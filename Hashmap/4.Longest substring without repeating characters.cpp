#include <iostream>
#include <map>
#include <vector>
using namespace std;

int lengthofLongestSubstring(string str) {
  vector<int> mpp(256, -1);
  int n = str.length();
  int length = 0;
  int left = 0;
  int right = 0;

  while (right < n) {
    if (mpp[str[right]] != -1) {
      left = max(mpp[str[right]] + 1, left);
      mpp[str[right]] = right;
      length = max(length, right - left + 1);
    }
  }
  return length;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters "
          "is "
       << lengthofLongestSubstring(str);
  return 0;
}