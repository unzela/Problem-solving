// You are given a sorted array arr of distinct values and a target value x. You
// need to search for the index of the target value in the array

#include <iostream>
#include <vector>
using namespace std;

int searchInsertPosition(vector<int> arr, int x) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = n; // If such index is not found, then return n ie size of array

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= x) { // Maybe an ans
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {2, 3, 5, 7, 9};
  cout << searchInsertPosition(arr, 6);
  return 0;
}