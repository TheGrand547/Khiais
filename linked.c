/* linked.c TheGrand547 */
#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

void insert(Linked *l, void *data)
{
	Node *node, *new;
	if (l == NULL) return;
	
	node = l->head;

	while (node->next != NULL) node = node->next;
	new = malloc(sizeof(Node));
	if (new) 
	{
		l->size++;
		node->next = new;
		new->data = data;
		new->prev = node;
	}
}

void removeNode(Node *node)
{
	if (!node) return;	
	if (node->prev) node->prev->next = node->next;
	if (node->next) node->next->prev = node->prev;
	free(node);
}

