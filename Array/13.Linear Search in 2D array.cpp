#include <iostream>
using namespace std;

bool linearSearch(int arr[][5], int row, int col, int key) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < row; j++) {
      if (arr[i][j] == key)
        return true;
    }
  }
  return false;
}

int main() {
  int row, col, key;
  int arr[5][5];
  cout << "Enter the number of rows and columns ";
  cin >> row >> col;
  cout << "Enter the key to search in array ";
  cin >> key;

  cout << "Enter the elements of array ";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }

  cout << linearSearch(arr, row, col, key);
  return 0;
}