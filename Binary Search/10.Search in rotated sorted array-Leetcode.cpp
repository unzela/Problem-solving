// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/901285996/

// TC - O(log n)
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target, int start, int end) {

  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return -1;
}

int findPivot(vector<int> arr) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  while (start < end) {
    if (start == end) // if there is single element in array
      return start;
    else if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
      return mid;
    else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
      return mid - 1;

    else if (arr[start] > arr[mid])
      end = mid - 1;
    else
      start = mid + 1;

    mid = start + (end - start) / 2;
  }
  return -1;
}

int search(vector<int> arr, int target) {
  int pivotIndex = findPivot(arr);

  if (target >= arr[0] && target <= arr[pivotIndex]) {
    // Search in A
    int ans = binarySearch(arr, target, 0, pivotIndex);
    return ans;
  }

  else if (pivotIndex + 1 < arr.size() && target >= arr[pivotIndex + 1] &&
           target <= arr[arr.size() - 1]) {
    // Search in B
    int ans = binarySearch(arr, target, pivotIndex + 1, arr.size() - 1);
    return ans;
  }
  return -1;
}

int main() {
  vector<int> arr{
      5, 6, 1, 2, 3, 4,
  };
  int target = 3;
  int result = search(arr, target);
  cout << "Element found at index " << result;
  return 0;
}