#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
    //test linked list
    list *start = create_list();

    for (int i = 0; i < 10; ++i) {
        insert_list(start,i,i + 1);
    }

    delete_list(start,1);
    delete_list(start,9);

    printf("count is :%d\n",count_list(start));

    traverse(start);

    list *p = locale_list(start,5);
    printf("local 5's data:%d\n",p->data);

    clear_list(start);
    traverse(start);

    clear_list(start);
    traverse(start);

    free(start);

    return 0;
}