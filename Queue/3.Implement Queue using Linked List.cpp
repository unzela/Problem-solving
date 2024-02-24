
// TC-O(1)
// SC-O(1)
#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  int size;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

Node *front = nullptr;
Node *rear = nullptr;

class Queue {
public:
  int size = 0;

  void Enqueue(int x) {
    Node *newNode = new Node(x);
    if (newNode == nullptr) {
      cout << "Queue is full" << endl;
    } else {
      if (front == nullptr) {
        front = newNode;
        rear = newNode;
      } else {
        rear->next = newNode;
        rear = newNode;
      }
      cout << x << " is enqueued" << endl;
      size++;
    }
  }

  void Dequeue() {
    if (front == nullptr)
      cout << "Queue is Empty" << endl;
    else {
      cout << front->data << " Removed from queue" << endl;
      Node *temp = front;
      front = front->next;
      delete temp;
      size--;
    }
  }

  bool empty() { return front == nullptr; }

  int peekElememt() {
    if (empty()) {
      cout << "Queue is empty" << endl;
      return -1;
    }
    return front->data;
  }
};

int main() {
  Queue Q;
  Q.Enqueue(10);
  Q.Enqueue(20);
  Q.Enqueue(30);
  Q.Enqueue(40);
  Q.Enqueue(50);
  Q.Dequeue();
  cout << "The size of the Queue is " << Q.size << endl;
  cout << "The Peek element of the Queue is " << Q.peekElememt() << endl;
  return 0;
}