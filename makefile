# TheGrand547 makefile
FLAGS=-ansi -pedantic -Wall -Werror
LIBS=-lncurses
DEPEND= 

all: main

main: main.o $(DEPEND) 
	gcc -g -o $@ $^ $(LIBS)


%.o: %.c
	gcc $(FLAGS) -g -c $< -o $@

clean:
	rm -rf *.o

