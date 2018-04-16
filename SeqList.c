//
// Created by 王靖凯 on 2018/4/14.
//

#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_SeqList {
    int capacity;
    int length;
    unsigned long *node;
} TSeqList;

SeqList *SeqList_Create(int capacity) {
    if (capacity < 0) {
        return NULL;
    }
    TSeqList *res = NULL;
    res = (TSeqList *)calloc(1, sizeof(TSeqList) + capacity * sizeof(unsigned long));
    if (res == NULL) {
        return NULL;
    }
    res->node = (unsigned long *)(res + 1);
    res->capacity = capacity;
    res->length = 0;
    return res;
}

void SeqList_Destroy(SeqList *list) {
    if (list != NULL) {
        free(list);
    }
}

void SeqList_Clear(SeqList *list) {
    if (list == NULL) {
        return;
    }
    TSeqList *t = (TSeqList *)list;
    t->length = 0;
}

int SeqList_Length(SeqList *list) {
    if (list == NULL) {
        return -1;
    }
    TSeqList *t = (TSeqList *)list;
    return t->length;
}

int SeqList_Capacity(SeqList *list) {
    if (list == NULL) {
        return -1;
    }
    TSeqList *t = (TSeqList *)list;
    return t->capacity;
}

int SeqList_Insert(SeqList *list, SeqListNode *node, int pos) {
    if (node == NULL || list == NULL) {
        return -1;
    }
    TSeqList *t = list;
    if (t->length >= t->capacity) {
        return -2;
    }
    if (pos < 0 || pos >= t->capacity) {
        return -3;
    }
    int length = t->length;
    if (pos >= length) {
        pos = length;
    }

    for (int i = t->length; i > pos; --i) {
        t->node[i] = t->node[i - 1];
    }
    t->node[pos] = (unsigned long)node;
    t->length++;
    return 0;
}

SeqListNode *SeqList_Get(SeqList *list, int pos) {
    SeqListNode *ret = NULL;
    TSeqList *t = NULL;
    t = (TSeqList *)list;
    if (list == NULL || pos < 0 || pos >= t->length) {
        return NULL;
    }
    ret = (SeqListNode *)t->node[pos];
    return ret;
}

SeqListNode *SeqList_Delete(SeqList *list, int pos) {
    SeqList *res = NULL;
    if (list == NULL) {
        return res;
    }
    TSeqList *t = list;
    if (pos < 0 || pos >= t->length) {
        return NULL;
    }
    res = (SeqListNode *)t->node[pos];
    for (int i = pos + 1; i < t->length; ++i) {
        t->node[i - 1] = t->node[i];
    }
    t->length--;
    return res;
}
