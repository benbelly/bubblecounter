
CC=gcc
PILIBS=-L/usr/local/lib -lwiringPi
WARNINGS=-Wall -Wextra -Werror
CFLAGS=${PILIBS} ${WARNINGS} -g

bubble: bubble.c
	${CC} ${CFLAGS} -o bubble bubble.c

blink: blink.c
	${CC} ${CFLAGS} -o blink blink.c

clean:
	rm -f bubble blink core
