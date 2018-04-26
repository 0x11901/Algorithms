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

#ifndef ALGORITHMS_CIRCLELIST_H
#define ALGORITHMS_CIRCLELIST_H

typedef void CircleList;

typedef struct _tag_CircleListNode {
    struct _tag_CircleListNode *next;
} CircleListNode;

CircleList *CircleList_Create();

void List_Destroy(CircleList *list);

void CircleList_Clear(CircleList *list);

int CircleList_Length(CircleList *list);

int CircleList_Insert(CircleList *list, CircleListNode *node, int pos);

CircleListNode *CircleList_Get(CircleList *list, int pos);

CircleListNode *CircleList_Delete(CircleList *list, int pos);

CircleListNode *CircleList_DeleteNode(CircleList *list, CircleListNode *node);

CircleListNode *CircleList_Reset(CircleList *list);

CircleListNode *CircleList_Current(CircleList *list);

CircleListNode *CircleList_Next(CircleList *list);
#endif // ALGORITHMS_CIRCLELIST_H
