#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_
typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *CreateNode(int param_data, Node *param_next);

// To be finished
Node *CreateList(int data_arr[]);

void PrintList(Node *head);

// Iteratively get list size
int GetListSize(Node *head);

// Recursively get list size
int GetListSizeR(Node *node);

void InsertHead(int param_data, Node **head_ref);

void RemoveHead(Node **head_ref);

void InsertTail(int param_data, Node *head);

void RemoveTail(Node *head);

Node *get_node_by_index(int param_index, Node *head);

Node *get_node_by_counterindex(int con_index, Node *head);

void InsertNodeByIndex(int param_data, int param_index, Node **head_ref);

void RemoveNodeByIndex(int param_index, Node **head_ref);

void ChangeDataByIndex(int param_data, int param_index, Node *head);

// Not implemented
void InsertBefore(int param_data, int target_data, Node *head);
void DeleteBefore(int target_data, Node *head);
void InsertAfter(int param_data, int target_data, Node *head);
void DeleteAfter(int param_data, int target_data, Node *head);

void ReverseList(Node **head_ref);

void InsertionSort(Node **head_ref);

// Loop detection
int Floyd(Node *head);

// Loop detection
int Brent(Node *head);
#endif  // SINGLY_LINKED_LIST_H_
