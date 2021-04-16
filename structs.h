/* Structs */
#ifndef STRUCTS_H
#define STRUCTS_H
#include "linked.h"

enum FLAGS {
	DYNAMIC = 0x00000001
};


typedef struct Element {
	char vis;
	void *data;
	unsigned int x, y, flags;
} Element;


typedef struct Room {
	unsigned int x, y, height, width;
	Linked *walls;
	Linked *rooms;
} Room;

typedef struct Wall {
	unsigned int width, height;
	Element *data;
	/* I'm missing something for doors but unsure what */
} Wall;

#endif
