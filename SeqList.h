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

#ifndef ALGORITHMS_SEQLIST_H
#define ALGORITHMS_SEQLIST_H

typedef void SeqList;
typedef void SeqListNode;

SeqList *SeqList_Create(int capacity);

void SeqList_Destroy(SeqList *list);

void SeqList_Clear(SeqList *list);

int SeqList_Length(SeqList *list);

int SeqList_Capacity(SeqList *list);

int SeqList_Insert(SeqList *list, SeqListNode *node, int pos);

SeqListNode *SeqList_Get(SeqList *list, int pos);

SeqListNode *SeqList_Delete(SeqList *list, int pos);

#endif // ALGORITHMS_SEQLIST_H
