//
// Created by 王靖凯 on 2018/4/14.
//

#include "SeqList.h"

SeqList *SeqList_Create(int capacity) { return NULL; }

void SeqList_Destroy(SeqList *list) {}

void SeqList_Clear(SeqList *list) {}

int SeqList_Length(SeqList *list) { return 0; }

int SeqList_Capacity(SeqList *list) { return 0; }

int SeqList_Insert(SeqList *list, SeqListNode *node, int pos) {
    for (int i = SeqList_Length(list); i < pos; --i) {

    }
    return 0; }

SeqListNode *SeqList_Get(SeqList *list, int pos) { return NULL; }

SeqListNode *SeqList_Delete(SeqList *list, int pos) { return NULL; }
