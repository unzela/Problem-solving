// Order - left, root, right

// TC- O(N) :We are traversing N nodes and every node is visited exactly once
// SC- O(N) :Space is needed for the recursion stack. In worst case (skewed
// tree), SC can be O(N).
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

void inOrderTraversal(Node *curr, vector<int> &inOrder) {
  if (curr == NULL)
    return;

  inOrderTraversal(curr->left, inOrder);
  inOrder.push_back(curr->data);
  inOrderTraversal(curr->right, inOrder);
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

  vector<int> inOrder;
  inOrderTraversal(root, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
  return 0;
}