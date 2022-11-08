

CC ?= cc
STRIP ?= strip

SRCS =	compat.c compile.c main.c misc.c process.c
OBJS =  ${SRCS:.c=.o}
MAN  =  sed.1

CFLAGS += -g -g1 -O3 
LDFLAGS +=

PREFIX ?= /usr/local
BINDIR ?= ${PREFIX}/bin
MANDIR ?= ${PREFIX}/share/man

.c.o:
	${CC} -c ${CFLAGS} $<

sed: ${OBJS}
	${CC} -o $@ ${OBJS} ${LDFLAGS}
	${STRIP} --strip-unneeded $@

install: sed
	install -d ${BINDIR}
	install -d ${MANDIR}/man1
	install -m 755 sed ${BINDIR}/sed
	install -m 644 sed.1 ${MANDIR}/man1/sed.1

uninstall:
	rm -f ${BINDIR}/sed
	rm -f ${MANDIR}/man1/sed.1

clean: 
	rm -f sed ${OBJS}
