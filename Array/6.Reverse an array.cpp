#include <iostream>
#include <limits.h>
using namespace std;

int main() {
  int n, arr[10];
  int start = 0;
  int end = n - 1;

  cout << "Enter the size of array ";
  cin >> n;
  cout << "Enter the elements of array ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  while (start <= end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
