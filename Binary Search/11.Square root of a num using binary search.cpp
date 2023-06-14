#include <iostream>
#include <vector>
using namespace std;

int squareRoot(int num) {
  int start = 0;
  int end = num;
  int mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    if (mid * mid == num)
      return mid;
    else if (mid * mid > num) // Left Search
      end = mid - 1;
    else {
      ans = mid;       // Store ans
      start = mid + 1; // Right search
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}

int main() {
  int num, result;
  cout << "Enter a number ";
  cin >> num;

  result = squareRoot(num);
  cout << "Sqaure root of " << num << " is " << result;

  int precision;
  cout << "\nEnter the no of floating digits in precision ";
  cin >> precision;

  double step = 0.1;
  double finalAns = result;
  for (int i = 0; i < precision; i++) {
    for (double j = finalAns; j * j <= num; j = j + step) {
      finalAns = j;
    }
    step = step * 0.1;
  }
  cout << "Final answer " << finalAns;
  return 0;
}
