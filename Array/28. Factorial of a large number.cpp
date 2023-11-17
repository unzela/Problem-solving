#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> factorial(int N) {
  vector<int> ans;
  ans.push_back(1); // Initially ans[j]=1
  int carry = 0;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < ans.size(); j++) {
      int x = ans[j] * i + carry;
      ans[j] = x % 10;
      carry = x / 10;
    }
    while (carry) {
      ans.push_back(carry);
      carry /= 10;
    }
    carry = 0;
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return ans;
}

int main() {
  int n = 7;
  vector<int> ans = factorial(n);
  return 0;
}