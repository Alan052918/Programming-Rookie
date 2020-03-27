#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

Node* CreateNode(int data);

// Depth-first search of binary tree
// ----------------------------------------------------------------------------
void PreorderTraversal(Node* node);

void InorderTraversal(Node* node);

void PostorderTraversal(Node* node);
// ----------------------------------------------------------------------------
#endif  // BINARY_TREE_H_
