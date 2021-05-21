/* wall.h */
#ifndef WALL_H
#define WALL_H
#include "structs.h"

void displayWall(Element *e);
Wall *makeWall(uint8 x, uint8 y, uint8 w, uint8 h, char vis);
int collideWall(Element *wall, Element *non);
#endif
