// TC - O(1)
// SC - O(N)

#include <iostream>
#include <limits.h>
#include <stack>
using namespace std;

// Modified value is always less than min value because
// ie always st.top() < min
class MinStack {
  stack<long long> st;
  long long min;

public:
  MinStack() {
    while (st.empty() == false) { // not necessary
      st.pop();
    }
    min = INT_MAX;
  }

  // Push modified value = (2*val to be pushed - min value)

  // val < min
  // val-min <0
  // val+val-min < 0+val
  // 2*val-min < val => Formula
  // Modified val < min
  void push(int value) {
    long long val = value;
    if (st.empty()) {
      min = val;
      st.push(val);
    } else {
      if (val < min) {
        st.push(2 * val * 1LL - min);
        min = val;
      } else {
        st.push(val);
      }
    }
  }

  // While element to be popped out is modified value, then update/remove min
  // using formula =
  //((2 * current min value) - value to be popped)

  // min = (2 * min)-st.top)
  // min = (2 * min)-(2*val-prevMin)
  // min = (2 * min)-(2*min-prevMin)
  // min = prevMin
  void pop() {
    if (st.empty()) {
      return;
    }
    long long el = st.top();
    st.pop();

    if (el < min) {
      min = 2 * min - el;
    }
  }

  // If top has (modified value < min value), then return min value
  int top() {
    if (st.empty()) {
      return -1;
    }
    long long el = st.top();
    if (el < min) {
      return min;
    }
    return el;
  }

  int getMin() { return min; }
};

int main() {
  MinStack minStack;

  minStack.push(-2);
  minStack.push(0);
  cout << "Min: " << minStack.getMin() << endl;

  minStack.push(-3);
  minStack.pop();
  cout << "Min: " << minStack.getMin() << endl;
  minStack.push(1);
  cout << "Min: " << minStack.getMin() << endl;

  minStack.pop();
  cout << "Top: " << minStack.top() << endl;
  cout << "Min: " << minStack.getMin() << endl;
  return 0;
}