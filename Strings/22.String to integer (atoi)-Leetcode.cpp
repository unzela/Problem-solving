// Implement the myAtoi(stri) function, which converts a string to a 32-bit
// signed integer (similar to C/C++'s atoi function)

#include <iostream>
#include <limits.h>
using namespace std;

int stringToInteger(string s) {
  int num = 0;
  int i = 0;
  int sign = 1; //+ve

  while (s[i] == ' ') {
    i++;
  }

  if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
    sign = s[i] == '+' ? 1 : -1;
    i++;
  }

  while (i < s.size() && isdigit(s[i])) {
    if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
      return sign == 1 ? INT_MAX : INT_MIN;
    }
    num = num * 10 + (s[i] - '0');
    i++;
  }
  return num * sign;
}

int main() {
  string str = "  -123hello45";
  cout << stringToInteger(str);
  return 0;
}