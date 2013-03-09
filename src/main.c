/***
  This file (main.c) is part of Liblinkedlist

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
static void
print_chars (void *data) {
        printf("%s ", (char*) data);
}


static void
print_ints(void *data) {
        printf("%d ", (intptr_t) data);
}

int
main(void)
{
        LIST ints;
        LIST chars;

        list_init(&ints, Intcmp);
        list_init(&chars, Strcmp);

        for (intptr_t i = 0; i <= 10; i++) {
                list_put(&ints, INT_TO_VP(i));
        }

        list_traverse(&ints, FORWARD, print_ints);
        printf("\nLenght of \"ints\" %d\n", list_len(&ints));
        list_find_delete(&ints, INT_TO_VP(5));
        list_find_delete(&ints, INT_TO_VP(6));
        printf("\n");
        list_traverse(&ints, FORWARD, print_ints);

        list_put(&chars, "This");
        list_put(&chars, "list");
        list_put(&chars, "owns!");

        list_find_delete(&chars, "This");

        list_traverse(&chars, FORWARD, print_chars);

        printf("\nLenght of \"ints\" %d\n", list_len(&ints));
        printf("Lenght of \"chars\"  %d\n", list_len(&chars));

        list_dispose(&ints);
        list_dispose(&chars);

        return 0;
}
