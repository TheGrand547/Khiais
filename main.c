/* Gaming */
#include <ncurses.h>
#include "debug.h"
#include "word.h"
#include "structs.h"
#include "output.h"

/* Should be put elsewhere */
#define WIDTH 10
#define HEIGHT 10
#define PLAYER_FLAGS A_BOLD

int setup();
int main(int argc, char **argv)
{
	Element e;	
	int i, j;
	char inp;	
	if (!setup())
		return -1;
	curs_set(0);
	e.vis = '?';

	do
	{
		clear();
		move(5, 0);	
		for (i = 0; i < HEIGHT; i++)
		{
			for (j = 0; j < WIDTH; j++)
				printw(" ~ ");
			printw("\n");
		}
		switch (inp)
		{
			case 'h':
				e.x--;
				break;
			case 'j':
				e.y++;
				break;
			case 'k':
				e.y--;
				break;
			case 'l':
				e.x++;
				break;
			default:
				break;
		}
		e.y %= HEIGHT;
		e.x %= WIDTH;
		attron(PLAYER_FLAGS);	
		display(&e);		
		attroff(PLAYER_FLAGS);
		refresh();
	} while ((inp = getch()) != 'q');
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
