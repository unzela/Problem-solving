// Given an unsorted array A of size N that contains only positive integers,
// find a continuous sub-array that adds to a given number S and return the left
// and right index(1-based indexing) of that subarray.

// TC - O(n)
#include <iostream>
#include <vector>
using namespace std;

vector<int> subArrayGivenSum(vector<int> &arr, int n, int s) {
  int left = 0;
  int right = 0;
  bool isFound = false;
  vector<int> ans;
  int sum = arr[0];

  if (s == 0) {
    ans.push_back(-1);
    return ans;
  }

  while (right < n) {
    if (sum == s) {
      isFound = true;
      break;
    } else if (sum < s) {
      right++;
      if (right < n)
        sum += arr[right];
    } else {
      sum -= arr[left];
      left++;
    }
  }
  if (isFound) {
    ans.push_back(left + 1);
    ans.push_back(right + 1);
    return ans;
  } else {
    ans.push_back(-1);
    return ans;
  }
}

int main() {
  vector<int> arr{1, 2, 4, 6, 7, 8};
  int n = arr.size();
  int s = 12;
  vector<int> result = subArrayGivenSum(arr, n, s);

  for (int i : result) {
    cout << i << " ";
  }
  return 0;
}