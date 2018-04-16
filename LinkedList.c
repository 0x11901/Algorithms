//
// Created by 王靖凯 on 2018/4/15.
//

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_LinkList {
    LinkedListNode header;
    int length;
} TLinkedList;

LinkedList *LinkedList_Create() { return calloc(1, sizeof(TLinkedList)); }

void LinkedList_Destroy(LinkedList *list) {
    if (list) free(list);
}

void LinkedList_Clear(LinkedList *list) {
    TLinkedList *t = (TLinkedList *)list;
    t->header.next = NULL;
    t->length = 0;
}

int LinkedList_Length(LinkedList *list) {
    if (list == NULL) return 0;
    return ((TLinkedList *)list)->length;
}

int LinkedList_Insert(LinkedList *list, LinkedListNode *node, int pos) {
    if (list == NULL || node == NULL) {
        return -1;
    } else if (pos < 0) {
        return -2;
    }
    TLinkedList *t = list;
    if (pos > t->length) { pos = t->length; }
    LinkedListNode *p = &(t->header);
    while (p->next && pos--) { p = p->next; }
    node->next = p->next;
    p->next = node;
    ++t->length;
    return 0;
}

LinkedListNode *LinkedList_Get(LinkedList *list, int pos) {
    if (list && pos > -1) {
        TLinkedList *t = list;
        LinkedListNode *p = &(t->header);
        while (p->next && pos--) { p = p->next; }
        return p;
    }
    return NULL;
}

LinkedListNode *LinkedList_Delete(LinkedList *list, int pos) { return NULL; }
