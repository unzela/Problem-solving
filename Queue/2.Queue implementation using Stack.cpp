// Push(x)
//   add x to inputStack
// Pop()
//   if (outputStack is not empty)
//   outputStack.pop()
//     else
//   Move all inputStack elements to outputStack
//   outputStack.pop()
// Top()
//   if (outputStack is not empty)
//   outputStack.pop()
// else
//   Move all inputStack elements to outputStack
// outputStack.pop()

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
  stack<int> input, output;
  MyQueue() {}

  void push(int x) {
    cout << "The element pushed is " << x << endl;
    input.push(x);
  }

  int pop() {
    // shift input to output
    if (output.empty())
      while (input.size()) {
        output.push(input.top());
        input.pop();
      }

    int x = output.top();
    output.pop();
    return x;
  }

  int top() {
    // shift input to output
    if (output.empty())
      while (input.size()) {
        output.push(input.top());
        input.pop();
      }
    return output.top();
  }

  int size() { return (output.size() + input.size()); }
};
int main() {
  MyQueue q;
  q.push(3);
  q.push(4);
  cout << "The element poped is " << q.pop() << endl;
  q.push(5);
  cout << "The top of the queue is " << q.top() << endl;
  cout << "The size of the queue is " << q.size() << endl;
}