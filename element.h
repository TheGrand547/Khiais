/* element.h */
#ifndef ELEMENT_H
#define ELEMENT_H
#include "linked.h"
#include "types.h"

typedef struct Element {
	char vis;
	void *data;
	uint x, y, flags;
} Element;

int collideElement(void *l, void *r);
Element clearElement();
Element *addElementTo(Linked *l, int y, int x);
Element *clearElementPointer();
Element *makeElement(uint x, uint y, uint flags, char vis, void *data);
#endif

