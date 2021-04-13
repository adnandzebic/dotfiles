CFLAGS=-g -O3 -Wall
CC=gcc

all: normal

normal:
	$(CC) $(CFLAGS) -o bright bright.c
	$(CC) $(CFLAGS) -o dark dark.c

clean:
	rm -f bright
	rm -f dark

install:
	cp bright /usr/bin
	cp dark /usr/bin

uninstall:
	rm /usr/bin/bright
	rm /usr/bin/dark

