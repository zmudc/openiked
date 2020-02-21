/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define if you have a getaddrinfo that fails for the all-zeros IPv6 address
   */
/* #undef AIX_GETNAMEINFO_HACK */

/* Define if your resolver libs need this for getrrsetbyname */
/* #undef BIND_8_COMPAT */

/* Define if cmsg_type is not passed correctly */
/* #undef BROKEN_CMSG_TYPE */

/* getaddrinfo is broken (if present) */
/* #undef BROKEN_GETADDRINFO */

/* OS X glob does not do what we expect */
/* #undef BROKEN_GLOB */

/* Uses pre-standard HMAC-SHA2-256 truncation */
/* #undef BROKEN_HMAC_SHA2_256 */

/* Define if you have a broken realpath. */
/* #undef BROKEN_REALPATH */

/* Define if your setregid() is broken */
/* #undef BROKEN_SETREGID */

/* Define if your setresgid() is broken */
/* #undef BROKEN_SETRESGID */

/* Define if your setresuid() is broken */
/* #undef BROKEN_SETRESUID */

/* Define if your setreuid() is broken */
/* #undef BROKEN_SETREUID */

/* Define if your snprintf is busted */
/* #undef BROKEN_SNPRINTF */

/* Define if you have BSD auth support */
/* #undef BSD_AUTH */

/* fsid_t has member val */
/* #undef FSID_HAS_VAL */

/* fsid_t has member __val */
/* #undef FSID_HAS___VAL */

/* Define if your system uses access rights style file descriptor passing */
/* #undef HAVE_ACCRIGHTS_IN_MSGHDR */

/* Use Apple's NAT-T support */
/* #undef HAVE_APPLE_NATT */

/* Define to 1 if you have the `arc4random' function. */
#define HAVE_ARC4RANDOM 1

/* Define to 1 if you have the `arc4random_buf' function. */
#define HAVE_ARC4RANDOM_BUF 1

/* Define to 1 if you have the `arc4random_uniform' function. */
#define HAVE_ARC4RANDOM_UNIFORM 1

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <asm/byteorder.h> header file. */
/* #undef HAVE_ASM_BYTEORDER_H */

/* Define to 1 if you have the `asprintf' function. */
#define HAVE_ASPRINTF 1

/* Have attribute nonnull */
#define HAVE_ATTRIBUTE__NONNULL__ 1

/* Define if you have the basename function. */
#define HAVE_BASENAME 1

/* Define to 1 if you have the `bcopy' function. */
#define HAVE_BCOPY 1

/* Define to 1 if you have the `chflags' function. */
#define HAVE_CHFLAGS 1

/* Define if your libraries define clock_gettime() */
#define HAVE_CLOCK_GETTIME 1

/* define if you have clock_t data type */
#define HAVE_CLOCK_T 1

/* Define to 1 if you have the `closefrom' function. */
#define HAVE_CLOSEFROM 1

/* Define if gai_strerror() returns const char * */
#define HAVE_CONST_GAI_STRERROR_PROTO 1

/* Define if your system uses ancillary data style file descriptor passing */
#define HAVE_CONTROL_IN_MSGHDR 1

/* Define to 1 if you have the <ctype.h> header file. */
#define HAVE_CTYPE_H 1

/* Define if your libraries define daemon() */
#define HAVE_DAEMON 1

/* Define to 1 if you have the declaration of `O_NONBLOCK', and to 0 if you
   don't. */
#define HAVE_DECL_O_NONBLOCK 1

/* Define to 1 if you have the declaration of `writev', and to 0 if you don't.
   */
#define HAVE_DECL_WRITEV 1

/* System declares daemon as deprecated */
/* #undef HAVE_DEPRECATED_DAEMON */

/* Define to 1 if you have the <dirent.h> header file. */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the `dirfd' function. */
/* #undef HAVE_DIRFD */

/* Define to 1 if you have the `dirname' function. */
#define HAVE_DIRNAME 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <endian.h> header file. */
#define HAVE_ENDIAN_H 1

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <err.h> header file. */
#define HAVE_ERR_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `fgetln' function. */
#define HAVE_FGETLN 1

/* Define to 1 if the system has the type `float_t'. */
#define HAVE_FLOAT_T 1

/* Define to 1 if you have the `fmt_scaled' function. */
/* #undef HAVE_FMT_SCALED */

/* Define if your libraries define fparseln() */
#define HAVE_FPARSELN 1

/* Define to 1 if you have the `freeaddrinfo' function. */
#define HAVE_FREEADDRINFO 1

/* Define to 1 if the system has the type `fsblkcnt_t'. */
#define HAVE_FSBLKCNT_T 1

/* Define to 1 if the system has the type `fsfilcnt_t'. */
#define HAVE_FSFILCNT_T 1

/* Define to 1 if you have the `gai_strerror' function. */
#define HAVE_GAI_STRERROR 1

/* Define to 1 if you have the `getaddrinfo' function. */
#define HAVE_GETADDRINFO 1

/* Define to 1 if you have the `getnameinfo' function. */
#define HAVE_GETNAMEINFO 1

/* Define to 1 if you have the `getopt' function. */
#define HAVE_GETOPT 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define if your getopt(3) defines and uses optreset */
#define HAVE_GETOPT_OPTRESET 1

/* Define to 1 if you have the `getpeereid' function. */
#define HAVE_GETPEEREID 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* define if you have int64_t data type */
#define HAVE_INT64_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* define if you have intxx_t data type */
#define HAVE_INTXX_T 1

/* Define to 1 if the system has the type `in_addr_t'. */
#define HAVE_IN_ADDR_T 1

/* Define to 1 if the system has the type `in_port_t'. */
#define HAVE_IN_PORT_T 1

/* Define to 1 if you have the `crypt' library (-lcrypt). */
#define HAVE_LIBCRYPT 1

/* Define to 1 if you have the `dl' library (-ldl). */
/* #undef HAVE_LIBDL */

/* Define to 1 if you have the <libgen.h> header file. */
#define HAVE_LIBGEN_H 1

/* Define to 1 if you have the <libkern/OSByteOrder.h> header file. */
/* #undef HAVE_LIBKERN_OSBYTEORDER_H */

/* Define to 1 if you have the `pam' library (-lpam). */
/* #undef HAVE_LIBPAM */

/* Define to 1 if you have the <libutil.h> header file. */
/* #undef HAVE_LIBUTIL_H */

/* Define to 1 if you have the `z' library (-lz). */
#define HAVE_LIBZ 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <linux/in.h> header file. */
/* #undef HAVE_LINUX_IN_H */

/* Define to 1 if you have the <linux/ipsec.h> header file. */
/* #undef HAVE_LINUX_IPSEC_H */

/* Define to 1 if you have the <linux/pfkeyv2.h> header file. */
/* #undef HAVE_LINUX_PFKEYV2_H */

/* Define to 1 if you have the <login_cap.h> header file. */
#define HAVE_LOGIN_CAP_H 1

/* Define to 1 if the system has the type `long double'. */
#define HAVE_LONG_DOUBLE 1

/* Define to 1 if the system has the type `long long'. */
#define HAVE_LONG_LONG 1

/* Define to 1 if you have the <mach/mach_time.h> header file. */
/* #undef HAVE_MACH_MACH_TIME_H */

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* define if you have mode_t data type */
#define HAVE_MODE_T 1

/* Define to 1 if you have the <ndir.h> header file. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet6/ipsec.h> header file. */
#define HAVE_NETINET6_IPSEC_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <netinet/in_systm.h> header file. */
#define HAVE_NETINET_IN_SYSTM_H 1

/* Define to 1 if you have the <netinet/ip_ipsp.h> header file. */
/* #undef HAVE_NETINET_IP_IPSP_H */

/* Define to 1 if you have the <netinet/tcp.h> header file. */
#define HAVE_NETINET_TCP_H 1

/* Define to 1 if you have the <netinet/udp.h> header file. */
#define HAVE_NETINET_UDP_H 1

/* Define to 1 if you have the <netipsec/ipsec.h> header file. */
#define HAVE_NETIPSEC_IPSEC_H 1

/* Define to 1 if you have the <net/pfkeyv2.h> header file. */
#define HAVE_NET_PFKEYV2_H 1

/* Define if you have an old version of PAM which takes only one argument to
   pam_strerror */
/* #undef HAVE_OLD_PAM */

/* Define if your ssl headers are included with #include <openssl/header.h> */
#define HAVE_OPENSSL 1

/* Define to 1 if you have the `pam_getenvlist' function. */
/* #undef HAVE_PAM_GETENVLIST */

/* Define to 1 if you have the `pam_putenv' function. */
/* #undef HAVE_PAM_PUTENV */

/* define if you have pid_t data type */
#define HAVE_PID_T 1

/* Define if you have /proc/$pid/fd */
#define HAVE_PROC_PID 1

/* Define to 1 if you have the <pwd.h> header file. */
#define HAVE_PWD_H 1

/* Define if your password has a pw_change field */
#define HAVE_PW_CHANGE_IN_PASSWD 1

/* Define if your password has a pw_class field */
#define HAVE_PW_CLASS_IN_PASSWD 1

/* Define if your password has a pw_expire field */
#define HAVE_PW_EXPIRE_IN_PASSWD 1

/* define if you have sa_family_t data type */
#define HAVE_SA_FAMILY_T 1

/* Define to 1 if you have the `setproctitle' function. */
#define HAVE_SETPROCTITLE 1

/* Define to 1 if you have the `setregid' function. */
#define HAVE_SETREGID 1

/* Define to 1 if you have the `setresgid' function. */
/* #undef HAVE_SETRESGID */

/* Define to 1 if you have the `setresuid' function. */
/* #undef HAVE_SETRESUID */

/* Define to 1 if you have the `setreuid' function. */
#define HAVE_SETREUID 1

/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H 1

/* Define to 1 if the system has the type `sig_atomic_t'. */
#define HAVE_SIG_ATOMIC_T 1

/* define if you have size_t data type */
#define HAVE_SIZE_T 1

/* Have PEERCRED socket option */
/* #undef HAVE_SO_PEERCRED */

/* define if you have ssize_t data type */
#define HAVE_SSIZE_T 1

/* Fields in struct sockaddr_storage */
#define HAVE_SS_FAMILY_IN_SS 1

/* Define to 1 if you have the <stdarg.h> header file. */
#define HAVE_STDARG_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Silly mkstemp() */
/* #undef HAVE_STRICT_MKSTEMP */

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcat' function. */
#define HAVE_STRLCAT 1

/* Define to 1 if you have the `strlcpy' function. */
#define HAVE_STRLCPY 1

/* Define to 1 if you have the `strmode' function. */
#define HAVE_STRMODE 1

/* Define to 1 if you have the `strnvis' function. */
#define HAVE_STRNVIS 1

/* Define to 1 if you have the `strsep' function. */
#define HAVE_STRSEP 1

/* Define to 1 if you have the `strtonum' function. */
#define HAVE_STRTONUM 1

/* define if you have struct addrinfo data type */
#define HAVE_STRUCT_ADDRINFO 1

/* define if you have struct in6_addr data type */
#define HAVE_STRUCT_IN6_ADDR 1

/* define if you have struct sockaddr_in6 data type */
#define HAVE_STRUCT_SOCKADDR_IN6 1

/* Define to 1 if `sin6_len' is a member of `struct sockaddr_in6'. */
#define HAVE_STRUCT_SOCKADDR_IN6_SIN6_LEN 1

/* Define to 1 if `sin6_scope_id' is a member of `struct sockaddr_in6'. */
#define HAVE_STRUCT_SOCKADDR_IN6_SIN6_SCOPE_ID 1

/* Define to 1 if `sin_len' is a member of `struct sockaddr_in'. */
#define HAVE_STRUCT_SOCKADDR_IN_SIN_LEN 1

/* Define to 1 if `sa_len' is a member of `struct sockaddr'. */
#define HAVE_STRUCT_SOCKADDR_SA_LEN 1

/* define if you have struct sockaddr_storage data type */
#define HAVE_STRUCT_SOCKADDR_STORAGE 1

/* Define to 1 if `ss_len' is a member of `struct sockaddr_storage'. */
#define HAVE_STRUCT_SOCKADDR_STORAGE_SS_LEN 1

/* Define to 1 if `st_flags' is a member of `struct stat'. */
#define HAVE_STRUCT_STAT_ST_FLAGS 1

/* Define to 1 if `st_mtim' is a member of `struct stat'. */
#define HAVE_STRUCT_STAT_ST_MTIM 1

/* Define to 1 if `st_mtimespec' is a member of `struct stat'. */
#define HAVE_STRUCT_STAT_ST_MTIMESPEC 1

/* Define to 1 if the system has the type `struct timespec'. */
#define HAVE_STRUCT_TIMESPEC 1

/* define if you have struct timeval */
#define HAVE_STRUCT_TIMEVAL 1

/* Define to 1 if you have the `sysconf' function. */
#define HAVE_SYSCONF 1

/* Define to 1 if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H 1

/* Define to 1 if you have the <sys/cdefs.h> header file. */
#define HAVE_SYS_CDEFS_H 1

/* Define to 1 if you have the <sys/endian.h> header file. */
#define HAVE_SYS_ENDIAN_H 1

/* Define to 1 if you have the <sys/ndir.h> header file. */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/pstat.h> header file. */
/* #undef HAVE_SYS_PSTAT_H */

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/sysctl.h> header file. */
#define HAVE_SYS_SYSCTL_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/uio.h> header file. */
#define HAVE_SYS_UIO_H 1

/* Define to 1 if you have the <sys/un.h> header file. */
#define HAVE_SYS_UN_H 1

/* Define to 1 if you have the <sys/wait.h> header file. */
#define HAVE_SYS_WAIT_H 1

/* Define to 1 if you have the `time' function. */
#define HAVE_TIME 1

/* Define to 1 if you have the <ucred.h> header file. */
/* #undef HAVE_UCRED_H */

/* define if you have uintxx_t data type */
#define HAVE_UINTXX_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if the system has the type `unsigned long long'. */
#define HAVE_UNSIGNED_LONG_LONG 1

/* define if you have u_char data type */
#define HAVE_U_CHAR 1

/* define if you have u_int data type */
#define HAVE_U_INT 1

/* define if you have u_int64_t data type */
#define HAVE_U_INT64_T 1

/* define if you have u_intxx_t data type */
#define HAVE_U_INTXX_T 1

/* Define if va_copy exists */
#define HAVE_VA_COPY 1

/* Define to 1 if you have the <vis.h> header file. */
#define HAVE_VIS_H 1

/* Define to 1 if you have the `waitpid' function. */
#define HAVE_WAITPID 1

/* Define if compiler implements __FUNCTION__ */
#define HAVE___FUNCTION__ 1

/* Define if libc defines __progname */
#define HAVE___PROGNAME 1

/* Fields in struct sockaddr_storage */
/* #undef HAVE___SS_FAMILY_IN_SS */

/* Define if __va_copy exists */
#define HAVE___VA_COPY 1

/* Define if compiler implements __func__ */
#define HAVE___func__ 1

/* certificate path */
#define IKED_CA "/usr/local/etc/iked/"

/* configuration file path */
#define IKED_CONFIG "/usr/local/etc/iked.conf"

/* Specify location of iked.sock */
#define IKED_SOCKDIR "/var/run"

/* non-privileged user for privilege separation */
#define IKED_USER "_iked"

/* Define libevent major version */
#define LIBEVENT_MAJOR_VERSION 2

/* max value of long long calculated by configure */
/* #undef LLONG_MAX */

/* min value of long long calculated by configure */
/* #undef LLONG_MIN */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Define if you want OpenSSL's internally seeded PRNG only */
#define OPENSSL_PRNG_ONLY 1

/* Name of package */
#define PACKAGE "openiked-portable"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "Reyk Floeter <reyk@openbsd.org>"

/* Define to the full name of this package. */
#define PACKAGE_NAME "OpenIKED-portable"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "OpenIKED-portable 5.2-20200219150211"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "openiked-portable"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "5.2-20200219150211"

/* Path to OpenSSL binary */
#define PATH_OPENSSL "/usr/bin/openssl"

/* Path to TAR binary */
#define PATH_TAR "/bin/tar"

/* Path to ZIP binary */
/* #undef PATH_ZIP */

/* Root directory prefix */
#define PREFIX "NONE"

/* Port number of PRNGD/EGD random number socket */
/* #undef PRNGD_PORT */

/* Location of PRNGD/EGD random number socket */
/* #undef PRNGD_SOCKET */

/* Define if your platform breaks doing a seteuid before a setuid */
/* #undef SETEUID_BREAKS_SETUID */

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long int', as computed by sizeof. */
#define SIZEOF_LONG_INT 8

/* The size of `long long int', as computed by sizeof. */
#define SIZEOF_LONG_LONG_INT 8

/* The size of `short int', as computed by sizeof. */
#define SIZEOF_SHORT_INT 2

/* Define as const if snprintf() can declare const char *fmt */
#define SNPRINTF_CONST const

/* Define to a Set Process Title type if your system is supported by
   setproctitle.c */
/* #undef SPT_TYPE */

/* OpenSSL Configuration Directory */
#define SSLDIR "/usr/local/ssl"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define if you want to enable PAM support */
/* #undef USE_PAM */

/* Version number of package */
#define VERSION "5.2-20200219150211"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Enable GNU Extensions */
#define _GNU_SOURCE 1

/* Use RFC3542 IPv6 API */
/* #undef __APPLE_USE_RFC_3542 */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif
