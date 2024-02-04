// TC-O(2N)
// SC-O(1): To solve the problem and O(n) to store the ans

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data1) {
    data = data1;
    next = nullptr;
    prev = nullptr;
  }

  Node(int data1, Node *next1, Node *prev1) {
    data = data1;
    next = next1;
    prev = prev1;
  }
};

Node *convertArrTo2DLL(vector<int> arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = prev->next; // prev=temp
  }
  return head;
}

Node *findTail(Node *head) { // TC-O(n)
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  return tail;
}

vector<pair<int, int>> findPairs(Node *head, int key) {
  vector<pair<int, int>> ans;
  Node *left = head;
  Node *right = findTail(head);

  if (head == NULL) {
    return ans;
  }

  while (left->data < right->data) { // TC-O(n)
    if (left->data + right->data == key) {
      ans.push_back({left->data, right->data});
      left = left->next;   // Move left pointer to next node
      right = right->prev; // Move right pointer to previous node
    } else if (left->data + right->data < key) {
      left = left->next;
    } else {
      right = right->prev;
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 9};
  Node *head = convertArrTo2DLL(arr);
  vector<pair<int, int>> ans = findPairs(head, 5);
  for (auto i : ans) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}