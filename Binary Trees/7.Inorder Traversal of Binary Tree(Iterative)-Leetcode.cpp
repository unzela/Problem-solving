// TC-O(N)
// SC-O(N)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
  int data;
  struct Node *left, *right;
};

Node *newNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

vector<int> inOrderTrav(Node *curr) {
  vector<int> inOrder;
  stack<Node *> s;

  while (true) {
    if (curr != NULL) {
      s.push(curr);
      curr = curr->left;
    } else {
      if (s.empty())
        break;

      curr = s.top();
      inOrder.push_back(curr->data);
      s.pop();
      curr = curr->right;
    }
  }
  return inOrder;
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
  inOrder = inOrderTrav(root);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
  return 0;
}