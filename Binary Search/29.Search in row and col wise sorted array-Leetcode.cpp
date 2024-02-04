// TC-O(n+m)
// SC- O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchElement(vector<vector<int>> &matrix, int target) {
  int n = matrix.size();
  int m = matrix[0].size();

  int row = 0; // Initially at first row, last column
  int col = m - 1;

  while (row < n && col >= 0) {
    if (matrix[row][col] == target) {
      return {row, col};
    }

    else if (matrix[row][col] < target) {
      row++;
    }

    else {
      col--;
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
  vector<int> ans = searchElement(matrix, 8);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  // if (ans) {
  //   cout << "true\n";
  // } else {
  //   cout << "false\n";
  // }
  return 0;
}