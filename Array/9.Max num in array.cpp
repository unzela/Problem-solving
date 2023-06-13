#include <iostream>
#include <limits.h>
using namespace std;

int main() {
  int n, arr[5];
  int max = INT_MIN; // Minimum possible integer value

  cout << "Enter the size of array ";
  cin >> n;
  cout << "Enter the elements of array ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  cout << "Max Number is " << max;
}