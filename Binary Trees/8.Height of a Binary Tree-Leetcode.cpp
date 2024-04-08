// TC- O(N)
// SC- O(N)
#include <iostream>
#include <stack>
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

int maxHeightOfBinaryTree(Node *root) {
  if (root == NULL)
    return 0;

  int lh = maxHeightOfBinaryTree(root->left);
  int rh = maxHeightOfBinaryTree(root->right);

  return 1 + max(lh, rh);
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

  int maxHeight = maxHeightOfBinaryTree(root);
  cout << "Max Height Of Binary Tree is :" << maxHeight;

  return 0;
}