// TC - o(n)
// SC - o(n) as created another ans string
#include <iostream>
#include <string.h>
using namespace std;

string removeDuplicates(string s) {
  string ans = "";
  int i = 0;

  while (i < s.length()) {
    if ((ans.length() - 1 >= 0) && (ans[ans.length() - 1] == s[i])) {
      ans.pop_back();
    } else {
      ans.push_back(s[i]);
    }
    i++;
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << removeDuplicates(s);
}