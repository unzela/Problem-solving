#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr{7, 1, 5, 3, 6, 4};

  int max = 0;

  for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] - arr[i] > max) {
        max = arr[j] - arr[i];
      }
    }
  }
  cout << max;
}