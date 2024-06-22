// TC- O(N)
// SC- O(1)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node *left, *right;

  Node(int data1) {
    data = data1;
    left = NULL;
    right = NULL;
  }
};

int dfsHeight(Node *root) {
  if (root == NULL)
    return 0;

  int leftHeight = dfsHeight(root->left);
  if (leftHeight == -1)
    return -1;

  int rightHeight = dfsHeight(root->right);
  if (rightHeight == -1)
    return -1;

  if (abs(leftHeight - rightHeight) > 1)
    return -1;

  return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root) {
  // Check if the tree's height difference between subtrees is less than 2
  // If not, return false; otherwise, return true
  return dfsHeight(root) != -1;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->right = new Node(6);
  root->left->right->right->right = new Node(7);

  if (isBalanced(root)) {
    cout << "The tree is balanced." << endl;
  } else {
    cout << "The tree is not balanced." << endl;
  }

  return 0;
}