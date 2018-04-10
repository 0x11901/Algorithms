#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int test_linked_list();

int main() {
  int res = test_linked_list();
  return res;
}

int test_linked_list() {
  // test linked list
  list *start = create_list();

  for (int i = 0; i < 10; ++i) {
    insert_list(start, i, i);
  }

  delete_list(start, 5);
  delete_list(start, 9);

  insert_list(start, 2, 100);

  printf("count is :%d\n", count_list(start));

  traverse(start);

  list *p = locale_list(start, 5);
  printf("local 5's data:%d\n", p->data);

  int pos = elem_pos(start, 2);
  int pos2 = elem_pos(start, 7);
  printf("positions are %d,%d\n", pos, pos2);

  list *ls2 = create_list();
  for (int j = 0; j < 10; ++j) {
    insert_list(ls2, j, j + 100);
  }

  merge_list(start, ls2);

  reverse(start);

  traverse(start);

  clear_list(start);
  traverse(start);

  clear_list(start);
  traverse(start);

  free(start);

  return 0;
}