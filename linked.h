/* LinkedList.h TheGrand547 */
#ifndef LINKED_H
#define LINKED_H

#define INSERT(l, data) insertStruct(l, &data, sizeof(data))

typedef struct _node Node;

typedef struct _linked Linked;

typedef void (*Func)(void*);
typedef int (*BoolFunc)(void*, void*);

void iterate(Linked *l, Func func);
void insert(Linked *l, void *data);
void insertStruct(Linked *l, void *data, size_t size);
int boolIterate(Linked *l, void *data, BoolFunc func);
Linked *makeLinked();
#endif
