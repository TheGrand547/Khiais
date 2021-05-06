/* wall.c */
#include <ncurses.h>
#include <stdlib.h>
#include "wall.h"
#include "constants.h"
#include "output.h"

static void _displayWall(Wall *w)
{
	uint x, y;
	Element e;
	if (!w) return;
	e.vis = w->data->vis;
	x = w->data->x + w->width;
	y = w->data->y + w->height;
	for (e.y = w->data->y; e.y < y; e.y++)
	{
		for (e.x = w->data->x; e.x < x; e.x++)
			display(&e);
			/*
			mvaddch(w->data->y + y + VERTICAL_OFFSET, 
				w->data->x + x + HORIZONTAL_OFFSET,
				w->data->vis);
			*/
	}	
}

void displayWall(Element *e)
{
	if (e && e->data && e->flags & WALL)
		_displayWall((Wall*) e->data);
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
