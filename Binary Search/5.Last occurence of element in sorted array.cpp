#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// TC - o(logn)

int lastOccurence(vector<int> arr, int target) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    if (arr[mid] == target) {
      ans = mid;
      start = mid + 1; // right search
    } else if (arr[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}

int upperBound(vector<int> arr, int n, int x) {
  int low = 0;
  int high = n - 1;
  int ans = n; // If such index is not found, then return n ie size of array

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] > x) { // Maybe an ans
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  vector<int> arr{2, 3, 3, 5, 5, 5, 5, 6, 7};
  int target = 5;

  int ans = lastOccurence(arr, target);
  cout << "Last occurence is found at index " << ans << endl;

  // Inbuilt method
  // auto ans2 = upper_bound(arr.begin(), arr.end(), target);
  // cout << "Last occurence is found at index " << ans2 - arr.begin();

  return 0;
}