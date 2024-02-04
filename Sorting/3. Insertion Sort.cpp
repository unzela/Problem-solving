// TC for normal case - o(n^2)
// TC for Best case - o(n)
// SC - o(1)
#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
  vector<int> arr{3, 1, 7, 4, 9, 2};
  int n = arr.size();

  for (int round = 1; round < n; round++) {
    // Step 1 - Fetch value
    int val = arr[round];

    int j = round - 1;
    // Step 2 - Compare
    for (; j >= 0; j--) {
      if (arr[j] > val) {
        // Step 3 - Shift
        arr[j + 1] = arr[j];
      } else {
        break;
      }
    }
    // Step 4 - Copy
    arr[j + 1] = val; // j+1 as j will become j-1 after loop ends
  }

  // Printing
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

// sort(arr.begin(), arr.end());