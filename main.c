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
    res = test_linked_list();
    //    res = test_seq_lise();
    return res;
}

int test_linked_list() {
    Data t1, t2, t3;

    LinkedList *list = NULL;
    t1.data = 31;
    t2.data = 32;
    t3.data = 33;

    list = LinkedList_Create();

    LinkedList_Insert(list, (LinkedListNode *)&t1, LinkedList_Length(list));
    LinkedList_Insert(list, (LinkedListNode *)&t2, LinkedList_Length(list));
    LinkedList_Insert(list, (LinkedListNode *)&t3, LinkedList_Length(list));

    for (int i = 0; i < LinkedList_Length(list); i++) {
        Data *tmp = (Data *)LinkedList_Get(list, i);
        if (tmp != NULL) {
            printf("age:%d ", tmp->data);
        }
    }

    while (LinkedList_Length(list) > 0) {
        Data *tmp = (Data *)LinkedList_Delete(list, 0);
        if (tmp != NULL) {
//            printf("age:%d ", tmp->data);
        }
    }

    LinkedList_Destroy(list);
    return 0;
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