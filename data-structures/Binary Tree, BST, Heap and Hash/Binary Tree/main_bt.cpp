#include <iostream>
#include <cstdlib>

#include "binary_tree.h"

int main() {
  Node *root, *tmp;
  root = CreateNode(0);
  tmp = CreateNode(1);
  root->left = tmp;
  tmp = CreateNode(2);
  root->right = tmp;
  tmp = CreateNode(3);
  root->left->left = tmp;
  tmp = CreateNode(4);
  root->left->right = tmp;

  // Topological structure of the tree:
  //     0 root
  //    / \
  //   1   2
  //  / \
  // 3   4

  printf("Pre-order traversal: ");
  PreorderTraversal(root);
  putchar('\n');

  printf("In-order traversal: ");
  InorderTraversal(root);
  putchar('\n');

  printf("Post-order traversal: ");
  PostorderTraversal(root);
  putchar('\n');
}
