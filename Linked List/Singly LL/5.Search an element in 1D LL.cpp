// TC - O(N)
// SC - O(1)
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

int searchInLL(Node *head, int value) {
  Node *temp = head;
  while (temp != nullptr) {
    if (temp->data == value) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int main() {
  vector<int> arr = {12, 5, 8, 7};
  Node *head = new Node(arr[0]);
  head->next = new Node(arr[1]);
  head->next->next = new Node(arr[2]);
  head->next->next->next = new Node(arr[3]);

  int value = 5;
  cout << searchInLL(head, value);

  return 0;
}