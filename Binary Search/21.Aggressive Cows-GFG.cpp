// Given a sorted array arr[] consisting of N integers which denote the position
// of a stall. You are also given an integer K which denotes the number of
// aggressive cows. You are given the task of assigning stalls to K cows such
// that the minimum distance between any two of them is the maximum possible.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> &stalls, int k, int mid) {
  // Can we place k cows with atleast mid distance btwn cows
  int count = 1;
  int pos = stalls[0];

  for (int i = 0; i < stalls.size(); i++) {
    if (stalls[i] - pos >= mid) {
      count++;
      pos = stalls[i]; // One more cow has been added
    }
    if (count == k) {
      return true;
    }
  }
  return false;
}

int placeCows(vector<int> &stalls, int n, int k) {
  sort(stalls.begin(), stalls.end());
  int ans = -1;
  int start = stalls[0];
  int end = stalls[stalls.size() - 1] - stalls[0]; // max-min

  while (start <= end) {
    int mid = (start + end) / 2;
    if (isPossibleSolution(stalls, k, mid)) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  vector<int> stalls{1, 2, 4, 8, 9};
  int n = 5;
  int k = 3;
  cout << placeCows(stalls, n, k);
  return 0;
}