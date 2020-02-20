# $OpenBSD: Makefile,v 1.7 2016/09/11 14:31:02 natano Exp $

.PATH:		${.CURDIR}/../iked

PROG=		ikectl
SRCS=		log.c ikeca.c ikectl.c parser.c util.c

MAN=		ikectl.8

LDADD=		-lutil -lcrypto
DPADD=		${LIBUTIL} ${LIBCRYPTO}
LDADD+=		-L../openbsd-compat -lopenbsd-compat
DPADD+=		../openbsd-compat/libopenbsd-compat.a
CFLAGS+=	-Wall -I${.CURDIR} -I${.CURDIR}/../iked
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes
CFLAGS+=	-Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith -Wcast-qual
CFLAGS+=	-Wsign-compare
CPPFLAGS=	-include ../openbsd-compat/includes.h \
		-I../openbsd-compat
NOGCCERROR=	yes

distribution:
	${INSTALL} -C -o root -g wheel -m 0644 ${.CURDIR}/ikeca.cnf \
	    ${DESTDIR}/etc/ssl/ikeca.cnf

.include <bsd.prog.mk>
