#ifndef BST_H
#define BST_H

#define VAL_T char *

typedef struct Entry {
  VAL_T val;
} Entry;

typedef struct Node {
  Entry *entry;
  struct Node *left;
  struct Node *right;
} Node;

#endif  // BST_H
