#include <iostream>
using namespace std;

void printRowSum(int arr[][3], int row, int col) {
  for (int i = 0; i < row; i++) {
    int sum = 0;
    for (int j = 0; j < col; j++) {
      sum = sum + arr[i][j];
    }
    cout << sum << endl;
  }
}

int main() {
  int row, col;
  int arr[3][3];
  cout << "Enter the number of rows and columns ";
  cin >> row >> col;

  cout << "Enter the elements of array ";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }

  printRowSum(arr, row, col);
  return 0;
}