// Dutch National Flag Algorithm - 2 pointer approach

// Time Complexity = o(n)
// Space Complexity = o(1)
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr{-11, 0, -4, 1, 6, -2, 10};

  int start = 0;
  int end = arr.size() - 1;

  while (start < end) {
    if (arr[start] < 0) {
      start++;
    } else if (arr[end] > 0) {
      end--;
    } else {
      swap(arr[start], arr[end]);
    }
  }

  for (auto val : arr) {
    cout << val << " ";
  }

  return 0;
}