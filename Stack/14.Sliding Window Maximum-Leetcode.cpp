// /Given an array of integers arr, there is a sliding window of size k which is
// moving from the very left of the array to the very right. You can only see
// the k numbers in the window. Each time the sliding window moves right by one
// position.

// TC-O(N)+O(N) = O(N)
// sc-O(k) ie will have elements that is equal to the size of sliding window
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
  deque<int> dq;
  vector<int> ans;

  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) { // Remove out of bound elements
      dq.pop_front();
    }
    while (!dq.empty() &&
           nums[dq.back()] < nums[i]) { // Removes all elements<a[i]
      dq.pop_back();
    }
    dq.push_back(i); // Push current index in deque
    if (i > k - 1) {
      ans.push_back(nums[dq.front()]);
    }
  }

  return ans;
}

int main() {
  int k = 3;
  vector<int> arr{4, 0, -1, 3, 5, 3, 6, 8};
  vector<int> ans;
  ans = maxSlidingWindow(arr, k);
  cout << "Maximum element in every " << k << " window " << endl;

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";

  return 0;
}