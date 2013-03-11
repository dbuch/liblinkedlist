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

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

/**
 **   Traverse thru declared list
 **/

#define FOREACH_NODE(current, list)                                         \
    for ((current) = (list)->head; current; current = current->next)

#define FOREACH_NODE_REVERSE(current, list)                                 \
    for ((current) = (list)->tail; current; current = current->prev)

/**
 **   Type Casts
 **/

#define INT_TO_VP(i)   ((void*) ((intptr_t)(i)))
#define VP_TO_INT(i)   ((int) ((intptr_t)(i)))

#define UINT_TO_VP(ui) ((void*) ((uintptr_t)(ui)))
#define VP_TO_UINT(ui) ((unsigned) ((uintptr_t)(ui)))

#define CHAR_TO_VP(c)  ((void*) ((char*)(c)))
#define VP_TO_CHAR(c)  ((char*) ((void*)(c)))

/**
 **   Typedefs
 **/

typedef struct NodeList NODE;
typedef struct LinkedList LIST;
typedef int (*cmpfn_t)(const void *, const void *);
typedef int (*list_t)(void *);
typedef enum { FORWARD, BACKWARD } Traverse_mode;

/**
 **   Node and List struct
 **/

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

/**
 **   Function Prototypes
 **/

int IntCmp(const void *a, const void *b);
int StrCmp(const void *a, const void *b);

LIST *list_init(cmpfn_t cmpfn);

bool list_contains(LIST *list, const void *data);

NODE *list_find_node(LIST *list, const void *data);

NODE *list_random_node(LIST *list);

void list_qsort(LIST *list);

int list_delete_node(LIST *list, const void *data);

void list_push_node(LIST *list, void *data);

unsigned list_len(LIST *list);

void list_dispose(LIST *list);

void list_traverse(LIST *list, Traverse_mode, void (*typefn)(void*));

#endif /* end of include guard: LINKEDLIST_H */
