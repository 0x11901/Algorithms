#include <stdio.h>
#include "LinkedList.h"

int main() {
    //test linked list
    list *start = create_list();

    for (int i = 0; i < 10; ++i) {
        insert_list(start,i,i + 1);
    }

    delete_list(start,1);
    delete_list(start,9);

    printf("%d\n",count_list(start));

    traverse(start);

    clear_list(start);
    traverse(start);

    clear_list(start);
    traverse(start);

    return 0;
}