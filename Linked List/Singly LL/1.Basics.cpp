#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next; // Pointer to the next node in the linked list

  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

Node *convertArrToLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *mover = head;

  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = mover->next; // or mover = temp;
  }
  return head;
}

int lengthOfLL(Node *head) {
  int count = 0;
  Node *temp = head;
  while (temp) {
    temp = temp->next;
    count++;
  }
  return count;
}

int searchInLL(Node *head, int value) {
  Node *temp = head;
  while (temp) {
    if (temp->data == value) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int main() {
  // Creating a Linked List
  vector<int> arr = {6, 12, 3, 4, 5};
  Node *y = new Node(arr[0]);
  cout << y << endl;       // returns the memory value
  cout << y->data << endl; // returns the data stored at that memory point

  Node *head = convertArrToLL(arr);
  cout << head->data << endl;

  // Traveral in LL - O(N)
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;

  // Length of LL - O(N)
  cout << "Length of LL :" << lengthOfLL(head) << endl;

  // Search in LL - O(N) best case O(1)
  cout << "Searching in LL :" << searchInLL(head, 5) << endl;
}