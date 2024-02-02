#include <iostream>
#include <vector>
using namespace std;

int findPeakElement1(vector<int> arr) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  // Peak element is middle element - own
  while (start < end) {
    if (arr[mid] < arr[mid + 1]) { // It is on line A, so Search right side
      start = mid + 1;
    } else {
      start = mid;
    }
  }
  return start; // Or return end as start==end
}


int findPeakElement(vector<int> &arr) {
    int n = arr.size();

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
  return -1;
}

int main() {
  vector<int> arr{2, 4, 10, 11, 7, 5, 3};
  int ans = findPeakElement(arr);
  cout << "Peak Element is at index " << ans << " and the element is "
       << arr[ans];
  return 0;
}