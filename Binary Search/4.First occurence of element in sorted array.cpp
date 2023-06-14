#include <iostream>
#include <vector>
using namespace std;

// TC - o(logn)

int firstOccurence(vector<int> arr, int target) {
  int start = 0;
  int end = arr.size() - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    if (arr[mid] == target) { // If found it may not be the first occurence
      ans = mid;              // store the index
      end = mid - 1;
    } else if (arr[mid] > target)
      end = mid - 1;
    else
      start = mid + 1;
    mid = start + (end - start) / 2;
  }
  return ans;
}

int main() {
  vector<int> arr{2, 3, 3, 5, 5, 5, 5, 6, 7};
  int target = 5;

  int ans = firstOccurence(arr, target);
  cout << "First occurence is found at index " << ans << endl;

  // Inbuilt method
  auto ans2 = lower_bound(arr.begin(), arr.end(), target);
  cout << "First occurence is found at index (using inbuilt method) "
       << ans2 - arr.begin();
  return 0;
}