#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_
typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;

Node* CreateNode(int param_data);

void PrintList(Node* head);

int GetListSize(Node* head);

void InsertHead(int param_data, Node** head_ref);

void RemoveHead(Node** head_ref);

void InsertTail(int param_data, Node* head);

void RemoveTail(Node* head);

Node* get_node_by_index(int param_data, int param_index, Node* head);

void ReverseList(Node** head_ref);
#endif  // DOUBLY_LINKED_LIST_H_
