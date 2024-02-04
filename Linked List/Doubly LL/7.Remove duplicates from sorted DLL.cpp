// TC-O(N) and not O(N^2) though there are 2 loops
// SC-O(1)

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data1) {
    data = data1;
    next = nullptr;
    prev = nullptr;
  }

  Node(int data1, Node *next1, Node *prev1) {
    data = data1;
    next = next1;
    prev = prev1;
  }
};

Node *convertArrTo2DLL(vector<int> arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = prev->next; // prev=temp
  }
  return head;
}

void print(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node *removeDuplicates(Node *head) {
  Node *temp = head;

  while (temp != NULL && temp->next != NULL) {
    Node *nextNode = temp->next;

    while (nextNode != NULL && temp->data == nextNode->data) {
      Node *duplicate = nextNode;
      nextNode = nextNode->next;
      free(duplicate);
    }
    temp->next = nextNode;

    if (nextNode != NULL) {
      nextNode->prev = temp;
    }
    temp = temp->next;
  }
  return head;
}

int main() {
  vector<int> arr = {1, 2, 2, 2, 2, 3, 3, 3, 4, 9};
  Node *head = convertArrTo2DLL(arr);
  head = removeDuplicates(head);
  print(head);
}