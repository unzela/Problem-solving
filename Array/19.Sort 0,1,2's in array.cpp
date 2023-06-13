#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr{2, 2, 0, 1, 1, 2, 2, 2, 0, 1};

  // sort(arr.begin(), arr.end()); // Inbuilt function

  // Count method
  // int zeros, ones, twos;
  // zeros = ones = twos = 0;

  // for (int i = 0; i < arr.size(); i++) {
  //   if (arr[i] == 0)
  //     zeros++;
  //   else if (arr[i] == 1)
  //     ones++;
  //   else
  //     twos++;
  // }

  // // Spread then back in array
  // int i = 0;
  // while (zeros--) {
  //   arr[i] = 0;
  //   i++;
  // }
  // while (ones--) {
  //   arr[i] = 1;
  //   i++;
  // }
  // while (twos--) {
  //   arr[i] = 2;
  //   i++;
  // }

  // In place shuffling method - 3 pointer approach
  int start = 0, i = 0;
  int end = arr.size() - 1;

  // for (int i = 0; i < arr.size(); i++) {
  while (i <= end) {
    if (arr[i] == 0) {
      swap(arr[start], arr[i]);
      start++;
      i++;
    } else if (arr[i] == 1) {
      i++;
    } else {
      swap(arr[i], arr[end]);
      end--;
    }
  }
  //}

  for (auto val : arr) {
    cout << val << " ";
  }

  return 0;
}
