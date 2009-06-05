# surf - simple browser
# See LICENSE file for copyright and license details.

include config.mk

SRC = surf.c tabbed.c
OBJ = ${SRC:.c=.o}

all: options surf tabbed

options:
	@echo surf build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

surf: surf.o
	@echo CC -o $@
	@${CC} -o $@ surf.o ${LDFLAGS}

tabbed: tabbed.o

clean:
	@echo cleaning
	@rm -f surf ${OBJ} surf-${VERSION}.tar.gz

dist: clean
	@echo creating dist tarball
	@mkdir -p surf-${VERSION}
	@cp -R LICENSE Makefile README config.def.h config.mk \
		surf.1 ${SRC} surf-${VERSION}
	@tar -cf surf-${VERSION}.tar surf-${VERSION}
	@gzip surf-${VERSION}.tar
	@rm -rf surf-${VERSION}

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f surf ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/surf
	@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@sed "s/VERSION/${VERSION}/g" < surf.1 > ${DESTDIR}${MANPREFIX}/man1/surf.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/surf.1

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/surf
	@echo removing manual page from ${DESTDIR}${MANPREFIX}/man1
	@rm -f ${DESTDIR}${MANPREFIX}/man1/surf.1

.PHONY: all options clean dist install uninstall
