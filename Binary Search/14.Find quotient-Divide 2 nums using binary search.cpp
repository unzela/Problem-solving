#include <iostream>
#include <vector>
using namespace std;

// quotient * divisor + reminder = dividend
// quotient * divisor  <= dividend
// quotient = mid
double divideNumberBinarySearch(int dividend, int divisor) {
  int start = abs(divisor);
  int end = abs(dividend);
  int mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    if (abs(mid * divisor) == abs(dividend)) {
      // ans = mid;
      return mid;
      // break;
    } else if (abs(mid * divisor) > abs(dividend)) {
      end = mid - 1;
    } else {
      ans = mid;       // store ans
      start = mid + 1; // right search
    }

    mid = start + (end - start) / 2;
  }

  double finalAns = ans;
  double step = 0.1;
  for (int i = 0; i < 3; i++) { // precision=3
    for (double j = finalAns; j * j <= abs(dividend); j += step) {
      finalAns = j;
    }
    step = step * 0.1;
  }

  if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0))
    return finalAns;
  else
    return -finalAns;
}

int main() {
  int dividend = 10;
  int divisor = -4;
  double result;
  result = divideNumberBinarySearch(dividend, divisor);
  cout << "Quotient is " << result << endl;

  return 0;
}
