/* Structs */
#ifndef STRUCTS_H
#define STRUCTS_H
#include "linked.h"
#include "types.h"
#include "element.h"

enum FLAGS {
	WALL = 0x00000001 /* If it's a wall then data is a Wall* pointer */
};

typedef struct Room {
	uint x, y, height, width;
	Linked *walls;
	Linked *rooms;
} Room;

typedef struct Wall {
	uint width, height;
	Element *data;
	/* I'm missing something for doors but unsure what */
} Wall;

typedef struct Point {
	unsigned char x, y;
} Point;
#endif
