// TC - O(1)
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

void printList(Node *head) { // Function to print the LinkedList
  Node *curr = head;
  for (; curr != nullptr; curr = curr->next) {
    cout << curr->data << " ";
    // cout << "null" << endl;
  }
}

Node *insertAtBeginning(int value, Node *head) {
  Node *newNode = new Node(value);
  newNode->next = head;

  // Making the newly created Node as head
  head = newNode;
  return head;
}

int main() {
  vector<int> arr = {12, 5, 8, 7};
  Node *head = new Node(arr[0]);
  head->next = new Node(arr[1]);
  head->next->next = new Node(arr[2]);
  head->next->next->next = new Node(arr[3]);

  cout << "Linked List before inserting 0 at beginning : " << endl;
  printList(head);
  head = insertAtBeginning(0, head);
  cout << endl << "Linked List after inserting 0 at beginning : " << endl;
  printList(head);

  return 0;
}