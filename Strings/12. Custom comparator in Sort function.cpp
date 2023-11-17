#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool cmp(char first, char second) {
  return first > second; // false - to sort in desc order
}

bool compare(int first, int second) { return first > second; }

int main() {
  string s = "Helloo";
  vector<int> arr{11, 4, 9, 7, 3, 0};
  sort(s.begin(), s.end(), cmp);
  cout << s << endl;

  sort(arr.begin(), arr.end(), compare);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}