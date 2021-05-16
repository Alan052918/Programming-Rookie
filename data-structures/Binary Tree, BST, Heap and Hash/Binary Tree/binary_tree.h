#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#define VAL_T int

typedef struct Entry {
  std::string key;
  VAL_T val;
} Entry;

typedef struct Node {
  Entry *entry;
  struct Node *left;
  struct Node *right;
} Node;

void initEntry(Entry *, std::string, VAL_T);
Node *makeNode();

#endif  // BINARY_TREE_H_
