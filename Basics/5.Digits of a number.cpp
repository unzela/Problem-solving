#include <iostream>
using namespace std;
int main() {
  int n;
  cout << "Enter a number ";
  cin >> n;

  while (n != 0) {
    int rem = n % 10;
    cout << rem << " ";
    n = n / 10;
  }

  // Using for loop
  // for (; n != 0; n = n / 10) {
  //   int rem = n % 10;
  //   cout << rem << ",";
  // }
}