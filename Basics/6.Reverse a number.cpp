#include <climits>
#include <iostream>
using namespace std;

int reverse(int n) {
  int ans = 0;
  bool isNegative = false;

  if (n <= INT_MIN) {
    return 0;
  }

  if (n < 0) {
    isNegative = true;
    n = -n;
  }

  while (n > 0) {
    if (ans > INT_MAX / 10) {
      return 0;
    }
    int rem = n % 10;
    ans = ans * 10 + rem;
    n = n / 10;
  }
  return isNegative ? -ans : ans;
}

int main() {
  int n;
  cout << "Enter a number ";
  cin >> n;

  int result = reverse(n);
  cout << "Reverse of " << n << " is " << result;
}