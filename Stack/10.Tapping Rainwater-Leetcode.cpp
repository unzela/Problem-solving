// Given an array of non-negative integers representation elevation of ground.
// Your task is to find the water that can be trapped after rain.

// TC-O(N) because of 2 pointer approach
// SC-O(1)
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int result = 0;
  int maxLeft = 0, maxRight = 0;

  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        result += maxLeft - height[left];
      }
      left++;
    }

    else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        result += maxRight - height[right];
      }
      right--;
    }
  }
  return result;
}

int main() {
  vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << "The water that can be trapped is " << trap(arr) << endl;

  return 0;
}