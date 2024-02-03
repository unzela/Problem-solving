// You’re given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int> arr, int x) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= x) { // Maybe an ans
      ans = arr[mid];
      low = mid + 1; // look for smaller index on the left
    } else {
      high = mid - 1; // look on the right
    }
  }
  return ans;
}

int findCeil(vector<int> arr, int x) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= x) {
      ans = arr[mid];
      high = mid - 1; // look for smaller index on the left
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {2, 3, 5, 7, 9};
  cout << findFloor(arr, 6) << endl;
  cout << findCeil(arr, 6);
  return 0;
}