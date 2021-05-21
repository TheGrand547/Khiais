/* Output for trivial things */
#include <ncurses.h>
#include <limits.h>
#include "output.h"
#include "structs.h"
#include "constants.h"
#include "wall.h" /* TODO: restructure */

static void makeValid(Element *e)
{
	if (e == NULL) return;
	if (e->x == UCHAR_MAX) e->x = 0;
	if (e->x >= WIDTH) e->x = WIDTH - 1;
	if (e->y == UCHAR_MAX) e->y = 0;
	if (e->y >= HEIGHT) e->y = HEIGHT - 1;
}

static void _display(Element *e)
{
	int x, y;
	if (e == NULL) return;
	makeValid(e);
	if (e->flags & WALL)
		displayWall(e);
	else
		for (y = 0; y < 2; y++)
			for (x = 0; x < 2; x++)
				mvaddch((e->y * 2 + y) + VERTICAL_OFFSET, 
					(e->x * 2 + x) + HORIZONTAL_OFFSET, e->vis[y][x]);
}

void display(void *data)
{
	_display((Element*) data);
}

void displayFlags(Element *e, int flags)
{
	uint old_flags;
	short color; 
	attr_get(&old_flags, &color, NULL);
	attroff(old_flags | color);
	attron(flags);
	_display(e);
	attroff(flags);
	attron(old_flags);
}

void drawBlank(void *ptr)
{
	Point *p = ptr;
	if (p) mvaddch(VERTICAL_OFFSET + p->y, HORIZONTAL_OFFSET + p->x, '!'); 
}

void emptyRectangle(uint8 x, uint8 y, 
			uint8 width, uint8 height, char display)
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

