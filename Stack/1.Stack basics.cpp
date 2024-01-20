#include <iostream>
#include <stack>
using namespace std;

class Stack {
public:
  int top;
  int *arr;
  int size;

  Stack(int size) {
    arr = new int[size];
    this->size = size;
    top = -1;
  }

  void push(int data) {
    if (size - top > 1) { // Space available
      top++;
      arr[top] = data;
    } else
      cout << "Stack Overflow" << endl;
  }

  void pop() {
    if (top == -1) {
      cout << "Stack Underflow, cant delete element" << endl;
    } else
      top--;
  }

  int getTop() {
    if (top == -1) {
      cout << "There is no element in the stack" << endl;
      return ' ';
    } else
      return arr[top];
  }

  int getSize() { return top + 1; }

  int isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
};

int main() {
  // STL
  //  Creation
  stack<int> st;

  // Insertion
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  // Remove
  st.pop();

  // Check element at top
  cout << "Element on top is: " << st.top() << endl;

  // Size of stack
  cout << "Size of Stack is : " << st.size() << endl;

  // Check if stack is empty
  if (st.empty())
    cout << "Stack is empty" << endl;
  else
    cout << "Stack is not empty" << endl;

  // Printing elements of stack
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl << endl << endl;

  Stack s(10);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);

  while (!s.isEmpty()) {
    cout << s.getTop() << " ";
    s.pop();
  }

  cout << endl << "Size of stack " << s.getSize() << endl;
  return 0;
}