// Write function to find longest common prefix amongst an array of strings. If
// there is not common prefix, return an empty string"""

#include <iostream>
#include <vector>
using namespace std;

// 2 Pointer approach
string longestCommonPrefix(vector<string> &s) {
  string ans;
  int i = 0; // to iterate over ith char of every string

  while (true) {
    char curr_char = 0;
    for (auto str : s) {
      if (i >= str.size()) {
        curr_char = 0; // Out of bound
        break;
      }

      if (curr_char == 0) { // Just started
        curr_char = str[i];
      } else if (str[i] != curr_char) {
        curr_char = 0; // Different
        break;
      }
    }
    if (curr_char == 0) {
      break;
    }
    ans.push_back(curr_char);
    i++;
  }
  return ans;
}

int main() {
  vector<string> str{"flower", "flow", "flight"};
  cout << longestCommonPrefix(str);
  return 0;
}