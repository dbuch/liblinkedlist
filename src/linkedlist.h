#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define FOREACH_NODE(current, list)                                         \
    for (NODE *(current) = (list)->head; current; current = current->next)

#define FOREACH_NODE_REVERSE(current, list)                                 \
    for (NODE *(current) = (list)->tail; current; current = current->prev)

typedef struct NodeList NODE;
typedef struct LinkedList LIST;

struct NodeList {
        const void *data;
        NODE *prev;
        NODE *next;
};

struct LinkedList {
        NODE *head;
        NODE *tail;
};

enum Traverse_mode { FORWARD, REVERSE };

void list_init(LIST *);

void list_push(LIST *, void *);

unsigned list_len(LIST *);

void list_dispose(LIST *);

void print_chars (void *);

void list_traverse(LIST *, int Traverse_mode, void (*typefn)(void*));

#endif
