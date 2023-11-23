// Given an array of N integers, count the inversion of the array (using
// merge-sort).
// What is an inversion of an array? Definition: for all i & j <
// size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j]
// < A[i].

// TC -  O(N*logN)
// SC -  O(N), as in merge sort we use temporary array to store elements in
// sorted order.
#include <iostream>
#include <vector>
using namespace std;

int numberOfInversionsBruteForce(vector<int> &a, int n) { // TC-O(n^2)
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j])
        cnt++;
    }
  }
  return cnt;
}

int merge(vector<int> arr, int low, int mid, int high) {
  vector<int> temp;
  int left = low;      // starting index of left half of arr
  int right = mid + 1; // starting index of right half of arr

  // Modification 1 in merge sort: count variable to count the pairs
  int count = 0;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      count += (mid - left + 1); // Modification 2 in merge sort
      right++;
    }
  }

  while (left <= mid) { // if elements on the left half are still left
    temp.push_back(arr[left]);
    left++;
  }

  while (right <= high) { // if elements on the right half are still left
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high;
       i++) { // transfering all elements from temporary to arr
    arr[i] = temp[i - low];
  }

  return count; // Modification 3
}

int mergeSort(vector<int> arr, int low, int high) {
  int count = 0;
  if (low >= high) {
    return count;
  }
  int mid = (low + high) / 2;
  count += mergeSort(arr, low, mid);      // left half
  count += mergeSort(arr, mid + 1, high); // right half
  count += merge(arr, low, mid, high);    // merge sorted halves

  return count;
}

int noOfInversions(vector<int> &a, int n) {
  return mergeSort(a, 0, n - 1); // Count the number of pairs:
}

int main() {
  vector<int> arr{5, 4, 3, 2, 1};
  int n = 5;
  int count = noOfInversions(arr, n);
  // int count1 = numberOfInversionsBruteForce(arr, n);
  cout << "No of Inversions: " << count;

  return 0;
}