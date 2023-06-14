#include <iostream>
#include <vector>
using namespace std;

int searchInNearlySortedArray(vector<int> arr, int target) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] == target)
      return mid;
    else if (mid - 1 >= 0 && arr[mid - 1] == target)
      return mid - 1;
    else if (mid + 1 < arr.size() && arr[mid + 1] == target)
      return mid + 1;

    else if (arr[mid] > target)
      end = mid - 2;
    else
      start = mid + 2; //+2 as we have already checked mid+1 element

    mid = start + (end - start) / 2;
  }
  return -1;
}

int main() {
  int target, result;
  vector<int> arr{3, 2, 10, 4, 40};
  cout << "Enter a number to search ";
  cin >> target;

  result = searchInNearlySortedArray(arr, target);
  cout << "Index of " << target << " is " << result;

  return 0;
}
