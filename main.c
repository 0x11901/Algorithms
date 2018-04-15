#include <stdio.h>
#include <stdlib.h>

#include "SeqList.h"
#include "LinkedList.h"

typedef struct {
    int data;
} Data;

int test_linked_list();
int test_seq_lise();

int main() {
    int res = -1;
    res = test_linked_list();
    //    res = test_seq_lise();
    return res;
}

int test_linked_list() { return 0; }

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