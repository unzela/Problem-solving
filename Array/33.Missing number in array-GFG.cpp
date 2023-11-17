// Given an array of size N-1 such that it only contains distinct integers in
// the range of 1 to N. Find the missing element.

// TC- O(n) for both methods
#include <iostream>
using namespace std;

// Sum Method
int missingNoSumMethod(int arr[], int n) {
  int total = (n + 1) * (n + 2) / 2; // n+1 because including missing element

  for (int i = 0; i < n; i++) {
    total -= arr[i];
  }
  return total;
}

// XOR Method
int missingNoXORMethod(int arr[], int n) {
  int x1 = arr[0]; // For XOR of all elements in array
  int x2 = 1;      // For XOR of all elements from 1 to n+1
  for (int i = 1; i < n; i++) {
    x1 = x1 ^ arr[i];
  }
  for (int i = 2; i <= n + 1; i++) {
    x2 = x2 ^ i;
  }
  return x1 ^ x2;
}

int main() {
  int arr[] = {6, 1, 2, 8, 4, 7, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  cout << missingNoSumMethod(arr, size);
  cout << endl;
  cout << missingNoXORMethod(arr, size);
  return 0;
}