#include <iostream>
using namespace std;

int main() {
  // Count of Set bits is the number of 1's in the binary representation
  int n, ans = 0;
  cout << "Enter a number ";
  cin >> n;

  while (n != 0) {
    if (n & 1) {
      ans++; // Found 1 set bit so increment the ans
    }
    n = n >> 1; // Right shift
  }
  cout << "Number of set bits " << ans;
}