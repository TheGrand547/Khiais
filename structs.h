/* Structs */
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Element {
	char vis;
	void *data;
	unsigned int x, y, flags;
	struct Element *next;
} Element;

#endif
