#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findNearestSmallerElement(const vector<int> &A) {
  int n = A.size();
  vector<int> result(n, -1);
  stack<int> s;

  for (int i = 0; i < n; ++i) {
    // Pop elements from the stack while they are greater than the current
    // element
    while (!s.empty() && A[s.top()] >= A[i]) {
      s.pop();
    }

    // If there is a smaller element, update the result array
    if (!s.empty()) {
      result[i] = A[s.top()];
    }

    // Push the current index onto the stack
    s.push(i);
  }

  return result;
}

int main() {
  vector<int> A = {4, 5, 2, 10, 8};
  vector<int> result = findNearestSmallerElement(A);

  cout << "Nearest smaller elements are: ";
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}
