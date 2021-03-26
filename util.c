/* Util.c */
#include <stdlib.h>
#include "util.h"

Element clearElement()
{
	Element e;
	e.x = 0;
	e.y = 0;
	e.vis = '+';
	e.next = NULL;
	e.data = NULL;
	return e;	
}

Element *addElementTo(Element *e, int x, int y)
{
	Element *new;
	new = malloc(sizeof(Element));
	if (new)
	{
		*new = clearElement();
		new->x = x;
		new->y = y;
		new->flags |= DYNAMIC;
		if (e)
		{
			while (e->next != NULL) e = e->next;
			e->next = new;
		}
	}
	return new;
}

void freeDynamic(Element *e)
{
	Element *next;
	while (e)
	{
		if (e->flags | DYNAMIC)
		{
			next = e->next;
			free(e);
		}
		else
		{


		}
	}
}
