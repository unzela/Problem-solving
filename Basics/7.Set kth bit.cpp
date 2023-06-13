// https://www.geeksforgeeks.org/set-k-th-bit-given-number/

// In this Qs we want to convert kth bit to 1.

#include <iostream>
using namespace std;

int setKthBit(int num, int k) {
  // As kth bit OR operation with 1, will result in 1 always as 0| 1 =>1 and 1 |
  // 1=> 1. So we will do left shift by kth on 1
  //  So if k is 2, then 1<<2=> 100.
  int mask = 1 << k;
  // If num is 10 then 10 binary will be 1010. So 1010 | 100 => 1110 => 14.
  return num | mask;
}

int main() {

  int num, k;
  cout << "Enter number" << endl;
  cin >> num;
  cout << "Enter kth bit to set" << endl;
  cin >> k;

  int output = setKthBit(num, k);
  cout << output;
  return 0;
}
