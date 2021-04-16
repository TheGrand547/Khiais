/* Util.c */
#include <stdlib.h>
#include "util.h"

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


Element *addElementTo(Linked *l, int y, int x)
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

int collideElement(void *l, void *r)
{
	int value = 0;
	Element *le, *re;
	if (l && r)
	{	
		le = (Element*) l;
		re = (Element*) r;
		value = (le->x == re->x) && (le->y == re->y);
	}
	return value;
}

