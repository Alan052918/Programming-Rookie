#include <stdio.h>

#include "singly_linked_list.h"

int main() {
  Node *head = CreateNode(1, NULL);
  Node *second = CreateNode(2, NULL);
  Node *third = CreateNode(3, NULL);

  head->next = second;
  second->next = third;

  printf("Initial singly linked list\n");
  PrintList(head);

  printf("Insert 0 at head\n");
  InsertHead(0, &head);
  PrintList(head);

  printf("Insert 4 at tail\n");
  InsertTail(4, head);
  PrintList(head);

  printf("Get list size iteratively: %d\n", GetListSize(head));
  printf("Get list size recursively: %d\n", GetListSizeR(head));

  printf("Get data of node number 3\n");
  Node *temp = get_node_by_index(3, head);
  printf("%d\n", temp->data);

  printf("Get data of node 2 to tail\n");
  temp = get_node_by_counterindex(2, head);
  printf("%d\n", temp->data);

  printf("Insert at node number 3\n");
  InsertNodeByIndex(5, 3, &head);
  PrintList(head);

  printf("Remove node at number 2\n");
  RemoveNodeByIndex(2, &head);
  PrintList(head);

  printf("Change data of node number 2 to 6\n");
  ChangeDataByIndex(6, 2, head);
  PrintList(head);

  printf("Reverse list\n");
  ReverseList(&head);
  PrintList(head);

  printf("Remove head\n");
  RemoveHead(&head);
  PrintList(head);

  printf("Remove tail\n");
  RemoveTail(head);
  PrintList(head);

  printf("Loop detection\n");
  temp = get_node_by_index(GetListSize(head) - 1, head);
  temp->next = head;
  int loop_size = Floyd(head);
  printf("Floyd | Loop size: %d node(s)\n", loop_size);

  loop_size = Brent(head);
  printf("Brent | Loop size: %d node(s)\n", loop_size);
}
