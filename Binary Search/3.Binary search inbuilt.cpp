#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr{2, 3, 5, 7};
  int target = 5;

  // binary_serach return true if element found, else false
  int ans = binary_search(arr.begin(), arr.end(), target);
  if (ans)
    cout << "Found ";
  else
    cout << "Not Found";

  // For array
  int arr1[] = {1, 2, 3, 4, 5, 7};
  int size = 6;

  int ans1 = binary_search(arr1, arr1 + size, target);
  if (ans1)
    cout << "Found ";
  else
    cout << "Not Found";
  return 0;
}