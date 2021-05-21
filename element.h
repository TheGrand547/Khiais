/* element.h */
#ifndef ELEMENT_H
#define ELEMENT_H
#include "linked.h"
#include "types.h"

typedef struct Element {
	char vis[2][2]; 
	uint8 x, y, flags;
	void *data;
} Element;

int collideElement(void *l, void *r);
int collidePoint(Element *e, uint8 y, uint8 x);
Element clearElement();
Element *addElementTo(Linked *l, uint8 y, uint8 x);
Element *clearElementPointer();
Element *makeElement(uint8 x, uint8 y, uint8 flags, char vis, void *data);
void setVis(Element *e, char vis);
void copyVis(Element *src, Element *dst);
#endif

