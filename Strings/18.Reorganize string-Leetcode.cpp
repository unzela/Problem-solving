// Given a string s, rearrange the characters of s so that any two adjacent
// characters are not the same. Return any possible rearrangement of s or return
// "" if not possible.

#include <iostream>
#include <limits.h>
using namespace std;

string reorganiseString(string s) {
  int hash[26] = {0}; // Only small alphabets
  for (int i = 0; i < s.size(); i++) {
    hash[s[i] - 'a']++; // Counting the frequency of each character
    // Subract 97 to get 0
  }

  // Find the most frequent character
  char max_freq_char;
  int max_freq = INT_MIN;
  for (int i = 0; i < 26; i++) {
    if (hash[i] > max_freq) {
      max_freq = hash[i];
      max_freq_char = i + 'a';
    }
  }

  int index = 0;
  // Place char with max frequency at alternate or +2 index
  while (max_freq > 0 && index < s.size()) {
    s[index] = max_freq_char;
    max_freq--;
    index += 2;
  }
  if (max_freq != 0) { // Can't place char with max frequency
    return " ";
  }

  hash[max_freq_char - 'a'] = 0;

  // Lets place rest of the characters
  for (int i = 0; i < 26; i++) {
    while (hash[i] > 0) {
      index = index >= s.size() ? 1 : index;
      s[index] = i + 'a';
      hash[i]--;
      index += 2;
    }
  }
  return s;
}

int main() {
  string s = "aab";
  cout << reorganiseString(s) << endl;

  string s1 = "aaab"; // Returns  ""
  cout << reorganiseString(s1);
}