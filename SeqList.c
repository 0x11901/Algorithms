//
// Created by 王靖凯 on 2018/4/14.
//

#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_SeqList {
    int capacity;
    int length;
    unsigned int *node;
} TSeaList;

SeqList *SeqList_Create(int capacity) {
    if (capacity < 0) {
        return NULL;
    }
    TSeaList *res = NULL;
    res = (TSeaList *)calloc(1, sizeof(TSeaList *) +
                                    capacity * sizeof(unsigned *));
    if (res == NULL) {
        return NULL;
    }
    res->node = (unsigned int *)(res + 1);
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
    TSeaList *t = (TSeaList *)list;
    t->length = 0;
}

int SeqList_Length(SeqList *list) {
    if (list == NULL) {
        return -1;
    }
    TSeaList *t = (TSeaList *)list;
    return t->length;
}

int SeqList_Capacity(SeqList *list) {
    if (list == NULL) {
        return -1;
    }
    TSeaList *t = (TSeaList *)list;
    return t->capacity;
}

int SeqList_Insert(SeqList *list, SeqListNode *node, int pos) {
    for (int i = SeqList_Length(list); i < pos; --i) {
    }
    return 0;
}

SeqListNode *SeqList_Get(SeqList *list, int pos) { return NULL; }

SeqListNode *SeqList_Delete(SeqList *list, int pos) { return NULL; }
