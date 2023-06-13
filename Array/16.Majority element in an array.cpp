// A majority element in an array A[] of size n is an element that appears more
// than n/2 times
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr{3, 4, 4, 2, 4, 4, 4, 2, 4};
  int count = 0;
  int mid = arr.size() / 2;

  for (int i = 0; i < arr.size(); i++) {
    count = 0;
    for (int j = i; j < arr.size(); j++) {
      if (arr[i] == arr[j]) {
        count++;
      }
    }
    if (count > mid) {
      cout << "Majority element is: " << arr[i];
      break;
    }
  }
  if (count < mid) {
    cout << "No majority element found";
  }
  return 0;
}