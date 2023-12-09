#include <iostream>
using namespace std;

// 2 Pointer approach
string reverseOnlyLetters(string s) {
  int low = 0;
  int high = s.size() - 1;
  while (low < high) {
    // if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
    if (isalpha(s[low]) && isalpha(s[high])) {
      swap(s[low], s[high]);
      low++;
      high--;
    } else if (!isalpha(s[low])) {
      low++;
    } else { //(!isalpha(s[high])
      high--;
    }
  }
  return s;
}

int main() {
  string str = "a-bC-dEf-ghIj";
  cout << reverseOnlyLetters(str);
  return 0;
}