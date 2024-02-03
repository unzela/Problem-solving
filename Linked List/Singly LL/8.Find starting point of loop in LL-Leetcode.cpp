// Given head, the head of a linked list, determine if the linked list has a
// cycle in it.
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

void print(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// TC - O(N)
// SC - O(1)
Node *startingPointOfLoopInLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  Node *slow = head;
  Node *fast = head;
  Node *entry = head;

  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {       // Loop found
      while (slow != entry) { // If slow and entry intersect, entry found
        slow = slow->next;
        entry = entry->next;
      }
      return slow; // Or entry
    }
  }
  return NULL;
}

int main() {
  Node *head = new Node(1);
  Node *second = new Node(2);
  Node *third = new Node(3);
  Node *fourth = new Node(4);
  Node *fifth = new Node(5);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  // Create a loop
  fifth->next = third;

  Node *loopStart = startingPointOfLoopInLL(head);
  if (loopStart != NULL) {
    cout << "Loop starts at: " << loopStart->data << endl;
  } else {
    cout << "No loop found" << endl;
  }

  return 0;
}