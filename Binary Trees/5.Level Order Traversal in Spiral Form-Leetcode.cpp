// TC- O(N)
// SC- O(N)
#include <iostream>
#include <queue>
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

vector<vector<int>> levelOrder(Node *root) {
  vector<vector<int>> ans;

  if (root == NULL)
    return ans;

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size(); // No of elements in each level
    vector<int> level;

    for (int i = 0; i < size; i++) { // No of levels
      Node *node = q.front();
      q.pop();

      if (node->left != NULL)
        q.push(node->left);

      if (node->right != NULL)
        q.push(node->right);

      level.push_back(node->data);
    }
    ans.push_back(level);
  }
  return ans;
}

int main() {
  Node *root = newNode(3);
  root->left = newNode(9);
  root->right = newNode(20);
  root->right->left = newNode(15);
  root->right->right = newNode(7);

  vector<vector<int>> result = levelOrder(root);

  cout << "Level Order Traversal: " << endl;
  for (int i = 0; i < result.size(); ++i) {
    cout << "Level " << i + 1 << ": ";
    for (int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  // Deallocating memory
  delete root->right->right;
  delete root->right->left;
  delete root->right;
  delete root->left;
  delete root;

  return 0;
}