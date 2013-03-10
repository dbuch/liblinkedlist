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

#define FOREACH_NODE(current, list)                                         \
    for ((current) = (list)->head; current; current = current->next)

#define FOREACH_NODE_REVERSE(current, list)                                 \
    for ((current) = (list)->tail; current; current = current->prev)

#define INT_TO_VP(i) ((void*) ((intptr_t)(i)))
#define VP_TO_INT(i) ((int) ((intptr_t)(i)))

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

int IntCmp(const void *a, const void *b);
int StrCmp(const void *a, const void *b);

void list_init(LIST *, cmpfn_t cmpfn);

bool list_contains(LIST *, const void *data);

NODE *list_node(LIST *, const void *data);

int list_find_delete(LIST *, const void *data);

void list_put(LIST *, void *);

unsigned list_len(LIST *);

void list_dispose(LIST *);

void list_traverse(LIST *, Traverse_mode, void (*typefn)(void*));

#endif
