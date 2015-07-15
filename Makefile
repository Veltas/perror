# Copyright (C) 2015  Christopher Leonard
# See README first for copyright terms, full terms in COPYING

.PHONY: all clean install uninstall

CC = gcc
CFLAGS = -O2 -std=c99 -pedantic -Wall
prefix = /usr/local

all: bin/perror

bin:
	mkdir $@

bin/perror: main.c | bin
	$(CC) $(CFLAGS) -o$@ $^

clean:
	-rm -r bin/

uninstall:
	-rm $(prefix)/bin/perror

install: $(prefix)/bin/perror
	
$(prefix)/bin/perror: bin/perror
	install -t$(prefix)/bin $<
