                            
//TC - O(log2N) where N is the number of nodes in the Binary Search Tree
//TC - worst case scenario, where the tree is degenerate (linear), the time complexity becomes O(n)
//SC - O(1)
                            
#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x){
     val = x;
     left = nullptr;
     right = nullptr;
    } 
};

Node* searchBST(Node* root, int val){
    while(root != NULL && root->val != val){
        root = val < root->val ? root->left : root->right;
    }
    return root;
}

void printInOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;
    
    int target = 6;
    Node* result = searchBST(root, target);

    if (result != nullptr) {
        cout << "Value " << target << " found in the BST!" <<endl;
    } else {
        cout << "Value " << target << " not found in the BST." << endl;
    }
    return 0;
}