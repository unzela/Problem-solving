#include <iostream>
#include <vector>
using namespace std;

vector<int> spiral(vector<vector<int>> &matrix) {
  vector<int> ans;
  int m = matrix.size();
  int n = matrix[0].size();
  int total_elements = m * n;

  int startingRow = 0;
  int endingCol = n - 1;
  int endingRow = n - 1;
  int startingCol = 0;

  int count = 0;
  while (count < total_elements) {
    // Print startingRow
    for (int i = startingCol; i <= endingCol && count < total_elements; i++) {
      ans.push_back(matrix[startingRow][i]);
      count++;
    }
    startingRow++;

    // Print endingCol
    for (int i = startingRow; i <= endingRow && count < total_elements; i++) {
      ans.push_back(matrix[i][endingCol]);
      count++;
    }
    endingCol--;

    // Print endingRow
    for (int i = endingCol; i >= startingCol && count < total_elements; i--) {
      ans.push_back(matrix[endingRow][i]);
      count++;
    }
    endingRow--;

    // Print startingCol
    for (int i = endingRow; i >= startingRow && count < total_elements; i--) {
      ans.push_back(matrix[i][startingCol]);
      count++;
    }
    startingCol++;
  }

  return ans;
}

int main() {
  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> ans = spiral(matrix);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}