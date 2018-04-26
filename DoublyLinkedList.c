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

#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_DoublyLinkedList {
    DoublyLinkedListNode  header;
    DoublyLinkedListNode *slider;
    int                   length;
} TDoublyLinkedList;

DoublyLinkedList *DoublyLinkedList_Create() {
    TDoublyLinkedList *ret = (TDoublyLinkedList *)malloc(sizeof(TDoublyLinkedList));

    if (ret != NULL) {
        ret->length      = 0;
        ret->header.next = NULL;
        ret->header.pre  = NULL;
        ret->slider      = NULL;
    }

    return ret;
}

void DoublyLinkedList_Destroy(DoublyLinkedList *list) {
    if (list != NULL) {
        free(list);
    }
}

void DoublyLinkedList_Clear(DoublyLinkedList *list) {
    TDoublyLinkedList *sList = (TDoublyLinkedList *)list;

    if (sList != NULL) {
        sList->length      = 0;
        sList->header.next = NULL;
        sList->header.pre  = NULL;
        sList->slider      = NULL;
    }
}

int DoublyLinkedList_Length(DoublyLinkedList *list) {
    TDoublyLinkedList *sList = (TDoublyLinkedList *)list;
    int                ret   = -1;

    if (sList != NULL) {
        ret = sList->length;
    }

    return ret;
}

int DoublyLinkedList_Insert(DoublyLinkedList *list, DoublyLinkedListNode *node, int pos) {
    int                ret = 0, i = 0;
    TDoublyLinkedList *sList = (TDoublyLinkedList *)list;

    if (list == NULL || node == NULL || pos < 0) {
        return -1;
    }

    {
        DoublyLinkedListNode *current = (DoublyLinkedListNode *)sList;
        DoublyLinkedListNode *next    = NULL; //需要增加next指针

        for (i = 0; (i < pos) && (current->next != NULL); i++) {
            current = current->next;
        }

        next = current->next;

        current->next = node;
        node->next    = next;

        if (next != NULL) //当链表插入第一个元素，需要特殊处理
        {
            next->pre = node;
        }
        node->pre = current;

        if (sList->length == 0) {
            sList->slider = node; //当链表插入第一个元素处理游标
        }

        //若在0位置插入，需要特殊处理 新来结点next前pre指向null
        if (current == (DoublyLinkedListNode *)sList) {
            node->pre = NULL;
        }

        sList->length++;
    }

    return ret;
}

DoublyLinkedListNode *DoublyLinkedList_Get(DoublyLinkedList *list, int pos) {
    TDoublyLinkedList *   sList = (TDoublyLinkedList *)list;
    DoublyLinkedListNode *ret   = NULL;
    int                   i     = 0;

    if ((sList != NULL) && (0 <= pos) && (pos < sList->length)) {
        DoublyLinkedListNode *current = (DoublyLinkedListNode *)sList;

        for (i = 0; i < pos; i++) {
            current = current->next;
        }

        ret = current->next;
    }

    return ret;
}

DoublyLinkedListNode *DoublyLinkedList_Delete(DoublyLinkedList *list, int pos) {
    TDoublyLinkedList *   sList = (TDoublyLinkedList *)list;
    DoublyLinkedListNode *ret   = NULL;
    int                   i     = 0;
    if (sList == NULL || pos < 0) {
        return NULL;
    }
    // if( (sList != NULL) && (0 <= pos) && (pos < sList->length) )
    {
        DoublyLinkedListNode *current = (DoublyLinkedListNode *)sList;
        DoublyLinkedListNode *next    = NULL; //需要增加next指针

        for (i = 0; i < pos; i++) {
            current = current->next;
        }

        ret  = current->next;
        next = ret->next;

        current->next = next;

        if (next != NULL) //需要特殊处理
        {
            next->pre = current;

            if (current == (DoublyLinkedListNode *)sList) //若第0个位置，需要特殊处理
            {
                next->pre = NULL;
            }
        }

        if (sList->slider == ret) {
            sList->slider = next;
        }

        sList->length--;
    }

    return ret;
}

DoublyLinkedListNode *DoublyLinkedList_DeleteNode(DoublyLinkedList *list, DoublyLinkedListNode *node) {
    TDoublyLinkedList *   sList = (TDoublyLinkedList *)list;
    DoublyLinkedListNode *ret   = NULL;
    int                   i     = 0;

    if (sList != NULL) {
        DoublyLinkedListNode *current = (DoublyLinkedListNode *)sList;

        for (i = 0; i < sList->length; i++) {
            if (current->next == node) {
                ret = current->next;
                break;
            }

            current = current->next;
        }

        if (ret != NULL) {
            DoublyLinkedList_Delete(sList, i);
        }
    }

    return ret;
}

DoublyLinkedListNode *DoublyLinkedList_Reset(DoublyLinkedList *list) {
    TDoublyLinkedList *   sList = (TDoublyLinkedList *)list;
    DoublyLinkedListNode *ret   = NULL;

    if (sList != NULL) {
        sList->slider = sList->header.next;
        ret           = sList->slider;
    }

    return ret;
}

DoublyLinkedListNode *DoublyLinkedList_Current(DoublyLinkedList *list) {
    TDoublyLinkedList *   sList = (TDoublyLinkedList *)list;
    DoublyLinkedListNode *ret   = NULL;

    if (sList != NULL) {
        ret = sList->slider;
    }

    return ret;
}

DoublyLinkedListNode *DoublyLinkedList_Next(DoublyLinkedList *list) {
    TDoublyLinkedList *   sList = (TDoublyLinkedList *)list;
    DoublyLinkedListNode *ret   = NULL;

    if ((sList != NULL) && (sList->slider != NULL)) {
        ret           = sList->slider;
        sList->slider = ret->next;
    }

    return ret;
}

DoublyLinkedListNode *DoublyLinkedList_Pre(DoublyLinkedList *list) {
    TDoublyLinkedList *   sList = (TDoublyLinkedList *)list;
    DoublyLinkedListNode *ret   = NULL;

    if ((sList != NULL) && (sList->slider != NULL)) {
        ret           = sList->slider;
        sList->slider = ret->pre;
    }

    return ret;
}