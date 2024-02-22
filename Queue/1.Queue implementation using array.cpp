#include <iostream>
#include <queue>
using namespace std;

class Queue {
  int *arr;
  int front, rear, currSize, maxSize;

public:
  Queue() {
    front = -1;
    rear = -1;
    currSize = 0;
    arr = new int[16];
  }

  Queue(int maxSize) {
    front = -1;
    rear = -1;
    currSize = 0;
    (*this).maxSize = maxSize;
    arr = new int[maxSize];
  }

  void push(int newElement) {
    if (currSize == maxSize) {
      cout << "Queue is full" << endl;
      exit(1);
    }
    if (rear == -1) {
      front = 0;
      rear = 0;
    } else {
      rear = (rear + 1) % maxSize; //(rear++)%maxSize
      // Keep moving rear even if its at the end of the array
    }
    arr[rear] = newElement;
    cout << "The element pushed is " << newElement << endl;
    currSize++;
  }

  int pop() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
    }
    int popped = arr[front];
    if (currSize == 1) {
      front = -1;
      rear = -1;
    } else {
      front = (front + 1) % maxSize; //% for circular
    }
    currSize--;
    return popped;
  }

  int top() {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      exit(1);
    }
    return arr[front];
  }

  int size() { return currSize; }
};

int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);

  cout << "The peek of the queue before deleting any element " << q.top()
       << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size()
       << endl;

  return 0;
}