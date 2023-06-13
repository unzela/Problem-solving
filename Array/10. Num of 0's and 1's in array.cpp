#include <iostream>
using namespace std;

int main() {
  int arr[5], n;
  int zeroSum = 0, oneSum = 0;

  cout << "Enter size of array ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    // If 0 found, increment zeroSum
    if (arr[i] == 0) {
      zeroSum++;
    }
    if (arr[i] == 1) {
      oneSum++;
    }
  }
  cout << "No of 1's " << oneSum << endl;
  cout << "No of 0's " << zeroSum;
}