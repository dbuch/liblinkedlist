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

        /* Put ints 0 to 10 into "LIST ints" */
        for (int i = 0; i <= 10; i++)
                list_push_node(ints, INT_TO_VP(i));

        /* Print list forward and list lenght */
        list_traverse(ints, FORWARD, print_ints);
        printf("\nLenght of \"ints\" %d\n", list_len(ints));

        /* Delete two nodes */
        list_delete_node(ints, INT_TO_VP(6));
        list_delete_node(ints, INT_TO_VP(5));

        printf("Select random node and print data: %d\n", (list_random_node(ints))->data);

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

finish:

        return r < 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
