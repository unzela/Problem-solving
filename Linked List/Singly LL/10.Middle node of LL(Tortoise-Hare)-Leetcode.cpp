// Given the head of a singly linked list, return the middle node of the linked
// list. If there are two middle nodes, return the second middle node.

// TC-O(N/2)=O(N)
// SC-O(1)
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

  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }
};

Node *convertArrToLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *current = head;

  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr);
    current->next = temp;
    current = current->next; // current=temp
  }
  return head;
}

void printLL(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}

Node *middleNodeNaiveApproach(Node *head) { // TC - O(N)+O(N/2)
  Node *temp = head;
  int count = 0;

  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  temp = head;

  for (int i = 0; i < count / 2; i++) {
    temp = temp->next;
  }
  return temp;
}

Node *middleNode(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  Node *head = convertArrToLL(arr);
  // head = middleNodeNaiveApproach(head);
  head = middleNode(head);
  printLL(head);
  return 0;
}