/* element.c */
#include <stdlib.h>
#include "wall.h"
#include "element.h"

Element clearElement()
{
	Element e;
	e.x = 0;
	e.y = 0;
	e.flags = 0;
	setVis(&e, '+');
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


Element *addElementTo(Linked *l, uint8 y, uint8 x)
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

Element *makeElement(uint8 x, uint8 y, uint8 flags, char vis, void *data)
{
	Element *e;
	if ((e = clearElementPointer()))
	{
		e->x = x;
		e->y = y;
		e->flags = flags;
		setVis(e, vis);	
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

int collidePoint(Element *e, uint8 x, uint8 y)
{
	int result = 0;
	if (e) result = (e->x == x) && (e->y == y);
	return result;
}

void setVis(Element *e, char vis)
{
	if (!e) return;
	e->vis[0][0] = vis;
	e->vis[0][1] = vis;
	e->vis[1][0] = vis;
	e->vis[1][1] = vis;
}

void copyVis(Element *src, Element *dst)
{
	if (!src || !dst) return;
	dst->vis[0][0] = src->vis[0][0];
	dst->vis[0][1] = src->vis[0][1];
	dst->vis[1][0] = src->vis[1][0];
	dst->vis[1][1] = src->vis[1][1];
}

