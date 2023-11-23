// Given an array A of n positive numbers. The task is to find the first
// equilibrium point in an array. Equilibrium point in an array is an index (or
// position) such that the sum of all elements before that index is same as sum
// of elements after it.

// TC-O(n)
// SC-O(1)
#include <iostream>
using namespace std;

int findEquilibriumIndexBruteForce(int arr[], int n) { // TC-O(n^2)
  for (int i = 0; i < n; i++) {
    int leftSum = 0;
    for (int j = 0; j < i; j++) {
      leftSum += arr[j];
    }
    int rightSum = 0;
    for (int j = i + 1; j < n; j++) {
      rightSum += arr[j];
    }
    if (leftSum == rightSum) {
      return i;
    }
  }
  return -1;
}

int findEquilibriumIndex(int arr[], int n) {
  int totalSum = 0;
  for (int i = 0; i < n; i++) {
    totalSum += arr[i];
  }

  int leftSum = 0;
  int rightSum = totalSum;
  for (int i = 0; i < n; i++) {
    rightSum -= arr[i];
    if (leftSum == rightSum) {
      return i;
    }
    leftSum += arr[i];
  }
  return -1;
}

int main() {
  int n = 5;
  int arr[] = {2, 3, -1, 8, 4};
  // int equilibriumidx1 = findEquilibriumIndexBruteForce(arr, n);
  int equilibriumidx = findEquilibriumIndex(arr, n);
  cout << equilibriumidx << endl;
  return 0;
}