/* LinkedList.h TheGrand547 */

typedef struct _node {
	struct _node *prev, *next;
	void *data;
} Node;


typedef struct _linked {
	int size;
	Node *head, *tail;	
} Linked;
