#include <stdio.h>
#include "LinkedList.h"

int main() {
    //test linked list
    list *start = create_list();
    list *first = create_list();
    list *second = create_list();
    list *third = create_list();

    start->data = 1984;
    first->data = 1;
    second->data = 2;
    third->data = 3;

    start->next = first;
    first->next = second;
    second->next = third;

    traverse(start);

    return 0;
}