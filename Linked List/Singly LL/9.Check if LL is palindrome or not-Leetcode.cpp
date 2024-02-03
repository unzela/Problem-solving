// Given the head of a singly linked list, return true if it is a palindrome or
// false otherwise.

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

void printLinkedList(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// TC-O(2N)
// SC-O(N)
bool isPalindromeBruteForce(Node *head) {
  stack<int> st;
  Node *temp = head;

  while (temp != NULL) {
    st.push(temp->data);
    temp = temp->next;
  }
  temp = head; // Reset the temp pointer

  while (temp != NULL) {
    if (temp->data != st.top()) {
      return false;
    }

    st.pop();
    temp = temp->next;
  }
  return true;
}

Node *reverseLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;
  return newHead;
}

// TC- O(N/2 + N/2 + N/2 + N/2)= O(N)
// sc-O(1)
bool isPalindrome(Node *head) {
  if (head == NULL || head->next == NULL) {
    return true;
  }

  Node *slow = head;
  Node *fast = head;

  // To divide it into 2 LL
  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node *newHead = reverseLL(slow->next); // Reverse 2nd half of LL
  Node *first = head;
  Node *second = newHead; // Head of reversed 2nd half of LL

  while (second != NULL) {
    if (first->data != second->data) {
      reverseLL(newHead); // Reverse the LL back to original state
      return false;
    }
    first = first->next;
    second = second->next;
  }
  reverseLL(newHead);
  return true;
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(5);
  head->next->next = new Node(2);
  head->next->next->next = new Node(5);
  head->next->next->next->next = new Node(1);
  printLinkedList(head);

  if (isPalindrome(head)) {
    cout << "The linked list is a palindrome." << endl;
  } else {
    cout << "The linked list is not a palindrome." << endl;
  }

  return 0;
}