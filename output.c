/* Output for trivial things */
#include <ncurses.h>
#include "output.h"
#include "structs.h"
#include "constants.h"
#include "wall.h" /* TODO: restructure */

static void _display(Element *e)
{
	if (e == NULL) return;
	if (e->flags & WALL)
		displayWall(e);
	else
		mvaddch(e->y + VERTICAL_OFFSET, e->x + HORIZONTAL_OFFSET, e->vis);
}

void display(void *data)
{
	_display((Element*) data);
}

void displayFlags(Element *e, int flags)
{
	attron(flags);
	display(e);
	attroff(flags);
}

void blankBoard()
{
	int i, j;
	for (i = 0; i < HEIGHT; i++)
	{
		move(i + VERTICAL_OFFSET, HORIZONTAL_OFFSET);
		for (j = 0; j < WIDTH; j++)
			printw("~");
	}
}

void emptyRectangle(unsigned int x, unsigned int y, 
			unsigned int width, unsigned int height, char display)
{
	int i, j;	
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
		{
			move(i + VERTICAL_OFFSET + y, j + HORIZONTAL_OFFSET + x);
			if (!i | !j | i == height - 1 | j == width - 1)
				addch(display);
		}
}

/* TODO: Make this not garbage */
void printHeader()
{
	printw("\t,,   ,,\n \
	||   ||     '   _    '\n \
	||/\\ ||/\\\\ \\\\  < \\, \\\\  _-_,\n\
	||_< || || ||  /-|| || ||_. \n\
	|| | || || || (( || ||  ~ ||\n\
	\\\\,\\ \\\\ |/ \\\\  \\/\\\\ \\\\ ,-_-  \n\
	       _/                  ");
}

