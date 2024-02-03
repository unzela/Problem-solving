#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *back;

  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }

  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *convertArrTo2DLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;

  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = prev->next; // or prev = temp;
  }
  return head;
}

void print(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node *insertBeforeHead(Node *head, int value) {
  Node *newHead = new Node(value, head, nullptr);
  head->back = newHead;
  return newHead;
}

Node *insertAtEndOfDLL(Node *head, int value) {
  if (head == NULL) { // Single element
    return new Node(value);
  }
  Node *tail = head;
  while (tail->next != NULL) { // To find tail
    tail = tail->next;
  }

  Node *newNode = new Node(value, nullptr, tail);

  tail->next = newNode;
  return head;
}

Node *insertBeforeTail(Node *head, int value) {
  if (head->next == NULL) { // Single element
    return insertBeforeHead(head, value);
  }
  Node *tail = head;
  while (tail->next != NULL) { // To find tail
    tail = tail->next;
  }

  Node *prev = tail->back;
  Node *newNode = new Node(value, tail, prev);

  prev->next = newNode;
  tail->back = newNode;

  return head;
}

Node *insertBeforeKthElement(Node *head, int k, int value) {
  if (k == 1) {
    return insertBeforeHead(head, value);
  }

  Node *temp = head;
  int count = 0;

  while (temp != NULL) {
    count++;
    if (count == k) {
      break;
    }
    temp = temp->next;
  }

  Node *prev = temp->back;
  Node *newNode = new Node(value, temp, prev);

  prev->next = newNode;
  temp->back = newNode;
  return head;
}

void insertBeforeNode(Node *node, int value) {
  Node *prev = node->back;
  Node *newNode = new Node(value, node, prev);
  prev->next = newNode;
  node->back = newNode;
}

int main() {
  vector<int> arr = {6, 12, 3, 4, 5};
  Node *head = convertArrTo2DLL(arr);
  // head = insertBeforeHead(head, 10);
  // head = insertBeforeTail(head, 8);
  // head = insertBeforeKthElement(head, 4, 8);
  head = insertAtEndOfDLL(head, 22);
  insertBeforeNode(head->next->next, 20);
  print(head);
  return 0;
}