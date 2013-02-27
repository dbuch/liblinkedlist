#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define FOREACH_NODE(current, list)                                         \
    for (NODE *(current) = (list)->first; current; current = current->next)

#define FOREACH_NODE_REVERSE(current, list)                                 \
    for (NODE *(current) = (list)->last; current; current = current->prev)

typedef struct NODELIST NODE;
typedef struct LinkedLIST LIST;

struct NODELIST {
    const void *data;
    NODE *prev;
    NODE *next;
};

struct LinkedLIST {
    NODE *first;
    NODE *last;
};

void list_init(LIST *list);

void list_push(LIST *list, void *data);

void list_free(LIST *list);

void print_chars (void *data);

void list_traverse(LIST *list, void (*typefn)(void*));

void list_traverse_reverse(LIST *list, void (*typefn)(void*));

#endif
