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
#include <time.h>
#include <assert.h>

#include "linkedlist.h"
#include "debug.h"

/**
 **   Compare functions
 **/

int UIntCmp(const void *a, const void *b) {
        return VP_TO_UINT(a) - VP_TO_UINT(b);
}

int IntCmp(const void *a, const void *b) {
        return VP_TO_INT(a) - VP_TO_INT(b);
}

int StrCmp(const void *a, const void *b) {
        return strcmp(VP_TO_CHAR(a), VP_TO_CHAR(b));
}

/**
 **   Init List - Head tail node, Compare Function and set n_elements to 0
 **/

LIST *list_init(cmpfn_t cmpfn) {
        assert(cmpfn);

        LIST *newlist = new(LIST, 1);
        assert(newlist);

        newlist->head = newlist->tail = NULL;
        newlist->cmpfn = cmpfn;
        newlist->n_elements = 0;
        return newlist;
}

/**
 **   Puts new node + client data to list
 **/

void list_put(LIST *list, void *data) {
        assert(list);

        NODE *new = new0(NODE, 1);
        assert(new);

        new->data = data; /* Transfer Client data to new node */

        if (list->tail) {
                list->tail->next = new; /* Tail next points to new node */
                new->prev = list->tail; /* New Node's previous points to tail */
                list->tail = new;       /* Tail points to new node */
        } else {                        /** In case list is empty, head and tail is now points to new node **/
                list->head = new;
                list->tail = new;
        }
        list->n_elements++;
}

/**
 **   Returns length of list
 **/

unsigned list_len(LIST *list) {
        assert(list);

        return list->n_elements;
}

void list_dispose_clear(LIST *list) {
        assert(list);

        NODE *current, *next;

        for (current = list->head; current; current = next) {
                next = current->next;
                free(current->data);
                free(current);
        }
        free(list);
}
/**
 **   list_dispose free's the list nodes
 **/

void list_dispose(LIST *list) {
        assert(list);

        NODE *current, *next;
        for (current = list->head; current; current = next) {
                next = current->next;
                free(current);
        }
        free(list);
}

/**
 **   Traverse list and returns node equal to client data
 **/

NODE *list_get(LIST *list, const void *data) {
        assert(list);

        NODE *current;
        FOREACH_NODE(current, list) {
                if ((list->cmpfn(data,current->data)) == 0) {
                        return current;
                }
        }
        return NULL;
}

/**
 **   list_node_delete uses list_find_node to delete node
 **/

int list_delete_node(LIST *list, const void *data) {
        assert(list);

        NODE *target = list_get(list, data);

        if (!target) {
                INFO("Target node not found");
                return -1;
        }

        NODE *prev = target->prev;
        NODE *next = target->next;

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
        return 0;
}

/**
 **   Traverse list and returns true if client data is found
 **/

bool list_contains(LIST *list, const void *data) {
        assert(list);

        NODE *current;
        FOREACH_NODE(current, list) {
                if ((list->cmpfn(data,current->data)) == 0) {
                        return true;
                }
        }
        return false;
}

/**
 **   Traverse list forward or backward
 **/

void list_traverse(LIST *list, Traverse_mode mode, void (*typefn)(void*)) {
        assert(list);

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

/**
 **   Returns random node from list
 **/

NODE *list_get_random(LIST *list) {
        assert(list);

        NODE *random = list->head;
        unsigned n = rand() % list_len(list);

        for (unsigned i = 0; i < n; i++) {
                random = random->next;
        }
        return random;
}

/**
 **   Returns median node from list (If list length is odd round down)
 **/

NODE *list_get_median(LIST *list) {
        if (!list) {
                INFO("Invalid list");
                return NULL;
        }
        NODE *median = list->head;
        unsigned n = list_len(list);

        if (n % 2 == 1)
                n = n / 2 - 1;
        else
                n = n / 2;

        for (unsigned i = 0; i < n; i++) {
                median = median->next;
        }

        return median;
}

/**
 **   Quick-sort NON-recursive implementation for the list data
 **/

void list_qsort(LIST *list) {
        assert(list);

        LIST less, greater;
        LIST *lessPtr = &less;
        LIST *greaterPtr = &greater;

        NODE *pivot = list_get_median(list);

        lessPtr->tail = pivot->prev;
        greaterPtr->head = pivot->next;

        NODE *current;
        FOREACH_NODE_REVERSE(current, lessPtr) {
        }

        FOREACH_NODE(current, greaterPtr) {
        }
}
