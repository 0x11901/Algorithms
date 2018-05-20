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

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void println(int array[], int len) {
    int i = 0;

    for (i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}
void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void InertionSort_ddddd(int array[], int len) // O(n*n)
{
    int i    = 0;
    int j    = 0;
    int k    = -1;
    int temp = -1;

    //{12, 5, 433, 253, 216, 7};
    for (i = 1; i < len; i++) {
        k    = i; //待插入位置
        temp = array[k];

        for (j = i - 1; (j >= 0) && (array[j] > temp); j--) {
            array[j + 1] = array[j]; //元素后移
            k            = j;        // k需要插入的位置
        }

        array[k] = temp; //元素插入
    }
}

// nlogn
void ShellSort(int array[], int len) //
{
    int i    = 0;
    int j    = 0;
    int k    = -1;
    int temp = -1;
    int gap  = len;
    do {
        //业界统一实验的 平均最好情况 经过若干次后，收敛为1
        gap = gap / 3 + 1; // gap /2345 2000 都行  //O（n 1.3）

        for (i = gap; i < len; i += gap) {
            k    = i;
            temp = array[k];

            for (j = i - gap; (j >= 0) && (array[j] > temp); j -= gap) {
                array[j + gap] = array[j];
                k              = j;
            }

            array[k] = temp;
        }

    } while (gap > 1);
}

int main() {
    int array[] = { 12, 5, 433, 253, 216, 7 };
    int len     = sizeof(array) / sizeof(*array);

    println(array, len);
    ShellSort(array, len);
    println(array, len);
    system("pause");
    return 0;
}
