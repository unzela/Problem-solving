// Given an array nums and int k, return no of unique k-diff pairs in array ie.e
// nums[i]-muns[j]==k

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 2 pointer approach
int findPairs(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());
  int i = 0, j = 1;
  set<pair<int, int>> ans; // int ans=0; will have duplicate elements

  while (j < nums.size()) {
    int diff = nums[j] - nums[i];
    if (diff == k) {
      ans.insert({nums[i], nums[j]});
      // cout << nums[i] << " " << nums[j];
      i++, j++;
    } else if (diff > k) {
      i++;
    } else {
      j++;
    }
    if (i == j) {
      j++;
    }
  }
  return ans.size();
}

// Method 2 - Binary search
// TC - O(nlog n)
// a[i]+k =x is available then x-a[i] is a pair
int binarySearch(vector<int> &nums, int start, int x) {
  int end = nums.size();
  while (start <= end) {
    int mid = (start + end) / 2;
    if (nums[mid] == x) {
      return mid;
    } else if (x > nums[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

int findPair2(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());
  set<pair<int, int>> ans;

  for (int i = 0; i < nums.size(); i++) {
    if (binarySearch(nums, i + 1, nums[i] + k) != -1) {
      ans.insert({nums[i], nums[i] + k});
    }
  }
  return ans.size();
}

int main() {
  vector<int> arr = {3, 1, 4, 1, 5};
  int k = 2;
  cout << findPairs(arr, k) << endl;
  cout << findPair2(arr, k);
}