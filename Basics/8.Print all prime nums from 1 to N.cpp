#include <iostream>
using namespace std;

bool checkPrime(int n) {
  int i = 2;
  for (i = 2; i < n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n;
  cout << "Enter a number ";
  cin >> n;

  for (int i = 2; i <= n; i++) {
    bool ans = checkPrime(i);
    if (ans) {
      cout << i << " ";
    }
  }
}