/***
  This file (linkedlist) is part of Liblinkedlist

  Copyright 2013 Daniel Buch

  Liblinkedlist is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  Liblinkedlist is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with Liblinkedlist; If not, see <http://www.gnu.org/licenses/>.
***/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "linkedlist.h"

/**
 *   Compare functions
 **/

int IntCmp(const void *a, const void *b) {
        return VP_TO_INT(a) - VP_TO_INT(b);
}

int StrCmp(const void *a, const void *b) {
        return strcmp((char*)a, (char*)b);
}

/**
 *   Init List - Head tail node, Compare Function and set n_elements to 0
 **/

void
list_init(LIST *list, cmpfn_t cmpfn) {
        list->head = list->tail = NULL;
        list->cmpfn = cmpfn;
        list->n_elements = 0;
}

/*
   Put client data to new node
*/

void
list_put(LIST *list, void *data) {
        if (!list)
                return;

        NODE *new = (NODE *)calloc(1, sizeof(NODE));

        if (!new) {
                fprintf(stderr, "ERROR: Not enough memory for a Note!\n");
                exit(EXIT_FAILURE);
        }

        new->data = data; /* Transfer Client data to new node */

        if (list->tail) {
                list->tail->next = new; /* Put newly allocated node to tails next */
                new->prev = list->tail; /* Make new previous pointer point to List last */
                list->tail = new;       /* finally point new to list last */
        } else {
                list->head = new;
                list->tail = new;
        }
        list->n_elements++;
}

/*
   Returns the length of the list
*/

unsigned
list_len(LIST *list) {
        if (!list)
                return 0;

        return list->n_elements;
}

/*
   list_dispose function free's the list
*/


void
list_dispose(LIST *list) {
        if(!list)
                return;

        NODE *current, *next;
        for (current = list->head; current; current = next) {
                next = current->next;
                free(current);
        }
}

NODE *list_find_node(LIST *list, const void *data) {
        NODE *current;
        FOREACH_NODE(current, list) {
                if ((list->cmpfn(data,current->data)) == 0) {
                        return current;
                }
        }
        return NULL;
}

int list_node_delete(LIST *list, const void *data) {
        NODE *target = list_find_node(list, data);

        if (target == NULL)
                return -1;

        NODE *prev, *next;

        prev = target->prev;
        next = target->next;


        if (prev) {
                if (next) {
                        prev->next = next;
                        next->prev = prev;
                }
                else {
                        prev->next = NULL;
                        list->tail = prev;
                }
        }
        else {
                if (next) {
                        next->prev = NULL;
                        list->head = next;
                } else
                        list->head = list->tail = NULL;
        }

        free(target);
        list->n_elements--;
        return 1;
}

bool
list_contains(LIST *list, const void *data) {
        NODE *current;
        FOREACH_NODE(current, list) {
                if ((list->cmpfn(data,current->data)) == 0) {
                        return true;
                }
        }
        return false;
}

void
list_traverse(LIST *list, Traverse_mode mode, void (*typefn)(void*)) {
        NODE *current;
        switch (mode) {
                case FORWARD:
                        FOREACH_NODE(current, list)
                                typefn((void*) current->data);
                        break;
                case BACKWARD:
                        FOREACH_NODE_REVERSE(current, list)
                                typefn((void*) current->data);
                        break;
        }
}
