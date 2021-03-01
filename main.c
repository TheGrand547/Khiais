/* Gaming */
#include <ncurses.h>
#include "debug.h"

int setup();

int main()
{
	char a;
	if (!setup())
		return -1;	
	printw("This is in ncurses.\n");
	printw("\n\nEpic gamin\n");
	refresh();
	a = getch();

	attron(A_BLINK | A_BOLD);	
	printw("EPIC %c\n", a);
	attroff(A_BLINK | A_BOLD);
	refresh();
	
	getch();
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

