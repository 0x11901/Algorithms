//******************************************************************************
//
// Copyright (c) 2018 WANG,Jingkai. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_LinkList {
    LinkedListNode header;
    int            length;
} TLinkedList;

LinkedList *LinkedList_Create() {
    return calloc(1, sizeof(TLinkedList));
}

void LinkedList_Destroy(LinkedList *list) {
    if (list) free(list);
}

void LinkedList_Clear(LinkedList *list) {
    TLinkedList *t = (TLinkedList *)list;
    t->header.next = NULL;
    t->length      = 0;
}

int LinkedList_Length(LinkedList *list) {
    if (list == NULL) return 0;
    return ((TLinkedList *)list)->length;
}

int LinkedList_Insert(LinkedList *list, LinkedListNode *node, int pos) {
    if (list == NULL || node == NULL) {
        return -1;
    }
    else if (pos < 0) {
        return -2;
    }
    TLinkedList *t = list;
    if (pos > t->length) {
        pos = t->length;
    }
    LinkedListNode *p = &(t->header);
    while (p->next && pos--) {
        p = p->next;
    }
    node->next = p->next;
    p->next    = node;
    ++t->length;
    return 0;
}

LinkedListNode *LinkedList_Get(LinkedList *list, int pos) {
    TLinkedList *t = list;
    if (list && pos > -1 && pos <= t->length) {
        LinkedListNode *p = &(t->header);
        while (p->next && pos--) {
            p = p->next;
        }
        return p->next;
    }
    return NULL;
}

LinkedListNode *LinkedList_Delete(LinkedList *list, int pos) {
    TLinkedList *t = list;
    if (list && pos > -1 && pos <= t->length) {
        LinkedListNode *p = &(t->header);
        while (p->next && pos--) {
            p = p->next;
        }
        LinkedListNode *tmp = p->next;
        p->next             = tmp->next;
        --t->length;
        return tmp;
    }
    return NULL;
}
