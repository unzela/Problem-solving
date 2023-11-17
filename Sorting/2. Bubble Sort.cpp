// SC - o(1)
// TC in normal/worst case - o(n^2)
// Best Case TC - o(n) , as no need of round 2 and only need comparisons in
// round 1 Optimize it using swapped boolean variable, by checking whether any
// element got swapped in any round or not. If no, then break it, no need to
// check further

// Ques - Place the ith largest element at its correct position

#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr{3, 6, 1, 4, 2, 9};
  int n = arr.size();

  // Outer loop for rounds
  for (int round = 1; round < n; round++) {
    bool swapped = false;

    // inner loop for swapping 2 adjacent elements
    for (int j = 0; j < n - round; j++) { // Or j<=n-round-1
      if (arr[j] > arr[j + 1]) {
        swapped = true;
        swap(arr[j], arr[j + 1]);
      }
    }

    if (swapped == false) {
      break; // already swapped, no need of further rounds
    }
  }

  // Printing
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}