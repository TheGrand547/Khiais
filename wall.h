/* wall.h */
#ifndef WALL_H
#define WALL_H
#include "structs.h"

void displayWall(void *data);
Wall *makeWall(uint x, uint y, uint w, uint h, char vis);

#endif
