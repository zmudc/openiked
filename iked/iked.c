/*	$OpenBSD: iked.c,v 1.13 2012/10/22 10:25:17 reyk Exp $	*/
/*	$vantronix: iked.c,v 1.22 2010/06/02 14:43:30 reyk Exp $	*/

/*
 * Copyright (c) 2010 Reyk Floeter <reyk@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/param.h>
#include <sys/types.h>
#include "openbsd-compat/sys-queue.h"
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/uio.h>

#include <net/if.h>
#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#ifdef HAVE_DEPRECATED_DAEMON
/* Apple deprected daemon() and prints an warning that breaks -Werror */
#define daemon XXX_daemon
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <signal.h>
#include <errno.h>
#include <err.h>
#include <pwd.h>
#include <event.h>

#include "iked.h"
#include "ikev2.h"

#ifdef HAVE_DEPRECATED_DAEMON
#undef daemon
extern int daemon(int, int);
#endif

__dead void usage(void);

void	 parent_shutdown(struct iked *);
void	 parent_sig_handler(int, short, void *);
int	 parent_dispatch_ikev1(int, struct privsep_proc *, struct imsg *);
int	 parent_dispatch_ikev2(int, struct privsep_proc *, struct imsg *);
int	 parent_dispatch_ca(int, struct privsep_proc *, struct imsg *);
int	 parent_configure(struct iked *);

static struct privsep_proc procs[] = {
	{ "ikev1",	PROC_IKEV1, parent_dispatch_ikev1, ikev1 },
	{ "ikev2",	PROC_IKEV2, parent_dispatch_ikev2, ikev2 },
	{ "ca",		PROC_CERT, parent_dispatch_ca, caproc, IKED_CA }
};

#ifndef HAVE_SETPROCTITLE
/* Saved arguments to main(). */
char **saved_argv;
int saved_argc;
#endif

__dead void
usage(void)
{
	extern char	*__progname;

	fprintf(stderr, "usage: %s [-dnSTtv] [-D macro=value] "
	    "[-f file]\n", __progname);
	exit(1);
}

int
main(int argc, char *argv[])
{
	int		 c;
	int		 debug = 0, verbose = 0;
	int		 opts = 0;
	const char	*conffile = IKED_CONFIG;
	struct iked	*env = NULL;
	struct privsep	*ps;

	log_init(1);

#ifndef HAVE_SETPROCTITLE
	/* Save argv. Duplicate so setproctitle emulation doesn't clobber it */
	saved_argc = argc;
	saved_argv = calloc(argc + 1, sizeof(*saved_argv));
	if (saved_argv == NULL)
		fatal("calloc: argv");
	for (c = 0; c < argc; c++) {
		saved_argv[c] = strdup(argv[c]);
		if (saved_argv[c] == NULL)
			fatal("strdup: saved_argv[c]");
	}
	saved_argv[c] = NULL;

	/* Prepare for later setproctitle emulation */
	compat_init_setproctitle(argc, argv);
	argv = saved_argv;
#endif

	while ((c = getopt(argc, argv, "dD:nf:vSTt")) != -1) {
		switch (c) {
		case 'd':
			debug++;
			break;
		case 'D':
			if (cmdline_symset(optarg) < 0)
				log_warnx("could not parse macro definition %s",
				    optarg);
			break;
		case 'n':
			debug = 1;
			opts |= IKED_OPT_NOACTION;
			break;
		case 'f':
			conffile = optarg;
			break;
		case 'v':
			verbose++;
			opts |= IKED_OPT_VERBOSE;
			break;
		case 'S':
			opts |= IKED_OPT_PASSIVE;
			break;
		case 'T':
			opts |= IKED_OPT_NONATT;
			break;
		case 't':
			opts |= IKED_OPT_NATT;
			break;
		default:
			usage();
		}
	}

	argv += optind;
	argc -= optind;

	if ((env = calloc(1, sizeof(*env))) == NULL)
		fatal("calloc: env");

	env->sc_opts = opts;

	ps = &env->sc_ps;
	ps->ps_env = env;

	if ((opts & (IKED_OPT_NONATT|IKED_OPT_NATT)) ==
	    (IKED_OPT_NONATT|IKED_OPT_NATT))
		errx(1, "conflicting NAT-T options");

	if (strlcpy(env->sc_conffile, conffile, MAXPATHLEN) >= MAXPATHLEN)
		errx(1, "config file exceeds MAXPATHLEN");

	ca_sslinit();
	policy_init(env);

	/* check for root privileges */
	if (geteuid())
		errx(1, "need root privileges");

	if ((ps->ps_pw =  getpwnam(IKED_USER)) == NULL)
		errx(1, "unknown user %s", IKED_USER);

	/* Configure the control socket */
	ps->ps_csock.cs_name = IKED_SOCKET;

	log_init(debug);
	log_verbose(verbose);

	if (!debug && daemon(0, 0) == -1)
		err(1, "failed to daemonize");

	group_init();
	proc_init(ps, procs, nitems(procs));

	setproctitle("parent");

	event_init();

	signal_set(&ps->ps_evsigint, SIGINT, parent_sig_handler, ps);
	signal_set(&ps->ps_evsigterm, SIGTERM, parent_sig_handler, ps);
	signal_set(&ps->ps_evsigchld, SIGCHLD, parent_sig_handler, ps);
	signal_set(&ps->ps_evsighup, SIGHUP, parent_sig_handler, ps);
	signal_set(&ps->ps_evsigpipe, SIGPIPE, parent_sig_handler, ps);

	signal_add(&ps->ps_evsigint, NULL);
	signal_add(&ps->ps_evsigterm, NULL);
	signal_add(&ps->ps_evsigchld, NULL);
	signal_add(&ps->ps_evsighup, NULL);
	signal_add(&ps->ps_evsigpipe, NULL);

	proc_config(ps, procs, nitems(procs));

	if (parent_configure(env) == -1)
		fatalx("configuration failed");

	event_dispatch();

	log_debug("%d parent exiting", getpid());

	return (0);
}

int
parent_configure(struct iked *env)
{
	struct sockaddr_storage	 ss;
#if defined(HAVE_APPLE_NATT)
	int			 udpencap;
#endif

	if (parse_config(env->sc_conffile, env) == -1) {
		proc_kill(&env->sc_ps);
		exit(1);
	}

	if (env->sc_opts & IKED_OPT_NOACTION) {
		fprintf(stderr, "configuration OK\n");
		proc_kill(&env->sc_ps);
		exit(0);
	}

	env->sc_pfkey = -1;
	config_setpfkey(env, PROC_IKEV2);

	/* Now compile the policies and calculate skip steps */
	config_setcompile(env, PROC_IKEV1);
	config_setcompile(env, PROC_IKEV2);

	bzero(&ss, sizeof(ss));
	ss.ss_family = AF_INET;

#if defined(HAVE_APPLE_NATT)
	if ((env->sc_opts & IKED_OPT_NONATT) == 0) {
		udpencap = IKED_NATT_PORT;
		if (sysctlbyname("net.inet.ipsec.esp_port", NULL, NULL,
		    &udpencap, sizeof(udpencap)) != 0)
			fatalx("failed to set NAT-T port");
	}
#endif

	if ((env->sc_opts & IKED_OPT_NATT) == 0)
		config_setsocket(env, &ss, ntohs(IKED_IKE_PORT), PROC_IKEV2);
	if ((env->sc_opts & IKED_OPT_NONATT) == 0)
		config_setsocket(env, &ss, ntohs(IKED_NATT_PORT), PROC_IKEV2);

	bzero(&ss, sizeof(ss));
	ss.ss_family = AF_INET6;

	if ((env->sc_opts & IKED_OPT_NATT) == 0)
		config_setsocket(env, &ss, ntohs(IKED_IKE_PORT), PROC_IKEV2);
	if ((env->sc_opts & IKED_OPT_NONATT) == 0)
		config_setsocket(env, &ss, ntohs(IKED_NATT_PORT), PROC_IKEV2);

	config_setcoupled(env, env->sc_decoupled ? 0 : 1);
	config_setmode(env, env->sc_passive ? 1 : 0);

	return (0);
}

void
parent_reload(struct iked *env, int reset, const char *filename)
{
	/* Switch back to the default config file */
	if (filename == NULL || *filename == '\0')
		filename = env->sc_conffile;

	log_debug("%s: level %d config file %s", __func__, reset, filename);

	if (reset == RESET_RELOAD) {
		config_setreset(env, RESET_POLICY, PROC_IKEV1);
		config_setreset(env, RESET_POLICY, PROC_IKEV2);
		config_setreset(env, RESET_CA, PROC_CERT);

		if (parse_config(filename, env) == -1) {
			log_debug("%s: failed to load config file %s",
			    __func__, filename);
		}

		/* Re-compile policies and skip steps */
		config_setcompile(env, PROC_IKEV1);
		config_setcompile(env, PROC_IKEV2);

		config_setcoupled(env, env->sc_decoupled ? 0 : 1);
		config_setmode(env, env->sc_passive ? 1 : 0);
	} else {
		config_setreset(env, reset, PROC_IKEV1);
		config_setreset(env, reset, PROC_IKEV2);
		config_setreset(env, reset, PROC_CERT);
	}
}

void
parent_sig_handler(int sig, short event, void *arg)
{
	struct privsep	*ps = arg;
	int		 die = 0, status, fail, id;
	pid_t		 pid;
	char		*cause;

	switch (sig) {
	case SIGHUP:
		log_info("%s: reload requested with SIGHUP", __func__);

		/*
		 * This is safe because libevent uses async signal handlers
		 * that run in the event loop and not in signal context.
		 */
		parent_reload(ps->ps_env, 0, NULL);
		break;
	case SIGPIPE:
		log_info("%s: ignoring SIGPIPE", __func__);
		break;
	case SIGTERM:
	case SIGINT:
		die = 1;
		/* FALLTHROUGH */
	case SIGCHLD:
		do {
			pid = waitpid(-1, &status, WNOHANG);
			if (pid <= 0)
				continue;

			fail = 0;
			if (WIFSIGNALED(status)) {
				fail = 1;
				asprintf(&cause, "terminated; signal %d",
				    WTERMSIG(status));
			} else if (WIFEXITED(status)) {
				if (WEXITSTATUS(status) != 0) {
					fail = 1;
					asprintf(&cause, "exited abnormally");
				} else
					asprintf(&cause, "exited okay");
			} else
				fatalx("unexpected cause of SIGCHLD");

			die = 1;

			for (id = 0; id < PROC_MAX; id++)
				if (pid == ps->ps_pid[id]) {
					log_warnx("lost child: %s %s",
					    ps->ps_title[id], cause);
					break;
				}

			free(cause);
		} while (pid > 0 || (pid == -1 && errno == EINTR));

		if (die)
			parent_shutdown(ps->ps_env);
		break;
	default:
		fatalx("unexpected signal");
	}
}

int
parent_dispatch_ikev1(int fd, struct privsep_proc *p, struct imsg *imsg)
{
	switch (imsg->hdr.type) {
	default:
		break;
	}

	return (-1);
}

int
parent_dispatch_ikev2(int fd, struct privsep_proc *p, struct imsg *imsg)
{
	switch (imsg->hdr.type) {
	default:
		break;
	}

	return (-1);
}

int
parent_dispatch_ca(int fd, struct privsep_proc *p, struct imsg *imsg)
{
	struct iked	*env = p->p_ps->ps_env;
	int		 v;
	char		*str = NULL;
	u_int		 type = imsg->hdr.type;

	switch (type) {
	case IMSG_CTL_RESET:
		IMSG_SIZE_CHECK(imsg, &v);
		memcpy(&v, imsg->data, sizeof(v));
		parent_reload(env, v, NULL);
		break;
	case IMSG_CTL_COUPLE:
	case IMSG_CTL_DECOUPLE:
	case IMSG_CTL_ACTIVE:
	case IMSG_CTL_PASSIVE:
		proc_compose_imsg(env, PROC_IKEV1, type, -1, NULL, 0);
		proc_compose_imsg(env, PROC_IKEV2, type, -1, NULL, 0);
		break;
	case IMSG_CTL_RELOAD:
		if (IMSG_DATA_SIZE(imsg) > 0)
			str = get_string(imsg->data, IMSG_DATA_SIZE(imsg));
		parent_reload(env, 0, str);
		if (str != NULL)
			free(str);
		break;
	default:
		return (-1);
	}

	return (0);
}

void
parent_shutdown(struct iked *env)
{
	proc_kill(&env->sc_ps);

	free(env);

	log_warnx("parent terminating");
	exit(0);
}