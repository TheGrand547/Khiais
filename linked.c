/* linked.c TheGrand547 */
#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

struct _node {
	struct _node *prev, *next;
	void *data;
};

struct _linked {
	int size;
	Node *head, *tail;	
};


void iterate(Linked *l, Func func)
{
	Node *n;
	if (l == NULL) return;
	n = l->head;	
	do func(n->data);
	while ((n = n->next));
}

int boolIterate(Linked *l, void *data, BoolFunc func)
{
	int result = 0;
	Node* node;
	if (l)
	{	
		node = l->head;
		while (node && !(result = func(data, node->data)))
			node = node->next; 
	}
	return result;
}

void insert(Linked *l, void *data)
{
	Node *node, *new;
	if (l == NULL) return;
	
	node = l->head;

	if (node != NULL) 
		while (node->next != NULL) 
			node = node->next;

	new = calloc(1, sizeof(Node));
	if (new) 
	{
		l->size++;
		if (node == NULL) 
		{
			l->head = new;	
			l->tail = NULL;
		}
		else node->next = new;

		new->data = data;
		new->prev = node;
		l->tail = new;
	}
}

void removeNode(Linked *l, Node *node)
{
	if (!node) return;	
	if (node->prev) node->prev->next = node->next;
	if (node->next) node->next->prev = node->prev;
	free(node);
	l->size--;
}


Linked *makeLinked(){
	return (Linked*) calloc(1, sizeof(Linked));
}

