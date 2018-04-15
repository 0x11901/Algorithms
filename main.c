#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "SeqList.h"

typedef struct {
    int data;
} Data;

int test_linked_list();
int test_seq_lise();

int main() {
    int res = -1;
    //    res = test_linked_list();
    res = test_seq_lise();
    return res;
}

int test_seq_lise() {
    SeqList *list = NULL;

    Data d1, d2, d3;
    d1.data = 1;
    d2.data = 2;
    d3.data = 3;

    list = SeqList_Create(10);
    int length = SeqList_Length(list);
    SeqList_Insert(list, &d1, length);
    SeqList_Insert(list, &d2, length);
    SeqList_Insert(list, &d3, length);
    for (int i = 0; i < SeqList_Length(list); ++i) {
        Data *data = SeqList_Get(list, i);
        if (data != NULL) {
            printf("data is %d\n", data->data);
        }
    }

    while (SeqList_Length(list) > 0) {
        Data *data = SeqList_Delete(list, 0);
        if (data != NULL) {
            printf("data is %d\n", data->data);
        }
    }

    printf("length is %d\n", SeqList_Length(list));
    SeqList_Destroy(list);
    return 0;
}

int test_linked_list() {
    // test linked list
    list *start = create_list();

    for (int i = 0; i < 10; ++i) {
        insert_list(start, i, i);
    }

    delete_list(start, 5);
    delete_list(start, 9);

    insert_list(start, 2, 100);

    printf("count is :%d\n", count_list(start));

    traverse(start);

    list *p = locale_list(start, 5);
    printf("local 5's data:%d\n", p->data);

    int pos = elem_pos(start, 2);
    int pos2 = elem_pos(start, 7);
    printf("positions are %d,%d\n", pos, pos2);

    list *ls2 = create_list();
    for (int j = 0; j < 10; ++j) {
        insert_list(ls2, j, j + 100);
    }

    merge_list(start, ls2);

    reverse(start);

    traverse(start);

    clear_list(start);
    traverse(start);

    clear_list(start);
    traverse(start);

    free(start);

    return 0;
}