#include <iostream>
#include <string.h>
using namespace std;

string removeOccurences(string str, string part) {
  int pos = str.find(part);
  while (pos != string::npos) {
    str.erase(pos, part.length());
    pos = str.find(part);
  }
  return str;
}

int main() {
  string str, part;
  cin >> str >> part;
  cout << removeOccurences(str, part);
}