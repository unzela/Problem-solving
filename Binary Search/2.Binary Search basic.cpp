#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2; // To solve integer overflow issue

  while (start <= end) {
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return -1;
}

int main() {
  vector<int> arr{2, 3, 5, 7};
  int target = 5;

  int ans = binarySearch(arr, target);
  if (ans == -1)
    cout << "Not Found";
  else
    cout << "Found at index " << ans;

  return 0;
}