# TheGrand547 makefile
CC=gcc
CFLAGS=-g
CPPFLAGS=-g -ansi -pedantic -Wall -Werror
LDLIBS=-lncurses
LDFLAGS=-g
DEPEND=word.o output.o
SOURCE=*.c

all: main tags

main: main.o $(DEPEND) 
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

a.o: .c
	gcc $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o main ./.depend

tags: *.c
	ctags -R .

depend: .depend

.depend: *.c
	rm -f .depend	
	$(CC) -MM $^ >> ./.depend

include .depend
