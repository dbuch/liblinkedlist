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
#include <getopt.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "linkedlist.h"
static void seperator (void) {
        printf("\n=============================\n");

}
static void print_chars (void *data) {
        printf("%s ", VP_TO_CHAR(data));
}

static void print_ints(void *data) {
        printf("%d ", VP_TO_INT(data));
}

static void list_with_ints(void) {
        LIST *ints = list_init(IntCmp);

        /* Put 10 random ints into "LIST ints" */
        printf("Push 10 random int elements to list\n");
        srand(time(NULL));
        for (int i = 0; i <= 10; i++)
                list_put(ints, INT_TO_VP(rand() % 300));

        list_traverse(ints, FORWARD, print_ints);
        seperator();
        printf("Sorting data..\n");
        list_sort_data(ints);
        list_traverse(ints, FORWARD, print_ints);

        /* Print list again forward and list lenght */
        printf("\nLenght of \"ints\" %d\n", list_len(ints));

        /* Free list, and return to main */
        list_dispose(ints);
}

static void list_with_chars(void) {
        LIST *chars = list_init(StrCmp);

        const char *string[] = { "This", "List", "owns!", ".. allmost!", NULL };

        for (const char **l = string ; l && *l; l++) {
                list_put(chars, (void*) *l);
        }

        list_delete_node(chars, ".. allmost!");

        list_traverse(chars, FORWARD, print_chars);
        printf("\nLenght of \"chars\"  %d\n", list_len(chars));
        list_dispose(chars);
}

static void list_with_strdup(void) {
        LIST *chars = list_init(StrCmp);

        char *string_one = strdup("Hello");
        char *string_two = strdup("World");

        list_put(chars, CHAR_TO_VP(string_one));
        list_put(chars, CHAR_TO_VP(string_two));

        list_traverse(chars, FORWARD, print_chars);
        printf("\n");

        list_dispose_data(chars);
}

static int help(void) {

        printf("[OPTIONS... {COMMAND ...\n\n"
               "   -h --help            Show this help\n"
               "   -v --version         Show package version\n");

        return 0;
}

static int parse_argv(int argc, char *argv[]) {
        static const struct option options[] = {
                { "help",          no_argument,    NULL, 'h'       },
                { "version",       no_argument,    NULL, 'v'       },
                { NULL,            0,              NULL, 0         }
        };
        assert(argc >= 0);
        assert(argv);

        int c;
        while ((c = getopt_long(argc, argv, "+hv", options, NULL)) >= 0) {
                switch (c) {
                        case 'h':
                                help();
                                return 0;
                        case 'v':
                                printf("this is beta version 0.01\n");
                                return 0;
                        default:
                                return -1;
                }
        }
        return 1;
}

int main(int argc, char *argv[]) {
        int r = parse_argv(argc, argv);

        if (r <= 0)
                goto finish;


        list_with_ints();
        seperator();
        list_with_chars();
        seperator();
        list_with_strdup();

finish:

        return r < 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
