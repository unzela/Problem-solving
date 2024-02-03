// https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/902645323/
// https://www.geeksforgeeks.org/find-the-element-that-odd-number-of-times-in-olog-n-time/

// All repeating elements occur in pair and no 2 pairs are adjacent

// Ans is always at even index
// Left side of ans are in even odd index pair
// Right side of ans are in odd even index pair

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> arr) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (start == end) // If single element in present in array
      return start;

    else if (mid % 2 == 0) {          // If mid is at even index
      if (arr[mid] == arr[mid + 1]) { // this is left, so ans is on right
        start = mid + 2;
      } else {
        end = mid;
      }
    }

    else { // If mid is at odd index
      if (arr[mid] == arr[mid - 1]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    mid = start + (end - start) / 2;
  }
  return -1;
}

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size();

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            low = mid + 1;  //eliminate the left half
        }
        //we are in the right:
        else {
            high = mid - 1;//eliminate the right half
        }
    }
    return -1;
}

int main() {
  vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};
  int result = search(arr);
  // int ans = singleNonDuplicate(arr);
  cout << "Index is " << result << " and Value is " << arr[result];

  return 0;
}
