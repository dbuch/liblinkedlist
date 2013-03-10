/***
  This file (main) is part of Liblinkedlist

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
#include <stdint.h>

#include "linkedlist.h"
static void seperator (void) {
        printf("\n=============================\n");

}
static void print_chars (void *data) {
        printf("%s\n", VP_TO_CHAR(data));
}


static void print_ints(void *data) {
        printf("%d\n", VP_TO_INT(data));
}

static void list_with_ints(void) {
        LIST *ints = list_init(IntCmp);

        /* Put ints 0 to 10 into "LIST ints" */
        for (intptr_t i = 0; i <= 10; i++)
                list_push_node(ints, INT_TO_VP(i));

        /* Print list forward and list lenght */
        list_traverse(ints, FORWARD, print_ints);
        printf("\nLenght of \"ints\" %d\n", list_len(ints));

        /* Delete two nodes */
        list_delete_node(ints, INT_TO_VP(6));
        list_delete_node(ints, INT_TO_VP(5));

        seperator();
        printf("Remove node 5 and 6\n");
        /* Print list again forward and list lenght */
        list_traverse(ints, FORWARD, print_ints);
        printf("\nLenght of \"ints\" %d\n", list_len(ints));

        /* Free list, and return to main */
        list_dispose(ints);
}

static void list_with_chars(void) {
        LIST *chars = list_init(StrCmp);

        list_push_node(chars, "This");
        list_push_node(chars, "list");
        list_push_node(chars, "owns!");
        list_push_node(chars, ".. allmost!");

        list_delete_node(chars, ".. allmost!");

        list_traverse(chars, FORWARD, print_chars);
        printf("\nLenght of \"chars\"  %d\n", list_len(chars));
        list_dispose(chars);
}

int main(void)
{
        list_with_ints();
        seperator();
        list_with_chars();

        return 0;
}
