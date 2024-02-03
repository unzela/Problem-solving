#include <iostream>
#include <vector>
using namespace std;

// TC- O(logN)
// SC- O(1)
int searchInRotatedSortedArray(vector<int> arr, int n, int target) {
  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
      return mid;
    }

    // if left part is sorted
    if (arr[low] <= arr[mid]) {
      if (arr[low] <= target && target <= arr[mid]) {
        high = mid - 1; // element exists:
      } else {
        low = mid + 1; // element does not exist
      }
    }
    // if right part is sorted
    else {
      if (arr[mid] <= target && target <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return -1;
}

// TC- O(logN) for the best and average case. O(N/2) for the worst case.
bool searchInARotatedSortedArrayWithDuplicates(vector<int> &arr, int target) {
  int n = arr.size();
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == target)
      return true;

    // Edge case: if duplicates exist at ends, then shrink the search space
    if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
      low = low + 1;
      high = high - 1;
      continue; // If next element is also duplicate
    }

    // if left part is sorted:
    if (arr[low] <= arr[mid]) {
      if (arr[low] <= target && target <= arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else { // if right part is sorted:
      if (arr[mid] <= target && target <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return false;
}

int main() {
  vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  int n = 9, target = 1;
  int ans = searchInRotatedSortedArray(arr, n, target);
  if (ans == -1)
    cout << "Target is not present.\n";
  else
    cout << "The index is: " << ans << "\n";

  vector<int> arr1 = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
  int k = 3;
  bool ans1 = searchInARotatedSortedArrayWithDuplicates(arr, k);
  if (!ans1)
    cout << "Target is not present.\n";
  else
    cout << "Target is present in the array.\n";
  return 0;

  return 0;
}