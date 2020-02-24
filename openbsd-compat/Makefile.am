noinst_LIBRARIES= libopenbsd-compat.a

libopenbsd_compat_a_SOURCES= \
		bsd-arc4random.c bsd-closefrom.c bsd-pledge.c \
		daemon.c entropy.c fgetln.c getopt.c imsg.c imsg-buffer.c \
		setresguid.c setproctitle.c \
		strlcat.c strlcpy.c strtonum.c vis.c explicit-bzero.c

EXTRA_DIST=	defines.h imsg.h includes.h chacha_private.h \
		openbsd-compat.h sys-queue.h sys-tree.h vis.h

CPPFLAGS=	-include $(top_srcdir)/openbsd-compat/includes.h \
		-I$(top_srcdir) -I$(top_srcdir)/openbsd-compat \
		@CPPFLAGS@ @DEFS@
