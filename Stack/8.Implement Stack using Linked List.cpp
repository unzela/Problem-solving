// We can assume our linked list to be a horizontal stack where the operations
// like deletion and insertion would take place at the top of the stack or at
// the head of the linked list.

// To perform all the operations our head of the linked list would act as the
// topof the stack.

#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  int size;

  Node(int value) {
    data = value;
    next = NULL;
  }
};

class Stack {
public:
  Node *top;
  int size;
  Stack() {
    top = NULL;
    size = 0;
  }

  void push(int x) {
    Node *newNode = new Node(x);
    newNode->next = top;
    top = newNode;
    cout << "Element pushed" << endl;
    size++;
  }

  int pop() {
    if (top == NULL) {
      return -1;
    }
    Node *temp = top;
    int topData = top->data;
    top = top->next;
    delete temp;
    size--;
    return topData;
  }

  int stackSize() { return size; }

  bool stackIsEmpty() { return top == NULL; }

  int topElement() {
    if (top == NULL) {
      return -1;
    }
    return top->data;
  }

  void print() {
    Node *current = top;
    while (current != NULL) {
      cout << current->data << " ";
      current = current->next;
    }
  }
};

int main() {
  Stack s;

  s.push(10);
  s.push(1);
  s.push(20);
  s.push(30);
  s.push(40);
  cout << "Element popped: " << s.pop() << "\n";
  cout << "Stack size: " << s.stackSize() << "\n";
  cout << "Stack empty or not? " << s.stackIsEmpty() << "\n";
  cout << "stack's top element: " << s.topElement() << "\n";
  s.print();
  return 0;
}