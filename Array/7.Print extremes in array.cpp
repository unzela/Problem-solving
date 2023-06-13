#include <iostream>
#include <limits.h>
using namespace std;

int main() {
  int n, arr[5];

  cout << "Enter the size of array ";
  cin >> n;
  cout << "Enter the elements of array ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Using 2 pointers, one at start and other at end of array
  int start = 0;
  int end = n - 1;

  while (true) { // or while(start <= end)
    if (start > end)
      break;

    if (start == end)
      cout << arr[start] << " "; // Print only once, either start or end

    else {
      cout << arr[start] << " ";
      cout << arr[end] << " ";
    }
    start++;
    end--;
  }
}