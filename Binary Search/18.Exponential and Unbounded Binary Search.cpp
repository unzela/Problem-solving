// Also called as doubling / Galloping / Stragic Search
// Applying Binary search on a small portion of arry (subarray)
#include <iostream>
using namespace std;

// TC - O(log(2^((log m)-1)))
int binarySearch(int a[], int start, int end, int x) {
  while (start <= end) {
    int mid = (start + end) / 2;
    if (a[mid] == x) {
      return mid;
    } else if (x > a[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

int expoSearch(int a[], int n, int k) {
  if (a[0] == k) {
    return 0;
  }
  int i = 1;
  while (i < n && a[i] <= k) {
    i = i * 2;
  }
  return binarySearch(a, i / 2, min(i, n - 1), k);
  // min(i,n-1) if n is out of bound
}

int main() {
  int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
  int n = sizeof(arr) / sizeof(int);
  int k = 13;
  int result = expoSearch(arr, n, k);
  cout << result;
  return 0;
}
// Algo for Unbounded binary search
// I.e find an element in infinite arrray

// Brute force - run infinite loop
// while (1) {
//   if (arr[i] > x) {
//     break;
//   }
//   if (arr[i] == x) {
//     ans = i;
//   }
//   i++;
// }

// Exponential Search
//   i=0;
//   j=1;
//   while(a[j]<x){
//     i=j;
//     j=j*2;
//   }
//  Then binary search from
//  start=i;
//  end=j