// Given a string, return the no of palindromic substrings in it
// 2 pointer approach
// TC = o(n)*o(n/2) = o(n^2)

#include <iostream>
#include <string.h>
using namespace std;

int expandAroundOdd(string s, int i, int j) {
  int count = 0;
  // If char matches inc count, inc i and dec j
  while (i >= 0 && j < s.length() && s[i] == s[j]) {
    count++;
    i--;
    j++;
  }
  return count;
}

int countSubstrings(string str) {
  int totalCount;
  int n = str.size();

  for (int i = 0; i < n; i++) {
    // odd length of substring
    int oddAns = expandAroundOdd(
        str, i, i); // initially i, j both are at same 0th index //TC-o(n/2)
    totalCount = totalCount + oddAns;
    // even length of substring
    int evenAns =
        expandAroundOdd(str, i, i + 1); // i, j are at 0th and 1st index
    totalCount = totalCount + evenAns;
  }
  return totalCount;
}

int main() {
  string s = "noon";
  cout << countSubstrings(s);
  return 0;
}