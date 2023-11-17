// TC-o(n)
// SC-o(1)

// TC-o(n)
// SC-o(1)
#include <iostream>
#include <string.h>
using namespace std;

bool compareStrings(string a, string b) {
  if (a.length() != b.length())
    return false;

  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string a;
  string b;
  cin >> a >> b;
  cout << compareStrings(a, b);
}