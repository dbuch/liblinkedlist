#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int
main(void)
{
        LIST list_one;
        LIST list_two;

        list_init(&list_one);
        list_init(&list_two);

        list_push(&list_one, "Hello");
        list_push(&list_one, "World");

        list_push(&list_two, "This list owns");
        list_push(&list_two, "!");

        list_traverse(&list_one, print_chars);
        list_traverse(&list_two, print_chars);

        list_dispose(&list_one);
        list_dispose(&list_two);

        return 0;
}
