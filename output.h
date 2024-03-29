/* Epic */
#ifndef OUTPUT_H
#define OUTPUT_H

#include "structs.h"

void drawBlank(void *ptr);
void printHeader();
void display(void *data);
void displayFlags(Element *e, uint flags);
void displayFlagsColorblind(Element *e, uint flags);
void blankBoard();
void displayElements(Element *e);
void emptyRectangle(uint8 x, uint8 y, uint8 width,
			uint8 height, char display);

#endif

