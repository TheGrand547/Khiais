/* element.c */
#include <stdlib.h>
#include "wall.h"
#include "element.h"

Element clearElement()
{
	Element e;
	e.x = 0;
	e.y = 0;
	e.vis = '+';
	e.data = NULL;
	return e;	
}

Element *clearElementPointer()
{
	Element *e;
	e = malloc(sizeof(Element));
	if (e) *e = clearElement();
	return e;
}


Element *addElementTo(Linked *l, uint y, uint x)
{
	Element *new = clearElementPointer();
	if (new)
	{
		insert(l, new);
		new->x = x;
		new->y = y;
	}
	return new;
}

Element *makeElement(uint x, uint y, uint flags, char vis, void *data)
{
	Element *e;
	if ((e = clearElementPointer()))
	{
		e->x = x;
		e->y = y;
		e->flags = flags;
		e->vis = vis;
		e->data = data;
	}
	return e;
}

int collideElement(void *l, void *r)
{
	int value = 0;
	Element *le = l, *re = r;
	if (l && r)
	{
		value = (le->x == re->x) && (le->y == re->y);
		if (re->flags & WALL) value = collideWall(le, re);
	}
	return value;
}

int collidePoint(Element *e, uint x, uint y)
{
	int result = 0;
	if (e) result = (e->x == x) && (e->y == y);
	return result;
}

