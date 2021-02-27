# TheGrand547 makefile
FLAGS=-ansi -pedantic -Wall -Werror
LIBS=-lncurses
DEPEND=test.o 

all: main

main: $(DEPEND) 
	gcc -g -o $@ $^ $(LIBS)


%.o: %.c
	gcc $(FLAGS) -g -c $< -o $@


