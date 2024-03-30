#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// TC- O( 2*N ) (sometimes left and right both have to travel a complete array)
// SC- O(N) where N is the size of HashSet taken for storing the elements
int lengthOfLongestSubstr(string str) {
  unordered_set<int> set;
  int length = INT_MIN;
  int left = 0;

  if (str.size() == 0) {
    return 0;
  }

  for (int r = 0; r < str.length(); r++) { // outer loop for traversing string
    if (set.find(str[r]) != set.end()) {   // if duplicate element is found
      while (left < r && set.find(str[r]) != set.end()) {
        set.erase(str[left]);
        left++;
      }
    }
    set.insert(str[r]);
    length = max(length, r - left + 1);
  }

  return length;
}

// TC- O(N)
// SC- O(N)
int lengthofLongestSubstringOptimised(string str) {
  int left = 0, right = 0;
  int n = str.size();
  int length = 0;
  unordered_map<char, int> mpp;

  while (right < n) {
    if (mpp.find(str[right]) != mpp.end()) {
      left = max(left, mpp[str[right]]);
    }
    mpp[str[right]] = right;
    length = max(length, right - left + 1);
    right++;
  }
  return length;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is "
       << lengthofLongestSubstringOptimised(str);
  return 0;
}