// https://leetcode.com/problems/string-compression/description/
// Run lenth encoding

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int compressString(vector<char> &s) {
  int index =
      0; // To store ans. Ponits to same input vector , its just another pointer
  int count = 1;
  char prev = s[0];

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == prev) {
      count++;
    } else {
      s[index++] = prev;
      if (count > 1) {
        int start = index;
        while (count) { // To store 2 digit number in 2 differnt indexes of
                        // array
          s[index++] = count % 10 + '0';
          count = count / 10;
        }
        reverse(s.begin() + start, s.begin() + index);
      }
      prev = s[i];
      count = 1; // Reset counter
    }
  }
  // Out of bound
  s[index++] = prev;
  if (count > 1) {
    int start = index;
    while (count) {
      s[index++] = count % 10 + '0'; // Int to char
      count = count / 10;
    }
    reverse(s.begin() + start, s.begin() + index);
  }
  return index;
}

int main() {
  vector<char> s = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'd'};
  int compressedSize = compressString(s);

  for (int i = 0; i < compressedSize; i++) {
    cout << s[i];
  }
}