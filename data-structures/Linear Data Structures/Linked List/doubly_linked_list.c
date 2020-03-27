#include <stdio.h>

#include "doubly_linked_list.h"

Node *CreateNode(int param_data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = param_data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void PrintList(Node *head) {
  Node *itr = head;
  while (itr) {
    printf("%d ", itr->data);
    itr = itr->next;
  }
  printf("\n");
}

int GetListSize(Node *head) {
  int size = 0;
  Node *itr = head;
  while (itr) {
    ++size;
    itr = itr->next;
  }
  return size;
}
