#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> arr) {
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

int main() {
  vector<int> arr{2, 4, 10, 11, 7, 5, 3};
  int ans = findPeakElement(arr);
  cout << "Peak Element is at index " << ans << " and the element is "
       << arr[ans];
  return 0;
}