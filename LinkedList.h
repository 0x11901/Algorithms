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
