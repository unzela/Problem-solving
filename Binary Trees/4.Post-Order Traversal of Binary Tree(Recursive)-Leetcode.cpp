// Order - left, right, root

// TC- O(N) :We are traversing N nodes and every node is visited exactly once
// SC- O(N) :Space is needed for the recursion stack.
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

void postOrderTraversal(Node *curr, vector<int> &postOrder) {
  if (curr == NULL)
    return;

  postOrderTraversal(curr->left, postOrder);
  postOrderTraversal(curr->right, postOrder);
  postOrder.push_back(curr->data);
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

  vector<int> postOrder;
  postOrderTraversal(root, postOrder);

  cout << "The postOrder Traversal is : ";
  for (int i = 0; i < postOrder.size(); i++) {
    cout << postOrder[i] << " ";
  }
  return 0;
}