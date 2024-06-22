// TC-0(N)
// SC-0(1)
#include <climits>
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

int findMaxPathSum(Node *root, int &maxi) {
  if (root == NULL) {
    return 0;
  }
  int leftPathMax = max(0, findMaxPathSum(root->left, maxi));
  // Return 0 if left sum is negative
  int rightPathMax = max(0, findMaxPathSum(root->right, maxi));

  // Update the overall max path sum including the current node
  maxi = max(maxi, leftPathMax + rightPathMax + root->data);

  // Return the max sum considering only one branch (either left or right) along
  // with the current node
  return root->data + max(leftPathMax, rightPathMax);
}

int maxPathSum(Node *root) {
  int maxi = INT_MIN;
  findMaxPathSum(root, maxi);
  return maxi;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->right = new Node(6);
  root->left->right->right->right = new Node(7);

  int maxPathSumAns = maxPathSum(root);
  cout << "Maximum Path Sum: " << maxPathSumAns << endl;

  return 0;
}