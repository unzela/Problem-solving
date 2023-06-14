// An element which breaks the monotonous function/graph. Its previous and next
// elements are small, but do not form mountain.
#include <iostream>
#include <vector>

using namespace std;

int findPivot(vector<int> arr) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (start == end) // if single element is there in array
      return start;
    else if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
      return mid;
    else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
      return mid - 1;

    else if (arr[start] > arr[mid])
      end = mid - 1;
    else
      start = mid + 1;

    mid = start + (end - start) / 2;
  }
  return -1;
}

int main() {
  vector<int> arr{2, 3, 4, 5, 7, 9, 3, 5, 6};

  int ans = findPivot(arr);
  cout << "Pivot Element is at index " << ans << " and the element is "
       << arr[ans];
  return 0;
}