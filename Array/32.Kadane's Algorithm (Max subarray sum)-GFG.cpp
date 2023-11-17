// Given an array Arr[] of N integers. Find the contiguous sub-array(containing
// at least one number) which has the maximum sum and return its sum.

// TC - O(n)

#include <iostream>
#include <limits.h>
using namespace std;

int maxSubArraySum(int arr[], int size) {
  int maxi = INT_MIN;
  int sum = 0;

  int start = 0; // These 3 variables to print subarray with max sum
  int ansStart = -1;
  int ansEnd = -1;

  for (int i = 0; i < size; i++) {

    if (sum == 0) {
      start = i;
    }
    sum += arr[i];

    if (sum > maxi) {
      maxi = sum;

      ansStart = start;
      ansEnd = i;
    }
    if (sum < 0) {
      sum = 0;
    }
  }
  if (maxi < 0) { // To consider the sum of the empty subarray
    maxi = 0;
  }

  cout << "The subarray is: " << endl;
  for (int i = ansStart; i <= ansEnd; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return maxi;
}

int main() {
  int arr[] = {1, 2, 3, -2, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << maxSubArraySum(arr, size);

  return 0;
}