CFLAGS=-g -O3 -Wall
CC=gcc

all: normal

normal:
	$(CC) $(CFLAGS) -o bspc-node-loop bspc-node-loop.c

clean:
	rm -f bspc-node-loop

install:
	cp bspc-node-loop /usr/bin

uninstall:
	rm /usr/bin/bspc-node-loop

