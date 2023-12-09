// Given 2 strings s and t, return true if t is an anagram of s, else return
// false

//Brute Force - Sort both string and then compare them

// TC- O(n+m)
#include <iostream>
using namespace std;

bool isAnagram(string s, string t) { // O(n)
  int freqTable[256] = {0};          // Hash Table
  for (int i = 0; i < s.size(); i++) {
    freqTable[int(s[i])]++; // explicitly converting char to int
  }

  for (int i = 0; i < t.size(); i++) { // O(m) Using same freq table instead of creating 2 freq tables and comparing them
    freqTable[int(t[i])]--;
  }

  for (int i = 0; i < 256; i++) { // O(256)
    if (freqTable[i] != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string s = "anagram";
  string t = "naagram";
  cout << isAnagram(s, t);
  return 0;
}