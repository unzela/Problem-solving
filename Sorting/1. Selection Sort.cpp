// TC - o(n^2)
// SC - o(1)
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr{2, 3, 5, 1, 6};
  int n = arr.size();

  // Outer loop for (n-1) rounds
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;

    // inner loop to find index of minimum element in range i to n
    for (int j = i + 1; j < n; j++) { // or j=i
      if (arr[j] < arr[minIndex]) {
        minIndex = j; // new minimum, then store it
      }
    }

    swap(arr[i], arr[minIndex]); // Swap
  }

  // Printing
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}