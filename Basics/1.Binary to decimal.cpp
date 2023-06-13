#include <cmath>
#include <iostream>
using namespace std;

int binaryToDecimal(int n) {
  int decimal = 0, i = 0;
  while (n > 0) {
    int bit = n % 10; // last bit ot binary number
    decimal = decimal + bit * pow(2, i++);
    n = n / 10;
  }
  return decimal;
}

int main() {
  int n;
  cout << "Enter a binary number ";
  cin >> n;

  int decimalNo = binaryToDecimal(n);
  cout << "Its decimal representation is " << decimalNo << endl;
}