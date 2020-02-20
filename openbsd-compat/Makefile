# $NetBSD: Makefile.in,v 1.35 2007/05/16 11:05:10 fukumoto Exp $

LIBISPRIVATE=yes

.include <bsd.init.mk>

#DBG=-g

CPPFLAGS+=	-include ../openbsd-compat/includes.h \
		-I../openbsd-compat

LIB=	openbsd-compat

SRCS= \
		bsd-arc4random.c bsd-closefrom.c bsd-pledge.c \
		daemon.c entropy.c fgetln.c getopt.c imsg.c imsg-buffer.c \
		setresguid.c setproctitle.c \
		strlcat.c strlcpy.c strtonum.c vis.c explicit-bzero.c

.include <bsd.lib.mk>
