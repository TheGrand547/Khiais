/* wall.c */
#include <ncurses.h>
#include <stdlib.h>
#include "wall.h"
#include "constants.h"

static void _displayWall(Wall *w)
{
	unsigned int x, y;
	if (!w) return;
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

Wall *makeWall(uint x, uint y, uint w, uint h, char vis)
{	
	Wall *wall;
	if ((wall = malloc(sizeof(Wall))))
	{
		wall->width = w;
		wall->height = h;
		wall->data = makeElement(x, y, WALL, vis, wall); 
		if (!wall->data) 
		{
			free(wall);
			return NULL;
		}
	}
	return wall;
}

int collideWall(Element *non, Element *wall)
{
	int result = 0;
	Wall *w = (Wall*) wall->data;
	if (non && w)
	{
		result = (non->x >= wall->x && non->x < wall->x + w->width) && 
			(non->y >= wall->y && non->y < wall->y + w->height);
	}
	return result;
}
