.PHONY: all clean install uninstall

CC = gcc
CFLAGS = -std=c99 -pedantic -Wall
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
