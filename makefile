# TheGrand547 makefile
CC=gcc
CFLAGS=-g
CPPFLAGS=-g -std=c99 -DCOMPILE_TIME=`date '+%s'` -pedantic -Wall -Wextra -Werror
LDLIBS=-lncurses
LDFLAGS=-g
SRC=$(wildcard *.c)
DEP=$(SRC:.c=.o)

all: main tags

main: main.o $(DEP) 
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(DEP) main ./.depend

tags: *.c
	ctags -R .

depend: .depend

.depend: $(SRC)
	$(CC) -MM $^ > ./.depend

include .depend
