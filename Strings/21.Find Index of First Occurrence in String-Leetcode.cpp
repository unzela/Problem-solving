// Given two strings needle and haystack, return the index of the first
// occurrence of needle in haystack, or -1 if needle is not part of haystack.

// TC - O((N-M+1)*N) = O(N*M)
#include <iostream>
using namespace std;

int indexOfFirstOccurence(string haystack, string needle) {
  int n = haystack.length();
  int m = needle.length();

  for (int i = 0; i < n - m + 1; i++) { // No need to check till last index
    for (int j = 0; j < m; j++) {
      if (needle[j] != haystack[i + j]) {
        break;
      }
      if (j ==
          m - 1) { // If needle is traversed completely and found in heystack
        return i;
      }
    }
  }
  return -1;
}

int main() {
  string haystack = "letsadu";
  string needle = "sad";
  cout << indexOfFirstOccurence(haystack, needle);
  return 0;
}