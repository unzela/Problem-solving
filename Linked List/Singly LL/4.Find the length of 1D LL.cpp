// TC - O(N)
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

int lengthOfLL(Node *head) {
  int count = 0;
  Node *temp = head;
  while (temp != NULL) {
    temp = temp->next;
    count++;
  }
  return count;
}

int main() {
  vector<int> arr = {12, 5, 8, 7};
  Node *head = new Node(arr[0]);
  head->next = new Node(arr[1]);
  head->next->next = new Node(arr[2]);
  head->next->next->next = new Node(arr[3]);

  cout << lengthOfLL(head);

  return 0;
}