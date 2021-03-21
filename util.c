/* Util.c */
#include <stdlib.h>
#include "util.h"

Element clearElement()
{
	Element e;
	e.x = 0;
	e.y = 0;
	e.vis = '?';
	e.next = NULL;
	e.data = NULL;
	return e;	
}
