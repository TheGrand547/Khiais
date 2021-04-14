/* LinkedList.h TheGrand547 */
#ifndef LINKED_H
#define LINKED_H
typedef struct _node {
	struct _node *prev, *next;
	void *data;
} Node;

typedef struct _linked {
	int size;
	Node *head, *tail;	
} Linked;

typedef void (*Func)(void*);

void iterate(Linked *l, Func func);
void insert(Linked *l, void *data);

#endif
