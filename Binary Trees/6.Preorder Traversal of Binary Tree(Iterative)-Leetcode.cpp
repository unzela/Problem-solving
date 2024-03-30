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

// We first push the right child of this popped node and then push the left
// child, because stack is a LIFO. We need to access the left child first, so we
// need to push it at the last.

vector<int> preOrderTrav(Node *root) {
  vector<int> preOrder;

  if (root == NULL)
    return preOrder;

  stack<Node *> s;
  s.push(root);

  while (!s.empty()) {
    Node *topNode = s.top();
    preOrder.push_back(topNode->data);
    s.pop();

    if (topNode->right != NULL)
      s.push(topNode->right);

    if (topNode->left != NULL)
      s.push(topNode->left);
  }
  return preOrder;
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
  preOrder = preOrderTrav(root);

  cout << "The preOrder Traversal is : ";
  for (int i = 0; i < preOrder.size(); i++) {
    cout << preOrder[i] << " ";
  }
  return 0;
}