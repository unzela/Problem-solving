// Given 2 strings, determine if they are isomorphic or not
// 2 strings are isomorphic if the chars in s can be replaced to get t, while
// preserving the order of chars. No 2 chars can map to same char but a char
// may map to itself

#include <iostream>
using namespace std;

bool isIsomorphic(string s, string t) {

  int hash[256] = {0}; // Mapping of each char of language 's' to language 't'
  bool isCharsMapped[256] = {0}; // store if t[i] is already mapped with s[i]

  for (int i = 0; i < s.length(); i++) {
    if (hash[int(s[i])] == 0 && isCharsMapped[int(t[i])] == 0) {
      hash[int(s[i])] = t[i];
      isCharsMapped[int(t[i])] = true;
    }
  }

  for (int i = 0; i < s.length(); i++) {
    if (char(hash[int(s[i])]) != t[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string s = "add";
  string t = "egg";
  cout << isIsomorphic(s, t);
}