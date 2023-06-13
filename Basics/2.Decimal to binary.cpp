#include <cmath>
#include <iostream>
using namespace std;

// Division Method
int decimalToBinaryMethod1(int n) {
  int binaryNo = 0;
  int i = 0;

  while (n > 0) {
    int bit = n % 2;
    binaryNo = bit * pow(10, i++) + binaryNo;
    // To reverse the digits/bits to form the no got by division
    n = n / 2;
  }
  return binaryNo;
}

// Bitwise Method
int decimalToBinaryMethod2(int n) {
  int binaryNo = 0;
  int i = 0;

  while (n > 0) {
    int bit = (n & 1);
    binaryNo = bit * pow(10, i++) + binaryNo;
    n = n >> 1;
  }
  return binaryNo;
}

int main() {
  int n;
  cout << "Enter a decimal number ";
  cin >> n;

  int result = decimalToBinaryMethod1(n);
  cout << "Its binary representation is " << result << endl;
  int result1 = decimalToBinaryMethod2(n);
  cout << "Its binary representation is " << result1 << endl;
}