#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

#define FOREACH_NODE(current, list)                                         \
    for ((current) = (list)->head; current; current = current->next)

#define FOREACH_NODE_REVERSE(current, list)                                 \
    for ((current) = (list)->tail; current; current = current->prev)

#define INT_TO_VP(i) ((void*) ((intptr_t)(i)))
#define UINT_TO_VP(ui) ((void*) ((uintptr_t)(ui)))

typedef struct NodeList NODE;
typedef struct LinkedList LIST;
typedef int (*cmpfn_t)(const void *, const void *);
typedef int (*list_t)(void *);

struct NodeList {
        const void *data;
        NODE *prev, *next;
};

struct LinkedList {
        NODE *head, *tail;

        cmpfn_t cmpfn;
        list_t list_t;
        unsigned n_elements;
};

typedef enum { FORWARD, BACKWARD } Traverse_mode;

int Intcmp(const void *a, const void *b);
int Strcmp(const void *a, const void *b);

void list_init(LIST *, cmpfn_t cmpfn);

bool list_contains(LIST *, const void *data);

NODE *list_node(LIST *, const void *data);

void list_find_delete(LIST *, const void *data);

void list_put(LIST *, void *);

unsigned list_len(LIST *);

void list_dispose(LIST *);

void list_traverse(LIST *, Traverse_mode, void (*typefn)(void*));

#endif
