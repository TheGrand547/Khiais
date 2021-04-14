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
	unsigned int height, width, rheight, rwidth;
	Linked *rooms;
} Room;

#endif
