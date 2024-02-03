// TC - O(N)
// SC - O(1)

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

Node *reverseDLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *prev = NULL;
  Node *current = head;

  while (current != NULL) { // Swapping pointers
    prev = current->back;
    current->back = current->next;
    current->next = prev;

    current = current->back; // Since pointers are swapped
  }
  return prev->back;
}

int main() {
  vector<int> arr = {6, 12, 3, 4, 5};
  Node *head = convertArrTo2DLL(arr);
  head = reverseDLL(head);
  print(head);
  return 0;
}