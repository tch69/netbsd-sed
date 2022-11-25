
CC ?= cc

SRCS =	compile.c err.c main.c misc.c process.c
OBJS =  ${SRCS:.c=.o}
MAN  =  sed.1

CFLAGS ?= -O3
CFLAGS += -Wall -I.
LDFLAGS +=

PREFIX ?= /usr/local
MANDIR ?= ${PREFIX}/share/man

.c.o:
	${CC} ${CFLAGS} -c $<

sed: ${OBJS}
	${CC} -o $@ ${OBJS} ${LDFLAGS}

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
