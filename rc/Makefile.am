# $Id: Makefile.in,v 1.28 2010/05/16 18:30:20 kamada Exp $

ACLOCAL_AMFLAGS = -I m4

install-exec-hook:
	$(INSTALL) -d $(DESTDIR)$(sysconfdir)/iked/rc.d
	$(INSTALL) -m 555 iked $(DESTDIR)$(sysconfdir)/iked/rc.d/iked
