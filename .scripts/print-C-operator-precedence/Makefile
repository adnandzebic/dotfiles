CFLAGS=-g -O3 -Wall
CC=gcc

all: normal

normal:
	$(CC) $(CFLAGS) -o c-precedence c-precedence.c

clean:
	rm -f c-precedence

install:
	cp c-precedence /usr/bin

uninstall:
	rm /usr/bin/c-precedence

