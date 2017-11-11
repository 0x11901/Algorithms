//
// Created by 王靖凯 on 2017/11/9.
//

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*建立一个节点*/
struct list *create_list() {
    return calloc(1, sizeof(struct list));
}

/*循环遍历链表*/
void traverse(struct list *ls) {
    struct list *p = ls->next;
    while (p) {
        printf("%d\n",p->data);
        p = p->next;
    }
}

/*在指定位置插入元素*/
struct list *insert_list(struct list *ls, int n, int data) {
    list *p = ls;
    while (p && n--) {
        p = p->next;
    }
    if (!p)
        return NULL;
    else {
        list *node = create_list();
        node->data = data;
        node->next = p->next;
        p->next = node;
        return node;
    }
}

/*删除指定位置元素*/
int delete_list(struct list *ls, int n) {
    list *p = ls;
    while (p && --n) {
        p = p->next;
    }
    if (!p)
        return 0;
    list *node = p->next;
    if (!node)
        return 0;
    p->next = node->next;
    free(node);
    return 1;
}

/*返回链表元素个数*/
int count_list(struct list *ls) {
    list *p = ls->next;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

/*清空链表，只保留首节点*/
void clear_list(struct list *ls) {
    list *s = ls;
    list *p = ls->next;
    list *n = p->next;
    if (!s->next)
        return;
    while (n) {
        free(p);
        p = n;
        n = n->next;
    }
    s->next = NULL;
}

/*返回链表是否为空*/
int empty_list(struct list *ls) {
    return ls->next == NULL ? 0 : 1;
}

/*返回链表指定位置的节点*/
struct list *locale_list(struct list *ls, int n) {
    list *p = ls;
    while (p && n--) {
        p = p->next;
    }
    if (!p)
        return NULL;
    return p;
}

/*返回数据域等于data的节点*/
struct list *elem_locale(struct list *ls, int data) {
    list *p = ls->next;
    int n = 1;
    while (p) {
        if (p->data == data)
            return p;
        p = p->next;
        n++;
    }
    return NULL;
}


int elem_pos(struct list *ls, int data);//返回数据域等于data的节点位置
struct list *last_list(struct list *ls);//得到链表最后一个节点
void merge_list(struct list *ls1, struct list *ls2);//合并两个链表,结果放入st1中
void reverse(struct list *ls);//链表逆置