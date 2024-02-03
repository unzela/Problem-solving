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

Node *deleteHead(Node *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }
  Node *prev = head;
  head = head->next;

  head->back = nullptr;
  prev->next = nullptr;

  delete prev;
  return head;
}

Node *deleteTail(Node *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }

  Node *prev = tail->back; // Prev is new tail
  prev->next = nullptr;
  tail->back = nullptr;

  delete tail;
  return head;
}

Node *deleteKthNode(Node *head, int k) {
  int count = 0;
  if (head == NULL) {
    return NULL;
  }
  Node *kNode = head;
  while (kNode != NULL) {
    count++;
    if (count == k) { // To find position of kth node
      break;
    }
    kNode = kNode->next;
  }

  Node *prev = kNode->back;
  Node *front = kNode->next;

  if (prev == NULL && front == NULL) { // Single element
    return NULL;
  }
  if (prev == NULL) { // Head
    return deleteHead(head);
  }
  if (front == NULL) { // Tail
    return deleteTail(head);
  }

  prev->next = front;
  front->back = prev;

  kNode->back = nullptr;
  kNode->next = nullptr;

  delete kNode;
  return head;
}

void deleteNode(Node *temp) {
  Node *prev = temp->back;
  Node *front = temp->next;

  if (front == NULL) {
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return;
  }

  prev->next = front;
  front->back = prev;

  temp->back = nullptr;
  temp->next = nullptr;

  free(temp);
}

int main() {
  vector<int> arr = {6, 12, 3, 4, 5};
  Node *head = convertArrTo2DLL(arr);
  // head = deleteHead(head);
  // head = deleteTail(head);
  // head = deleteKthNode(head, 3);
  deleteNode(head->next->next); // 3rd node
  print(head);
  return 0;
}