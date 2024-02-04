// If two rows have the same number of ones, consider the one with a smaller
// index. If there’s no row with at least 1 zero, return -1.

#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &arr, int n, int target) {
  int low = 0;
  int high = n - 1;
  int ans = n;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] >= target) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
  int count_max = 0;
  int index = -1;

  for (int i = 0; i < n; i++) {
    // count_ones = No of col - index when 1 appeared first
    int count_ones = m - lowerBound(matrix[i], m, 1);

    if (count_ones > count_max) {
      count_max = count_ones;
      index = i;
    }
  }
  return index;
}

int main() {
  vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
  int n = 3, m = 3;
  cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m);

  return 0;
}