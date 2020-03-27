#include <stdio.h>
#include <stdlib.h>

#include "singly_linked_list.h"

Node *CreateNode(int param_data, Node *param_next) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = param_data;
  node->next = param_next;
  return node;
}

// TODO: fix this function
Node *CreateList(int data_arr[]) { return NULL; }

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

int GetListSizeR(Node *node) {
  return node ? (GetListSizeR(node->next) + 1) : 0;
}

/*
 * Inserts new node with param_data at head and returns pointer to the new
 * head node.
 */
void InsertHead(int param_data, Node **head_ref) {
  Node *temp = *head_ref;
  *head_ref = CreateNode(param_data, temp);
}

/*
 * Remove head node and returns pointer to the new head node.
 */
void RemoveHead(Node **head_ref) {
  Node *temp = *head_ref;
  *head_ref = temp->next;
  free(temp);
}

void InsertTail(int param_data, Node *head) {
  Node *new_node = CreateNode(param_data, NULL);
  Node *itr = head;
  if (!itr) {
    head = new_node;
    return;
  }
  while (itr->next) itr = itr->next;
  itr->next = new_node;
}

void RemoveTail(Node *head) {
  Node *itr = head;
  if (!itr) {
    return;
  } else if (!itr->next) {
    head = NULL;
    free(itr);
    return;
  }
  while (itr->next->next) itr = itr->next;
  Node *temp = itr->next;
  itr->next = NULL;
  free(temp);
}

Node *get_node_by_index(int param_index, Node *head) {
  int list_size = GetListSize(head);
  if (param_index >= list_size) return NULL;
  int index_counter = 0;
  Node *itr = head;
  while (index_counter < param_index) {
    ++index_counter;
    itr = itr->next;
  }
  return itr;
}

// O(n) time complexity
Node *get_node_by_counterindex(int con_index, Node *head) {
  Node *tortoise = head;
  Node *hare = head;
  while (con_index && hare->next) {
    hare = hare->next;
    --con_index;
  }
  while (hare->next) {
    hare = hare->next;
    tortoise = tortoise->next;
  }
  return tortoise;
}

void InsertNodeByIndex(int param_data, int param_index, Node **head_ref) {
  Node *head = *head_ref;
  Node *new_node = CreateNode(param_data, NULL);
  int list_size = GetListSize(head);
  if (param_index >= list_size) {
    return;
  } else if (param_index == 0) {
    new_node->next = head;
    *head_ref = new_node;
    return;
  }
  int index_counter = 0;
  Node *itr = *head_ref;
  while (index_counter < param_index - 1) {
    ++index_counter;
    itr = itr->next;
  }
  Node *temp = itr->next;
  itr->next = new_node;
  new_node->next = temp;
}

void RemoveNodeByIndex(int param_index, Node **head_ref) {
  Node *head = *head_ref;
  Node *temp = NULL;
  int list_size = GetListSize(head);
  if (param_index >= list_size) {
    return;
  } else if (param_index == 0) {
    temp = head;
    *head_ref = head->next;
    free(temp);
  }
  int index_counter = 0;
  Node *itr = *head_ref;
  while (index_counter < param_index - 1) {
    ++index_counter;
    itr = itr->next;
  }
  temp = itr->next;
  itr->next = itr->next->next;
  free(temp);
}

void ChangeDataByIndex(int param_data, int param_index, Node *head) {
  int list_size = GetListSize(head);
  if (param_index >= list_size) return;
  int index_counter = 0;
  Node *itr = head;
  while (index_counter < param_index) {
    ++index_counter;
    itr = itr->next;
  }
  itr->data = param_data;
}

// InsertBefore, DeleteBefore, InsertAfter, DeleteAfter

void ReverseList(Node **head_ref) {
  Node *prev = NULL;
  Node *curr = *head_ref;
  Node *next = NULL;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head_ref = prev;
}

/*
 * Returns the size of loop in the linked list.
 */
int Floyd(Node *head) {
  if (!head || !head->next || !head->next->next) return 0;
  int has_loop = 0;
  Node *tortoise = head;
  Node *hare = head;

  // Detect loop
  while (tortoise && hare && hare->next) {
    tortoise = tortoise->next;
    hare = hare->next->next;
    if (tortoise == hare) {
      has_loop = 1;
      break;
    }
  }
  if (has_loop) {
    int mu = 0;
    tortoise = head;

    // Find the first node of the loop
    while (tortoise != hare) {
      tortoise = tortoise->next;
      hare = hare->next;
      ++mu;
    }
    int lam = 1;
    hare = hare->next;

    // Find loop size
    while (tortoise != hare) {
      hare = hare->next;
      ++lam;
    }
    return lam;
  }
  return 0;
}

/*
 * Returns the size of loop in the linked list.
 */
int Brent(Node *head) {
  if (!head || !head->next) return 0;
  int power = 1;
  int lam = 1;
  Node *tortoise = head;
  Node *hare = head->next;

  // Find loop size
  while (tortoise != hare) {
    if (power == lam) {
      tortoise = hare;
      power *= 2;
      lam = 0;
    }
    hare = hare->next;
    ++lam;
  }

  // Find the first node of the loop
  tortoise = head;
  hare = head;
  for (int i = 0; i < lam; ++i) hare = hare->next;
  int mu = 0;
  while (tortoise != hare) {
    tortoise = tortoise->next;
    hare = hare->next;
    ++mu;
  }
  return lam;
}
