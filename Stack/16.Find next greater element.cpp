#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findNextLargestElement(const vector<int> &Arr) {
  int n = Arr.size();
  vector<int> result(n);
  stack<int> s;

  for (int i = 0; i < n; i++) {
    while (!s.empty() && Arr[s.top()] <= Arr[i]) {
        int v = s.top();
        result[v] = Arr[i];
        s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    result[s.top()] = -1;
    s.pop();
  }
  return result;
}

int main() {
  vector<int> A = {4, 5, 2, 10, 8};
  vector<int> result = findNextLargestElement(A);

  cout << "Next largest elements are: ";
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}
