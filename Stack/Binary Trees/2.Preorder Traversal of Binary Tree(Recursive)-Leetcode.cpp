// Order - root, left, right

// TC- O(N) :We are traversing N nodes and every node is visited exactly once
// SC- O(N) :Space is needed for the recursion stack
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node *newNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void preOrderTraversal(Node *curr, vector<int> &preOrder) {
  if (curr == NULL)
    return;

  preOrder.push_back(curr->data);
  preOrderTraversal(curr->left, preOrder);
  preOrderTraversal(curr->right, preOrder);
}

int main() {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(8);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->right->left = newNode(9);
  root->right->right->right = newNode(10);

  vector<int> preOrder;
  preOrderTraversal(root, preOrder);

  cout << "The preOrder Traversal is : ";
  for (int i = 0; i < preOrder.size(); i++) {
    cout << preOrder[i] << " ";
  }
  return 0;
}