// Given an array of distinct integers. The task is to count all the triplets
// such that sum of two elements equals the third element.

// TC - O(n^2)
// Also solve by Hashing
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int countTriplets(vector<int> &arr) {
  int count = 0;
  sort(arr.begin(), arr.end()); // nlogn

  for (int i = arr.size() - 1; i >= 2; i--) { // n times
    int left = 0;
    int right = i - 1;

    while (left < right) { // n times
      if (arr[left] + arr[right] == arr[i]) {
        count++;
        left++;
        right--;
      } else if (arr[left] + arr[right] < arr[i]) {
        left++;
      } else {
        right++;
      }
    }
  }
  return count;
}

int main() {
  vector<int> arr{1, 2, 3, 4, 5};
  int ans = countTriplets(arr);
  cout << ans;

  return 0;
}
