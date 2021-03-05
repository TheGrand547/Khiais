/* Gaming */
#include <ncurses.h>
#include "debug.h"
#include "word.h"
#include "structs.h"

int setup();
int main(int argc, char **argv)
{
	char a;
	int i, j;
	if (!setup())
		return -1;
	curs_set(0);
	printw("This is in ncurses.\n");
	printw("\n\nEpic gamin\n");
	refresh();
	getword(NULL);
	while ((a = getch()) != 'q')
	{
		clear();
		move(5, 0);	
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
				printw(" ? ");
			printw("\n");
		}	
		attron(A_BLINK | A_BOLD);	
		mvaddch(10, 1 + 5 * 3, a);	
		attroff(A_BLINK | A_BOLD);
		mvprintw(30, 10,"\n");	
		refresh();
	}	
	endwin();
	return 0;
}

int setup()
{
	int value = 0;	
	if (initscr() != NULL)
		value = noecho() | cbreak();
	return !value;
}

