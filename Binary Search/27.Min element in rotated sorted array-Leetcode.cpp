#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int findMin(vector<int> arr) {
  int low = 0;
  int high = arr.size() - 1;
  int ans = INT_MAX;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    // search space is already sorted then arr[low] will always be
    // the min in that search space: (To improve TC)
    // if (arr[low] <= arr[high]) {
    //   ans = min(ans, arr[low]);
    //   break;
    // }

    if (arr[low] <= arr[mid]) { // Left half is sorted
      ans = min(ans, arr[low]); // Store the minimum value
      low = mid + 1;
    } else {
      high = mid - 1;
      ans = min(ans, arr[mid]);
      // If right side is sorted then mid will be smallest
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {7, 8, 2, 2, 3, 3, 3, 4, 5, 6};
  cout << findMin(arr);

  return 0;
}