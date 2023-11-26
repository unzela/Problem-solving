// Given are N boards of with length of each given in the form of array, and K
// painters, such that each painter takes 1 unit of time to paint 1 unit of the
// board. The task is to find the minimum time to paint all boards under the
// constraints that any painter will only paint continuous sections of boards,
// say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSolution(int arr[], int N, int k, long long mid) {
  long long timeSum = 0;
  int counter = 1;

  for (int i = 0; i < N; i++) {
    if (arr[i] > mid) {
      return false;
    }
    if (timeSum + arr[i] > mid) {
      counter++; // Allocate to next painter
      timeSum = arr[i];
      if (counter > k) { // No of allocations is more than no of painters
        return false;
      }
    } else {
      timeSum += arr[i];
    }
  }
  return true;
}

long long minTime(int arr[], int N, int k) {
  long long start = 0;
  long long ans = -1;
  long long end = 0;
  for (int i = 0; i < N; i++) {
    end += arr[i];
  }

  while (start <= end) {
    long long mid = start + (end - start) / 2;
    if (isPossibleSolution(arr, N, k, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}

int main() {
  int arr[] = {10, 20, 30, 40};
  int N = 4;
  int k = 2;
  cout << minTime(arr, N, k);
}