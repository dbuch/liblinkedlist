#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/*
   Init Head and tail note
*/

void
list_init(LIST *list) {
        list->first = list->last = NULL;
}

/*
   Push client data to node function
*/

void
list_push(LIST *list, void *data) {
        NODE *new = (NODE *)calloc(1, sizeof(NODE));

        if (!new) {
                fprintf(stderr, "ERROR: Not enough memory for a Note!\n");
                exit(EXIT_FAILURE);
        }

        new->data = data; /* Transfer Client data to new node */

        if (list->last) {
                list->last->next = new;
                new->prev = list->last;
                list->last = new;
        } else {
                list->first = new;
                list->last = new;
        }
}

/*
   Returns the length of the list
*/

unsigned
list_len(LIST *list)
{
        unsigned count = 0;
        FOREACH_NODE(current, list)
                count++;
        return count;
}


/*
   list_dispose function free's the list
*/


void
list_dispose(LIST *list)
{
        NODE *next;
        for (NODE *curr = list->first; curr; curr = next) {
                next = curr->next;
                free(curr);
        }
}

void
print_chars (void *data) {
        printf("%s ", (char*) data);
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
