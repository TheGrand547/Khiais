/* Structs */
#ifndef STRUCTS_H
#define STRUCTS_H

enum FLAGS {
	DYNAMIC = 0x00000001
};


typedef struct Element {
	char vis;
	void *data;
	unsigned int x, y, flags;
	struct Element *next;
} Element;


typedef struct Room {
	unsigned int height, width, rheight, rwidth;
	struct Element *bads;
	struct Room *subrooms;
} Room;

#endif
