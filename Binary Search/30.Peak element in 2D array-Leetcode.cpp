// TC - O(logm * n)
// SC - O(1)
#include <iostream>
#include <vector>
using namespace std;

int findMaxRowIndex(vector<vector<int>> &matrix, int n, int m, int col) {
  int maxValue = -1;
  int index = -1;

  for (int i = 0; i < n; i++) {
    if (matrix[i][col] > maxValue) {
      maxValue = matrix[i][col];
      index = i;
    }
  }
  return index;
}

vector<int> peakElement(vector<vector<int>> mat) {
  int n = mat.size();
  int m = mat[0].size();

  int low = 0;
  int high = m - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int maxRowIndex = findMaxRowIndex(mat, n, m, mid);
    // Find index of row of max element in column mid
    int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
    int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;
    // Top and bottom element of mid will be smaller than mid

    if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
      return {maxRowIndex, mid};
    } else if (mat[maxRowIndex][mid] < left) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return {-1, -1};
}

int main() {
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};

  vector<int> ans = peakElement(matrix);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";

    return 0;
  }
}