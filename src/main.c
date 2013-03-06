#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "linkedlist.h"

static void print_ints(void *data) {
        printf("%d ", (intptr_t) data);
}
int
main(void)
{
        LIST list_one;
        LIST list_two;

        list_init(&list_one);
        list_init(&list_two);

        for (intptr_t i = 0; i <= 10; i++) {
                list_push(&list_one, (void*) i);
        }

        list_push(&list_two, "This list owns");
        list_push(&list_two, "!");

        list_traverse(&list_one, FORWARD, print_ints);
        list_traverse(&list_two, FORWARD, print_chars);

        printf("\nSize of list_one %d", list_len(&list_one));
        printf("\nSize of list_two %d\n", list_len(&list_two));

        list_dispose(&list_one);
        list_dispose(&list_two);

        return 0;
}
