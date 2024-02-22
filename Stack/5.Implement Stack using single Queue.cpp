// SC-O(N)
// TC-O(N)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Stack {
  queue<int> q;

public:
  void push(int x) {
    int s = q.size();
    q.push(x);

    for (int i = 0; i < s; i++) {
      // Take all elements below x from q and push them to on top of q
      q.push(q.front());
      q.pop();
    }
  }

  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }

  int Top() { return q.front(); }

  int Size() { return q.size(); }
};

int main() {
  Stack s;
  s.push(3);
  s.push(2);
  s.push(4);
  s.push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

  return 0;
}
