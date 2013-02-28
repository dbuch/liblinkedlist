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

        for (char a = 'a'; a <= 'z'; a++) {
                list_push(&list_one, "a");
        }

        list_push(&list_two, "This list owns");
        list_push(&list_two, "!");

        list_traverse(&list_one, print_chars);
        list_traverse(&list_two, print_chars);

        printf("\nSize of list_one %d", list_len(&list_one));
        printf("\nSize of list_two %d\n", list_len(&list_two));

        list_dispose(&list_one);
        list_dispose(&list_two);

        return 0;
}
