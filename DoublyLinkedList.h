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

#ifndef ALGORITHMS_DOUBLYLINKEDLIST_H
#define ALGORITHMS_DOUBLYLINKEDLIST_H

typedef void DoublyLinkedList;
/*
typedef struct _tag_DoublyLinkedListNode DoublyLinkedListNode;
struct _tag_DoublyLinkedListNode
{
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* pre;
};
*/

typedef struct _tag_DoublyLinkedListNode {
    struct _tag_DoublyLinkedListNode *next;
    struct _tag_DoublyLinkedListNode *pre;
} DoublyLinkedListNode;

DoublyLinkedList *DoublyLinkedList_Create();

void DoublyLinkedList_Destroy(DoublyLinkedList *list);

void DoublyLinkedList_Clear(DoublyLinkedList *list);

int DoublyLinkedList_Length(DoublyLinkedList *list);

int DoublyLinkedList_Insert(DoublyLinkedList *list, DoublyLinkedListNode *node, int pos);

DoublyLinkedListNode *DoublyLinkedList_Get(DoublyLinkedList *list, int pos);

DoublyLinkedListNode *DoublyLinkedList_Delete(DoublyLinkedList *list, int pos);

//-- add
DoublyLinkedListNode *DoublyLinkedList_DeleteNode(DoublyLinkedList *list, DoublyLinkedListNode *node);

DoublyLinkedListNode *DoublyLinkedList_Reset(DoublyLinkedList *list);

DoublyLinkedListNode *DoublyLinkedList_Current(DoublyLinkedList *list);

DoublyLinkedListNode *DoublyLinkedList_Next(DoublyLinkedList *list);

DoublyLinkedListNode *DoublyLinkedList_Pre(DoublyLinkedList *list);

#endif // ALGORITHMS_DOUBLYLINKEDLIST_H
