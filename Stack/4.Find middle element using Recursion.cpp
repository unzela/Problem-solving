#include <iostream>
#include <stack>
using namespace std;

void printMiddle(stack<int> &s, int &totalSize) {
  if (s.size() == 0) {
    cout << "There is no element in the Stack" << endl;
  }

  // Base case
  if (s.size() == totalSize / 2 + 1) {
    cout << "Middle element is: " << s.top() << endl;
    return;
  }

  int temp = s.top();
  s.pop();

  // Recursive call
  printMiddle(s, totalSize);

  // Backtrack
  s.push(temp);
}

int main() {
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);

  int totalSize = s.size();
  printMiddle(s, totalSize);
  return 0;
}