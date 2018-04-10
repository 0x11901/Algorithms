//
// Created by 王靖凯 on 2017/11/9.
//

#ifndef ALGORITHMS_LINKEDLIST_H
#define ALGORITHMS_LINKEDLIST_H

#endif // ALGORITHMS_LINKEDLIST_H

typedef struct list {
  int data;
  struct list *next;
} list;

struct list *create_list();                                 //建立一个节点
void traverse(struct list *ls);                             //循环遍历链表
struct list *insert_list(struct list *ls, int n, int data); //在指定位置插入元素
int delete_list(struct list *ls, int n); //删除指定位置元素
int count_list(struct list *ls);         //返回链表元素个数
void clear_list(struct list *ls);        //清空链表，只保留首节点
int empty_list(struct list *ls);         //返回链表是否为空
struct list *locale_list(struct list *ls, int n); //返回链表指定位置的节点
struct list *elem_locale(struct list *ls, int data); //返回数据域等于data的节点
int elem_pos(struct list *ls, int data); //返回数据域等于data的节点位置
struct list *last_list(struct list *ls); //得到链表最后一个节点
void merge_list(struct list *ls1,
                struct list *ls2); //合并两个链表,结果放入ls1中
void reverse(struct list *ls);     //链表逆置