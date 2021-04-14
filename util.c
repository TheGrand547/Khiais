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


Element *addElementTo(Linked *l, int x, int y)
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

