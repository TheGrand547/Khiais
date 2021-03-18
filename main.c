/* Gaming */
#include <limits.h>
#include <ncurses.h>
#include "debug.h"
#include "word.h"
#include "structs.h"
#include "output.h"
#include "constants.h"

/* Should be put elsewhere */
#define PLAYER_FLAGS A_BOLD

void adjust(Element *e);
int setup();
int main(int argc, char **argv)
{
	Element e;	
	char inp = '\0';	
	if (!setup())
		return -1;
	curs_set(0);
	e.vis = '?';

	do
	{
		/* Buffer for status effects and such */
		printw("Welcome to epic gamin inc.\n");
		blankBoard();
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
		adjust(&e);
		attron(PLAYER_FLAGS);	
		display(&e);		
		attroff(PLAYER_FLAGS);
		refresh();
	} while ((inp = getch()) != 'q');
	endwin();
	return 0;
}

void adjust(Element *e)
{
	if (!e) return;
	if (e->x == UINT_MAX) e->x = WIDTH - 1;
	if (e->x == WIDTH) e->x = 0;
	if (e->y == UINT_MAX) e->y = HEIGHT - 1;
	if (e->y == HEIGHT) e->y = 0;
}

int setup()
{
	int value = 0;	
	if (initscr() != NULL)
		value = noecho() | cbreak();
	return !value;
}
