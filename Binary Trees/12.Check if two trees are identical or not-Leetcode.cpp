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

bool isIdentical(Node *root1, Node *root2) {
  // If both nodes are NULL,they are identical
  if (root1 == NULL && root2 == NULL) {
    return true;
  }
  // If only one of the nodes is NULL, they are not identical
  if (root1 == NULL || root2 == NULL) {
    return false;
  }
  return ((root1->data == root2->data) &&
          isIdentical(root1->left, root2->left) &&
          isIdentical(root1->right, root2->right));
}

int main() {
  Node *root1 = new Node(1);
  root1->left = new Node(2);
  root1->right = new Node(3);
  root1->left->left = new Node(4);

  Node *root2 = new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(3);
  root2->left->left = new Node(4);

  if (isIdentical(root1, root2)) {
    cout << "The binary trees are Identical." << endl;
  } else {
    cout << "The binary trees are not Identical." << endl;
  }

  return 0;
}