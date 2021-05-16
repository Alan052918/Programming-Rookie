#include <iostream>
#include <cstdlib>

#include "binary_tree.h"

void initEntry(Entry *entry, std::string key, VAL_T value) {
  entry->key = key;
  entry->val = value;
}

Node *makeNode() {
  Node *node = (Node *)malloc(sizeof(Node));
  memset(node, '\0', sizeof(Node));
  node->left = NULL;
  node->right = NULL;
}

class BinaryTree {
  Node *root;

  // Node operation
  void insertNode(Node *root, std::string key, VAL_T value) {
    Node *node = makeNode();
    initEntry(node->entry, key, value);
    if (root == NULL) {
    }
  }

  void removeNode(Node *root, char *key) {}

  // Assumes no duplicates
  VAL_T searchNode(Node *root, char *key) {
    if (root == NULL) {
      return -1;
    }
    if (root->entry->key == key) {
      return root->entry->val;
    }
    VAL_T left = searchNode(root->left, key);
    if (left != -1) {
      return left;
    }
    return searchNode(root->right, key);
  }

  // Traversal
  void PreorderTraversal(Node *root) {
    if (root == NULL) {
      return;
    }
    // Root, left, right
    printf("<%s, %d> ", root->entry->key, root->entry->val);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
  }

  void InorderTraversal(Node *root) {
    if (root == NULL) {
      return;
    }
    // left, Root, right
    InorderTraversal(root->left);
    printf("<%s, %d> ", root->entry->key, root->entry->val);
    InorderTraversal(root->right);
  }

  void PostorderTraversal(Node *root) {
    if (root == NULL) {
      return;
    }
    // left, right, Root
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("<%s, %d> ", root->entry->key, root->entry->val);
  }
};
