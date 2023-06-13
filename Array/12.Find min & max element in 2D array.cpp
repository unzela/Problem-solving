#include <iostream>
#include <limits.h>
using namespace std;

int findMax(int arr[][5], int row, int col) {
  int max = INT_MIN;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] > max)
        max = arr[i][j];
    }
  }
  return max;
}

int findMin(int arr[][5], int row, int col) {
  int min = INT_MAX;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] < min)
        min = arr[i][j];
    }
  }
  return min;
}

int main() {
  int row, col, key;
  int arr[5][5];
  cout << "Enter the number of rows and columns ";
  cin >> row >> col;

  cout << "Enter the elements of array ";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }

  cout << "Maximum element is " << findMax(arr, row, col) << endl;
  cout << "Minimum element is " << findMin(arr, row, col);
  return 0;
}