#include <iostream>
#include <vector>
using namespace std;

// Method - 1
//  TC - o(n)
//  SC - O(1)
void findMissingNumber(vector<int> arr, int size) {
  // for (int i = 0; i < arr.size(); i++) {
  //   int index = abs(arr[i]);
  //   if (arr[index - 1] > 0) {
  //     arr[index - 1] *= -1;
  //   }
  // }
  // for (int i = 0; i < arr.size(); i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;

  // for (int i = 0; i < arr.size(); i++) {
  //   if (arr[i] > 0)
  //     cout << i + 1 << " ";
  // }

  // Method 2 - Sorting + swapping
  int i = 0;
  while (i < arr.size()) {
    int index = arr[i] - 1;
    if (arr[i] != arr[index]) {
      swap(arr[i], arr[index]);
    } else {
      i++;
    }
  }

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] != i + 1)
      cout << i + 1 << " ";
  }
}

int main() {
  vector<int> arr{1, 3, 3, 5, 3};
  findMissingNumber(arr, arr.size());
  return 0;
}