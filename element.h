/* element.h */
#ifndef ELEMENT_H
#define ELEMENT_H
#include "linked.h"
#include "types.h"

typedef struct Element {
	char vis[2][2]; 
	uint x, y, flags;
	void *data;
} Element;

int collideElement(void *l, void *r);
int collidePoint(Element *e, uint y, uint x);
Element clearElement();
Element *addElementTo(Linked *l, uint y, uint x);
Element *clearElementPointer();
Element *makeElement(uint x, uint y, uint flags, char vis, void *data);
void setVis(Element *e, char vis);
void copyVis(Element *src, Element *dst);
#endif

