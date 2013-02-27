#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "linkedlist.h"

void
list_init(LIST *l) {
        l->first = l->last = NULL;
}

void
list_push(LIST *list, void *data) {
        NODE *new = (NODE *)calloc(1, sizeof(NODE));

        if (!new) {
                fprintf(stderr, "ERROR: Not enough memory for a Note!\n");
                exit(EXIT_FAILURE);
        }

        new->data = data;

        if (list->last) {
                list->last->next = new;
                new->prev = list->last;
                list->last = new;
        }
        else {
                list->first = new;
                list->last = new;
        }
}

void
list_free(LIST *list)
{
        NODE *next;
        for (NODE *curr = list->first; curr; curr = next) {
                next = curr->next;
                free(curr);
        }
}

void
print_chars (void *data) {
        printf("%s\n", (char*) data);
}

void
list_traverse(LIST *list, void (*typefn)(void*)) {
        FOREACH_NODE(current, list)
                typefn((void*) current->data);
}

void
list_traverse_reverse(LIST *list, void (*typefn)(void*)) {
        FOREACH_NODE_REVERSE(current, list)
                typefn((void*) current->data);
}
