// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing
// order. Merge them in sorted order without using any extra space. Modify arr1
// so that it contains the first N elements and modify arr2 so that it contains
// the last M elements.

#include <algorithm>
#include <iostream>
using namespace std;

// Brute Force
//  TC= o(n+m)+o(n+m)
//  SC - 0(n+m) because of extra 3rd array
void mergeBruteForce(int arr1[], int arr2[], int n, int m) {
  int arr3[n + m];
  int left = 0;
  int right = 0;
  int index = 0;

  // Insert the elements from the 2 arrays into the 3rd array using left and
  // right pointers
  while (left < n && right < m) {
    if (arr1[left] <= arr2[right]) {
      arr3[index] = arr1[left];
      left++;
      index++;
    } else {
      arr3[index] = arr2[right];
      right++;
      index++;
    }
  }

  // If right pointer reaches the end
  while (left < n) {
    arr3[index] = arr1[left];
    left++;
    index++;
  }

  // If left pointer reaches the end
  while (right < m) {
    arr3[index] = arr2[right];
    right++;
    index++;
  }

  // Fill back the elements from arr3[] to arr1[] and arr2[]
  for (int i = 0; i < n + m; i++) {
    if (i < n) {
      arr1[i] = arr3[i];
    } else {
      arr2[i - n] = arr3[i];
    }
  }
}

// 2 Pointer Approach
// TC - o(min(n,m)) + o(nlogn) + o(mlogm)
// SC - O(1)
void mergeTwoPointer(int arr1[], int arr2[], int n, int m) {
  int left1 = n - 1;
  int right1 = 0;

  // Swap the elements until arr1[left] is smaller than arr2[right]:
  while (left1 >= 0 && right1 < m) {
    if (arr1[left1] > arr2[right1]) {
      swap(arr1[left1], arr2[right1]);
      left1--;
      right1++;
    } else {
      break;
    }
  }
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
}

// Optimal Solution 2
// Gap Method (Shell Sort)

void mergeGapMethod(int arr1[], int arr2[], int n, int m) {}

int main() {
  int arr1[] = {1, 4, 8, 10};
  int arr2[] = {2, 3, 9};

  int n = sizeof(arr1) / sizeof(arr1[0]);
  int m = sizeof(arr2) / sizeof(arr2[0]);
  mergeBruteForce(arr1, arr2, n, m);

  cout << "Brute Force - The merged arrays are: "
       << "\n";
  cout << "arr1[] = ";
  for (int i = 0; i < n; i++) {
    cout << arr1[i] << " ";
  }
  cout << "\narr2[] = ";
  for (int i = 0; i < m; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  // mergeTwoPointer(arr1, arr2, n, m);
  cout << "Optimal Solution (2 Pointer) - The merged arrays are: "
       << "\n";
  cout << "arr1[] = ";
  for (int i = 0; i < n; i++) {
    cout << arr1[i] << " ";
  }
  cout << "\narr2[] = ";
  for (int i = 0; i < m; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  return 0;
}