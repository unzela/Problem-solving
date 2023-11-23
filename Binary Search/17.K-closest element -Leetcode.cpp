//  Given an arr, two int k and x, return the k closest integers to x in array.
//  Result should also be sorted in asc order

#include <iostream>
#include <vector>
using namespace std;

// 2 Pointer approach
// TC - O(n-k)
// SC - O(k)
vector<int> closestElements2Pointer(vector<int> &arr, int k, int x) {
  vector<int> ans;
  int low = 0;
  int high = arr.size() - 1;

  while (high - low >= k) {
    if (x - arr[low] > arr[high] - x) {
      low++;
    } else {
      high--;
    }
  }

  for (int i = low; i <= high; i++) {
    ans.push_back(arr[i]);
  }
  return ans;

  // return vector<int>(arr.begin() + low, arr.begin() + high + 1); // To reduce
  // space complexity by not creating another ans vector
}

int lowerbound(vector<int> &arr, int x) {
  int ans = -1;
  int end = arr.size() - 1;
  // int start = 0;
  int start = end; // End is closest if x> the largest element of arr
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] >= x) {
      ans = mid;
      end = mid - 1;
    } else if (x > arr[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}

vector<int> binarySearch_Method(vector<int> &arr, int k, int x) {
  int high = lowerbound(arr, x);
  int low = high - 1;
  while (k--) {
    if (low < 0) {
      high++;
    } else if (high >= arr.size()) {
      low--;
    } else if (x - arr[low] > arr[high] - x) {
      high++;
    } else {
      low--;
    }
  }
  return vector<int>(arr.begin() + low + 1, arr.begin() + high);
}

int main() {
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
  int k = 4;
  int x = 3;

  // vector<int> result = closestElements(arr, k, x);
  vector<int> result = binarySearch_Method(arr, k, x);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}