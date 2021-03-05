# TheGrand547 makefile
CC=gcc
CFLAGS=-g
CPPFLAGS=-g -ansi -pedantic -Wall -Werror
LDLIBS=-lncurses
LDFLAGS=-g
DEPEND=word.o
SOURCE=*.c

all: main tags

main: main.o $(DEPEND) 
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

a.o: .c
	gcc $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o main

tags: *.c
	ctags -R .

depend: .depend

.depend: *.c
	rm -f .depend	
	$(CC) $(CPPFLAGS) -MM $^>>./.depend

include .depend
