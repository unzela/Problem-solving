// Given string s, return true if s can be palindrome after deleting at most 1
// char from it
#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(string str, int i, int j) {
  while (i <= j) {
    if (str[i] != str[j])
      return false;
    i++;
    j--;
  }
  return true;
}

bool validPalindrome(string str) {
  int i = 0;
  int j = str.length() - 1;

  while (i <= j) {
    if (str[i] != str[j]) {
      return checkPalindrome(str, i + 1, j) ||
             checkPalindrome(str, i, j - 1); // either remove i or j
    } else {                                 // str[i]==str[j]
      i++;
      j--;
    }
  }
  return true; // only executed when no char is removed
}

int main() {
  string str;
  cin >> str;
  cout << validPalindrome(str);
}