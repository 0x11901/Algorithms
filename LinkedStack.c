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

#include "LinkedStack.h"
#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Teacher {
    LinkedListNode node;
    void *         item;
} Teacher;

LinkedStack *LinkedStack_Create() {
    return LinkedList_Create();
}

void LinkedStack_Destroy(LinkedStack *stack) {}

void LinkedStack_Clear(LinkedStack *stack) {}

int LinkedStack_Push(LinkedStack *stack, void *item) {
    int      ret = 0;
    Teacher *pTe = (Teacher *)malloc(sizeof(Teacher));
    if (pTe == NULL) {
        return -1;
    }
    pTe->item = item;

    ret = LinkedList_Insert(stack, (LinkedListNode *)(&pTe->node), 0);
    if (ret != 0) {
        free(pTe);
    }
    return ret;
}

void *LinkedStack_Pop(LinkedStack *stack) {
    void *   myItem = NULL;
    Teacher *pTmp   = NULL;
    pTmp            = (Teacher *)LinkedList_Delete(stack, 0);
    if (pTmp == NULL) {
        return NULL;
    }
    myItem = pTmp->item;

    if (pTmp != NULL) {
        free(pTmp);
    }
    return myItem;
}

void *LinkedStack_Top(LinkedStack *stack) {
    return NULL;
}

int LinkedStack_Size(LinkedStack *stack) {
    return LinkedList_Length(stack);
}