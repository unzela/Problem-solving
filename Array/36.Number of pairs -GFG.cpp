// Given two arrays X and Y of positive integers, find the number of pairs such
// that xy > yx (raised to power of) where x is an element from X and y is an
// element from Y.

// If x<y, then x^y > y^x
//  TC: O((N + M)log(N))
//  SC: O(1)

#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int countPairsBruteForce(int X[], int Y[], int m, int n) { // TC-O(m*n)
  int ans = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (pow(X[i], Y[j]) > pow(Y[j], X[i])) {
        ans++;
      }
    }
  }
  return ans;
}

int getIndex(int y[], int n, int ele) { // Returning no of elements that are
                                        // ahead of that index satisfying x<y

  int low = 0;
  int high = n - 1;
  int ans = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (y[mid] > ele) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int countPairs(int x[], int y[], int m, int n) {

  int zeros = 0, one = 0, three = 0, four = 0, two = 0;
  sort(x, x + m); // Sort array x
  sort(y, y + n);

  for (int i = 0; i < n; i++) {
    if (y[i] == 0)
      zeros++;
    if (y[i] == 1)
      one++;
    if (y[i] == 3)
      three++;
    if (y[i] == 4)
      four++;
    if (y[i] == 2)
      two++;
  }

  // traversing x elements
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (x[i] == 0) {
      continue;
    } else if (x[i] == 1) {
      ans += zeros;
    } else if (x[i] == 2) {
      int index = getIndex(y, n, 2);
      if (index != -1) {
        ans += n - index;
      }
      ans -= three;
      ans -= four;
      ans += one + zeros;
    } else {
      int index = getIndex(y, n, x[i]);
      if (index != -1) {
        ans += n - index;
      }
      ans += one + zeros;
      if (x[i] == 3) {
        ans += two;
      }
    }
  }
  return ans;
}

int main() {
  int arr1[] = {2, 3, 0, 1, 4, 5};
  int arr2[] = {1, 2, 3};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << "Total pairs = " << countPairsBruteForce(arr1, arr2, size1, size2)
       << endl;

  cout << "Total pairs = " << countPairs(arr1, arr2, size1, size2);

  return 0;
}