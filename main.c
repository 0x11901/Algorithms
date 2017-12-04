#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "des.h"

#define MAX_LENGTH 1024


void swap(int *x,int *y);

int mian() {
    int res = test_linked_list();
//    int res = test_des();
    return res;
}

int test_des() {
    char *plain = "hello world!";
    size_t length = strlen(plain);
    char *crypdata[MAX_LENGTH] = {0};
    int cryplen = -2;
    int res_enc =  DesEnc(plain,length,crypdata,&cryplen);
    if (res_enc != 0) {
        printf("des_enc err(%d)\n",res_enc);
        return -1;
    }

    char *decode[MAX_LENGTH];
    int decode_len = -1;
    int  res_dec = DesDec(crypdata,cryplen,decode,&decode_len);
    if (res_dec !=0) {
        printf("des_dec err(%d)\n",res_enc);
        return -1;
    }

    if (cryplen != decode_len) {
       printf("两次明文长度不同");
        return -1;
    }
    if (memcmp(plain,decode,cryplen) != 0){
        printf("加解密后内容不同");
        return -1;
    }
    printf("before: %s\nafter:\n%s\n",plain,decode);

    return 0;
}

int test_linked_list() {
    //test linked list
    list *start = create_list();

    for (int i = 0; i < 10; ++i) {
        insert_list(start,i,i + 1);
    }

    delete_list(start,1);
    delete_list(start,9);

    printf("count is :%d\n",count_list(start));

    traverse(start);

    list *p = locale_list(start,5);
    printf("local 5's data:%d\n",p->data);

    int pos = elem_pos(start,2);
    int pos2 = elem_pos(start,7);
    printf("positions are %d,%d\n",pos,pos2);

    list *ls2 = create_list();
    for (int j = 0; j < 10; ++j) {
        insert_list(ls2,j,j +100);
    }

    merge_list(start,ls2);

    reverse(start);


    traverse(start);

    clear_list(start);
    traverse(start);

    clear_list(start);
    traverse(start);

    free(start);

    return 0;
}