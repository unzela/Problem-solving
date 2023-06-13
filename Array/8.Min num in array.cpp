#include <iostream>
#include <limits.h>
using namespace std;

int main() {
  int n, arr[5];
  int min = INT_MAX; // Maximum possible integer value

  cout << "Enter the size of array ";
  cin >> n;
  cout << "Enter the elements of array ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  cout << "Min Number is " << min;
}