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

#ifndef ALGORITHMS_LINKEDSTACK_H
#define ALGORITHMS_LINKEDSTACK_H
typedef void LinkedStack;

LinkedStack *LinkedStack_Create();

void LinkedStack_Destroy(LinkedStack *stack);

void LinkedStack_Clear(LinkedStack *stack);

int LinkedStack_Push(LinkedStack *stack, void *item);

void *LinkedStack_Pop(LinkedStack *stack);

void *LinkedStack_Top(LinkedStack *stack);

int LinkedStack_Size(LinkedStack *stack);
#endif // ALGORITHMS_LINKEDSTACK_H
