CFLAGS=-g -O3 -Wall
CC=gcc

all: normal

normal:
	$(CC) $(CFLAGS) -o disable-internal-keyboard disable-internal-keyboard.c

clean:
	rm -f disable-internal-keyboard

install:
	cp disable-internal-keyboard /usr/bin

uninstall:
	rm /usr/bin/disable-internal-keyboard

