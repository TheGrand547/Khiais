/* Structs */
#ifndef STRUCTS_H
#define STRUCTS_H
typedef enum {
	Standard, NonStandard
} Type;

typedef struct {
	char vis;
	void *data;
	int flags;
} Element;

typedef struct {
	Element **elements;
	Type type;
} Room;
#endif
