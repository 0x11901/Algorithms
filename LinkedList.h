//
// Created by 王靖凯 on 2018/4/15.
//

#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

typedef void LinkedList;

typedef struct _tag_LinkedListNode {
    struct _tag_LinkedListNode *next;
} LinkedListNode;

LinkedList *LinkedList_Create();

void LinkedList_Destroy(LinkedList *list);

void LinkedList_Clear(LinkedList *list);

int LinkedList_Length(LinkedList *list);

int LinkedList_Insert(LinkedList *list, LinkedListNode *node, int pos);

LinkedListNode *LinkedList_Get(LinkedList *list, int pos);

LinkedListNode *LinkedList_Delete(LinkedList *list, int pos);

#endif // ALGORITHMS_LINKEDLIST_H
