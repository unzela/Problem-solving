// Given the head of a singly linked list, write a program to reverse the linked
// list, and return the head pointer to the reversed list.

#include <iostream>
#include <stack>
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

// TC - O(2N)
// SC - O(N)
Node *reverseLLBruteForce(Node *head) {
  Node *temp = head;
  stack<int> st;

  // Push the values of the linked list onto the stack
  while (temp != NULL) {
    st.push(temp->data);
    temp = temp->next;
  }

  temp = head; // Reset the temp pointer to head of linked list

  // Pop values from the stack and update the linked list
  while (temp != NULL) {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

// Iterative Approach
// TC - O(N)
// SC - O(1)
Node *reverseLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *prev = NULL;
  Node *temp = head;

  while (temp != NULL) {
    Node *front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

// Recursive Approach
// TC - O(N)
// SC - O(N)
Node *reverseLLRecursion(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // newHead is head of reversed LL
  Node *newHead = reverseLLRecursion(head->next);
  Node *front = head->next;
  front->next = head; // Reverse the pointer of head's next node
  head->next = NULL;
  return newHead;
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(3);
  head->next->next = new Node(2);
  head->next->next->next = new Node(4);
  // head = reverseLLBruteForce(head);
  // head = reverseLL(head);
  head = reverseLLRecursion(head);
  print(head);
  return 0;
}