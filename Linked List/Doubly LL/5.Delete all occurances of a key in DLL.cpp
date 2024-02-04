// TC-O(N)
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

void print(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

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

Node *deleteAllOccurancesOfAKey(Node *head, int key) {
  Node *temp = head;
  while (temp != NULL) {
    if (temp->data == key) {
      // If key is head, then post deletion it'll be updated
      if (temp == head) {
        head = temp->next;
      }
      Node *nextNode = temp->next;
      Node *prevNode = temp->prev;

      if (nextNode != NULL) {
        nextNode->prev = prevNode;
      }
      if (prevNode != NULL) {
        prevNode->next = nextNode;
      }

      free(temp);
      temp = nextNode;
    } else {
      temp = temp->next;
    }
  }
  return head;
}

int main() {
  vector<int> arr = {3, 6, 3, 12, 3, 4, 5};
  Node *head = convertArrTo2DLL(arr);
  head = deleteAllOccurancesOfAKey(head, 3);
  print(head);
  return 0;
}