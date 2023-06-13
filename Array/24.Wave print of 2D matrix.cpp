#include <iostream>
#include <vector>
using namespace std;

void wavePrint(vector<vector<int>> arr) {
  int rows = arr.size();
  int cols = arr[0].size();

  for (int startCol = 0; startCol < cols; startCol++) {
    // Even no of col - Top to Bottom
    if (startCol % 2 == 0) {
      for (int i = 0; i < rows; i++) {
        cout << arr[i][startCol] << " ";
      }
    } else {
      // Odd no of col - Bottom to Top
      for (int i = rows - 1; i >= 0; i--) {
        cout << arr[i][startCol] << " ";
      }
    }
  }
}

int main() {
  vector<vector<int>> arr{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  wavePrint(arr);
  return 0;
}