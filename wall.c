/* wall.c */
#include <ncurses.h>
#include "wall.h"
#include "constants.h"

static void _displayWall(Wall *w)
{
	unsigned int x, y;
	if (!w || !w->data) return;
	for (y = 0; y < w->height; y++)
	{
		for (x = 0; x < w->width; x++)
			mvaddch(w->data->y + y + VERTICAL_OFFSET, 
				w->data->x + x + HORIZONTAL_OFFSET,
				w->data->vis);
	}	
}

void displayWall(void *data)
{
	if (data)
		_displayWall((Wall*) data);
}

