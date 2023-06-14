// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/900732071/

#include <iostream>
#include <vector>
using namespace std;

void firstAndLastOccurence(vector<int> arr, int target) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;
  vector<int> result;

  while (start <= end) {
    if (arr[mid] == target) {
      ans = mid;
      end = mid - 1;
    } else if (arr[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  result.push_back(ans);

  start = 0;
  end = arr.size() - 1;
  mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] == target) {
      ans = mid;
      start = mid + 1;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  result.push_back(ans);

  for (auto val : result) {
    cout << val << " ";
  }
}

int main() {
  vector<int> arr{1, 4, 6, 6, 6, 6, 8, 9};
  int target = 6;
  firstAndLastOccurence(arr, target);
}