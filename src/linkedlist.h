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
#include <inttypes.h>

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

#define CONST_CHAR_TO_VP(c)  ((void*) ((const char*)(c)))
#define VP_TO_CONST_CHAR(c)  ((const char*) ((void*)(c)))

/**
 **   Swap NODES helper-macro for e.g. sorting algorithm
 **/

#define SWAP(a, b)                                                    \
        do { __typeof__ (a) temp = (a); (a) = (b); (b) = temp; } while(0);

/**
 **   macros for malloc and calloc
 **/

#define new(t, n) ((t*) malloc((n) * sizeof(t)))
#define new0(t, n) ((t*) calloc((n), sizeof(t)))

/**
 **   Typedefs
 **/

typedef struct NodeList NODE;
typedef struct LinkedList LIST;
typedef int (*cmpfn_t)(const void *, const void *);
typedef enum { FORWARD, BACKWARD } Traverse_mode;

/**
 **   Node and List struct
 **/

struct NodeList {
        void *data;
        NODE *prev, *next;
};

struct LinkedList {
        NODE *head, *tail;

        cmpfn_t cmpfn;
        unsigned n_elements;
};

/**
 **   Function Prototypes
 **/

extern int IntCmp(const void *a, const void *b);
extern int StrCmp(const void *a, const void *b);
extern LIST *list_init(cmpfn_t cmpfn);
extern bool list_contains(LIST *list, const void *data);
extern void list_put(LIST *list, void *data);
extern NODE *list_get(LIST *list, const void *data);
extern NODE *list_get_random(LIST *list);
extern NODE *list_get_median(LIST *list);
extern void list_qsort(LIST *list);
extern int list_delete_node(LIST *list, const void *data);
extern unsigned list_len(LIST *list);
extern void list_dispose(LIST *list);
extern void list_dispose_clear(LIST *list);
extern void list_traverse(LIST *list, Traverse_mode, void (*typefn)(void*));

#endif /* end of include guard: LINKEDLIST_H */
