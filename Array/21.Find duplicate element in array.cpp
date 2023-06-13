#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr{1, 2, 3, 4, 3};

  // Method 1
  //  Time Complexity of STL sort = o(n logn)
  //  Space Complexity = o(n)

  //  sort(arr.begin(), arr.end());
  //  for (int i = 0; i < arr.size()-1; i++) {

  //   if (arr[i] == arr[i + 1])
  //     cout << arr[i]; // return arr[i]; incase of function
  // }

  // Negative marking method -2
  //  Time Complexity =o(n)
  // Space Complexity = o(1)

  // int ans = -1;
  // for (int i = 0; i < arr.size(); i++) {
  //   int index = abs(arr[i]);
  //   // Already visited
  //   if (arr[index] < 0) {
  //     ans = index;
  //     break;
  //   }
  //   // Visited mark
  //   arr[index] *= -1;
  // }
  // cout << ans;

  // Positioning method -3
  // Return element at 0th index and place others elements at the same index
  //  Time Complexity =o(n)
  // Space Complexity = o(1)

  while (arr[0] != arr[arr[0]]) {
    swap(arr[0], arr[arr[0]]);
  }
  cout << arr[0];

  return 0;
}