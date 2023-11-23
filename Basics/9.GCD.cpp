// GCD(a,b) = GCD(a-b, b), a>b
// GCD(a,b) = GCD(b-a, a), a<b
// GCD(a,b) = GCD(a%b, b), a>b
// LCM(a,b)*GCD(a,b)=a*b
// LCM= (a*b)/GCD(a,b)
#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;

  while (a > 0 && b > 0) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  return a == 0 ? b : a;
}

int main() {
  int a = 24;
  int b = 72;
  // Euclid's Algorithm
  cout << gcd(a, b);
}