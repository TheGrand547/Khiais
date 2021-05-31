# TheGrand547 makefile
CC=gcc
CFLAGS=-g
CPPFLAGS=-g -std=c99 -pedantic -Wall -Wextra -Werror
LDLIBS=-lncurses
LDFLAGS=-g
SOURCE=$(wildcard *.c)
DEPEND=$(subst .c,.o,$(SOURCE))

all: main tags

main: main.o $(DEPEND) 
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f *.o main ./.depend

tags: *.c
	ctags -R .

depend: .depend

.depend: *.c
	rm -f .depend	
	$(CC) -MM $^ >> ./.depend

include .depend
