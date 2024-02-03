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

bool detectLoopBruteForce(Node *head) {
  Node *temp = head;
  // Create a map to keep track of encountered nodes
  unordered_map<Node *, int> nodeMap;

  while (temp != NULL) {
    // If the node is already in the map, there is a loop
    if (nodeMap.find(temp) != nodeMap.end()) {
      return true;
    }
    // Store the current node in the map
    nodeMap[temp] = 1;
    temp = temp->next;
  }
  return false;
}

// TC - O(N)
// SC - O(1)
bool detectLoopInLL(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return true;
    }
  }
  return false;
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

  if (detectLoopInLL(head)) {
    cout << "Loop detected in the linked list." << endl;
  } else {
    cout << "No loop detected in the linked list." << endl;
  }
  return 0;
}