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

void printLinkedList(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
}

Node *deleteFromEnd(Node *head) {
  // If the list is empty or has only one node, return NULL
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  Node *temp = head; // Initialize a temp pointer to traverse the list
  // Traverse to the second last node in the list
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  delete temp->next;

  // Set the next of the second last node to nullptr, effectively removing the
  // last node
  temp->next = nullptr;

  return head;
}

int main() {
  vector<int> arr = {12, 5, 8, 7};
  Node *head = new Node(arr[0]);
  head->next = new Node(arr[1]);
  head->next->next = new Node(arr[2]);
  head->next->next->next = new Node(arr[3]);
  head = deleteFromEnd(head);
  printLinkedList(head);
  ;
}