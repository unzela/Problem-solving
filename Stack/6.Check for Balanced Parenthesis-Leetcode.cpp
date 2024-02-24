// TC - O(N)
// SC - O(N)
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
    } else {
      if (st.empty()) { // or st.size()==0
        return false;
      }
      char ch = st.top();
      st.pop();
      if ((s[i] == ')' && ch == '(') || (s[i] == '}' && ch == '{') ||
          (s[i] == ']' && ch == '['))
        continue;
      else
        return false;
    }
  }
  return st.empty(); // If its balanced then stack will be empty
}

int main() {
  string s = "()[{}()]";
  if (isValid(s)) {
    cout << "True";
  } else
    cout << "False";
  return 0;
}