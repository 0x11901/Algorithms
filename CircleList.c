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

#include "CircleList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_CircleList {
    CircleListNode  header;
    CircleListNode *slider;
    int             length;
} TCircleList;

CircleList *CircleList_Create() {
    TCircleList *ret = (TCircleList *)malloc(sizeof(TCircleList));
    if (ret == NULL) {
        return NULL;
    }

    ret->length      = 0;
    ret->header.next = NULL;
    ret->slider      = NULL;
    return ret;
}

void CircleList_Destroy(CircleList *list) // O(1)
{
    if (list == NULL) {
        return;
    }
    free(list);
}

void CircleList_Clear(CircleList *list) // O(1)
{
    TCircleList *sList = (TCircleList *)list;
    if (sList == NULL) {
        return;
    }
    sList->length      = 0;
    sList->header.next = NULL;
    sList->slider      = NULL;
}

int CircleList_Length(CircleList *list) // O(1)
{
    TCircleList *sList = (TCircleList *)list;
    int          ret   = -1;
    if (list == NULL) {
        return ret;
    }
    ret = sList->length;
    return ret;
}

int CircleList_Insert(CircleList *list, CircleListNode *node, int pos) // O(n)
{
    int          ret = 0, i = 0;
    TCircleList *sList = (TCircleList *)list;

    if (list == NULL || node == NULL || pos < 0) {
        return -1;
    }
    // if( ret )
    {
        CircleListNode *current = (CircleListNode *)sList;

        for (i = 0; (i < pos) && (current->next != NULL); i++) {
            current = current->next;
        }

        // current->next 0号节点的地址
        node->next    = current->next; // 1
        current->next = node;          // 2

        //若第一次插入节点
        if (sList->length == 0) {
            sList->slider = node;
        }

        sList->length++;

        //若头插法
        if (current == (CircleListNode *)sList) {
            //获取最后一个元素
            CircleListNode *last = CircleList_Get(sList, sList->length - 1);
            last->next           = current->next; // 3
        }
    }

    return ret;
}

CircleListNode *CircleList_Get(CircleList *list, int pos) // O(n)
{
    TCircleList *   sList = (TCircleList *)list;
    CircleListNode *ret   = NULL;
    int             i     = 0;

    if (list == NULL || pos < 0) {
        return NULL;
    }
    // if( (sList != NULL) && (pos >= 0) && (sList->length > 0) )
    {
        CircleListNode *current = (CircleListNode *)sList;

        for (i = 0; i < pos; i++) {
            current = current->next;
        }

        ret = current->next;
    }

    return ret;
}

CircleListNode *CircleList_Delete(CircleList *list, int pos) // O(n)
{
    TCircleList *   sList = (TCircleList *)list;
    CircleListNode *ret   = NULL;
    int             i     = 0;

    if ((sList != NULL) && (pos >= 0) && (sList->length > 0)) {
        CircleListNode *current = (CircleListNode *)sList;
        CircleListNode *last    = NULL;

        for (i = 0; i < pos; i++) {
            current = current->next;
        }

        //若删除第一个元素
        if (current == (CircleListNode *)sList) {
            last = (CircleListNode *)CircleList_Get(sList, sList->length - 1);
        }

        //求要删除的元素
        ret           = current->next;
        current->next = ret->next;

        sList->length--;

        //判断链表是否为空
        if (last != NULL) {
            sList->header.next = ret->next;
            last->next         = ret->next;
        }

        //若删除的元素为游标所指的元素
        if (sList->slider == ret) {
            sList->slider = ret->next;
        }

        //若删除元素后，链表长度为0
        if (sList->length == 0) {
            sList->header.next = NULL;
            sList->slider      = NULL;
        }
    }

    return ret;
}

CircleListNode *CircleList_DeleteNode(CircleList *list, CircleListNode *node) // O(n)
{
    TCircleList *   sList = (TCircleList *)list;
    CircleListNode *ret   = NULL;
    int             i     = 0;

    if (sList != NULL) {
        CircleListNode *current = (CircleListNode *)sList;

        //查找node在循环链表中的位置i
        for (i = 0; i < sList->length; i++) {
            if (current->next == node) {
                ret = current->next;
                break;
            }

            current = current->next;
        }

        //如果ret找到，根据i去删除
        if (ret != NULL) {
            CircleList_Delete(sList, i);
        }
    }

    return ret;
}

CircleListNode *CircleList_Reset(CircleList *list) // O(1)
{
    TCircleList *   sList = (TCircleList *)list;
    CircleListNode *ret   = NULL;

    if (sList != NULL) {
        sList->slider = sList->header.next;
        ret           = sList->slider;
    }

    return ret;
}

CircleListNode *CircleList_Current(CircleList *list) // O(1)
{
    TCircleList *   sList = (TCircleList *)list;
    CircleListNode *ret   = NULL;

    if (sList != NULL) {
        ret = sList->slider;
    }

    return ret;
}

CircleListNode *CircleList_Next(CircleList *list) // O(1)
{
    TCircleList *   sList = (TCircleList *)list;
    CircleListNode *ret   = NULL;

    if ((sList != NULL) && (sList->slider != NULL)) {
        ret           = sList->slider;
        sList->slider = ret->next;
    }

    return ret;
}
