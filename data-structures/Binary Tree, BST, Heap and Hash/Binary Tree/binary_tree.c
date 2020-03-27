#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

Node *CreateNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Pre-order: NLR
void PreorderTraversal(Node *node) {
  printf("%d ", node->data);
  if (node->left) PreorderTraversal(node->left);
  if (node->right) PreorderTraversal(node->right);
}

// In-order: LNR
void InorderTraversal(Node *node) {
  if (node->left) InorderTraversal(node->left);
  printf("%d ", node->data);
  if (node->right) InorderTraversal(node->right);
}

// Post-order: LRN
void PostorderTraversal(Node *node) {
  if (node->right) PostorderTraversal(node->right);
  printf("%d ", node->data);
  if (node->left) PostorderTraversal(node->left);
}
