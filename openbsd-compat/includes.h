/*
 * Copyright (c) 2012 Reyk Floeter <reyk@openbsd.org>
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

/* based on includes.h from OpenSSH:
 *
 * $OpenBSD: includes.h,v 1.54 2006/07/22 20:48:23 stevesk Exp $
 *
 * Author: Tatu Ylonen <ylo@cs.hut.fi>
 * Copyright (c) 1995 Tatu Ylonen <ylo@cs.hut.fi>, Espoo, Finland
 *                    All rights reserved
 * This file includes most of the needed system headers.
 *
 * As far as I am concerned, the code I have written for this software
 * can be used freely for any purpose.  Any derived versions of this
 * software must be clearly marked as such, and if the derived work is
 * incompatible with the protocol description in the RFC file, it must be
 * called by a name other than "ssh" or "Secure Shell".
 */

#ifndef INCLUDES_H
#define INCLUDES_H

#include "config.h"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE /* activate extra prototypes for glibc */
#endif

#include <sys/types.h>
#include <sys/socket.h> /* For CMSG_* */

#ifdef HAVE_LIMITS_H
# include <limits.h> /* For PATH_MAX */
#endif

#ifdef HAVE_BSTRING_H
# include <bstring.h>
#endif

#ifdef HAVE_ASM_BYTEORDER_H
# include <asm/byteorder.h>
#endif

#if defined(HAVE_ENDIAN_H)
# include <endian.h>
#elif defined(HAVE_SYS_ENDIAN_H)
# include <sys/endian.h>
#endif

#ifdef HAVE_PATHS_H
# include <paths.h>
#endif

/*
 *-*-nto-qnx needs these headers for strcasecmp and LASTLOG_FILE respectively
 */
#ifdef HAVE_STRINGS_H
# include <strings.h>
#endif
#ifdef HAVE_LOGIN_H
# include <login.h>
#endif

#ifdef HAVE_RPC_TYPES_H
# include <rpc/types.h> /* For INADDR_LOOPBACK */
#endif
#ifdef USE_PAM
#if defined(HAVE_SECURITY_PAM_APPL_H)
# include <security/pam_appl.h>
#elif defined (HAVE_PAM_PAM_APPL_H)
# include <pam/pam_appl.h>
#endif
#endif
#include <errno.h>

#ifdef HAVE_ERR_H
#include <err.h>
#endif

#if defined (HAVE_NETINET_IN_H)
#include <netinet/in.h>
#endif

#if defined (HAVE_NETINET_UDP_H)
#include <netinet/udp.h>
#endif

#ifdef HAVE_NETDB_H
# include <netdb.h>
#endif

#if defined (HAVE_NETINET6_IPSEC_H)
#include <netinet6/ipsec.h>
#elif defined(HAVE_NETIPSEC_IPSEC_H)
#include <netipsec/ipsec.h>
#elif defined (HAVE_LINUX_IPSEC_H)
#include <linux/ipsec.h>
#endif

#if defined(HAVE_LIBKERN_OSBYTEORDER_H)
#include <libkern/OSByteOrder.h>
#endif

#ifdef HAVE_NET_PFKEYV2_H
#include <net/pfkeyv2.h>
#endif

#ifdef HAVE_LINUX_PFKEYV2_H
#include <linux/pfkeyv2.h>
#endif

#ifdef HAVE_SYS_SYSCTL_H
#include <sys/sysctl.h>
#endif

#include <openssl/opensslv.h> /* For OPENSSL_VERSION_NUMBER */

#include "defines.h"

#include "openbsd-compat.h"

#endif /* INCLUDES_H */
