// Diameter is the longest path between any 2 nodes and it need not passs
// through the root node

// TC-O(N)
// SC-O(1)
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int data1) {
    data = data1;
    left = NULL;
    right = NULL;
  }
};

int height(Node *node, int &diameter) {
  if (!node) {
    return 0;
  }

  int lh = height(node->left, diameter);
  int rh = height(node->right, diameter);

  // Update the diameter with the max of current diameter or sum of left and
  // right heights
  diameter = max(diameter, lh + rh);

  // Return the height of the current node's subtree
  return 1 + max(lh, rh);
}

int diameterOfBinaryTree(Node *root) {
  int diameter = 0;
  height(root, diameter);
  return diameter;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->right = new Node(6);
  root->left->right->right->right = new Node(7);

  int diameter = diameterOfBinaryTree(root);

  cout << "The diameter of the binary tree is: " << diameter << endl;

  return 0;
}