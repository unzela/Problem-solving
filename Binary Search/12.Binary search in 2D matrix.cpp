#include <iostream>
#include <vector>
using namespace std;

// x=c*i+j;
// i=x/c and j=x%c
bool search2dMatrix(int arr[][4], int rows, int cols, int target) {
  int start = 0;
  int end = rows * cols - 1;
  int mid = start + (end - start) / 2;
  int rowIndex, colIndex;

  while (start < end) {
    rowIndex = mid / cols;
    colIndex = mid % cols;

    if (target == arr[rowIndex][colIndex]) {
      cout << "Found at index " << rowIndex << " " << colIndex;
      return true;
    }

    else if (target > arr[rowIndex][colIndex])
      start = mid + 1;

    else
      end = mid - 1;

    mid = start + (end - start) / 2;
  }
  return false;
}

int main() {
  int arr[5][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16},
                   {17, 18, 19, 20}};

  int rows = 5;
  int cols = 4;
  int target;
  cout << "Enter an element to search ";
  cin >> target;

  bool ans = search2dMatrix(arr, rows, cols, target);

  if (ans)
    cout << "Found";
  else
    cout << "Not Found";
}