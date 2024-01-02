// Given a string s, return the longest palindromic substring in s.
//  TC = o(n^3) Will be improved using DP

#include <iostream>
#include <string.h>
using namespace std;

bool isPalindrome(string &s, int start, int end) {
  while (start < end) {
    if (s[start] != s[end]) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}

string longestPalindrome(string str) {
  string ans = "";

  for (int i = 0; i < str.size(); i++) {
    for (int j = i; j < str.size(); j++) {
      if (isPalindrome(str, i, j)) {
        string t = str.substr(i, j - i + 1);
        ans = t.size() > ans.size() ? t : ans;
      }
    }
  }
  return ans;
}

int main() {
  string str = "babad";
  cout << longestPalindrome(str);
  return 0;
}