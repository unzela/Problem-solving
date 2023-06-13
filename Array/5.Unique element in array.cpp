// https://leetcode.com/problems/single-number/

#include <iostream>
#include <vector>

using namespace std;

int findUniqueNumber(int num, vector<int> arr) {
  cout << "Enter the numbers in array" << endl;
  for (int i = 0; i < num; i++) {
    cin >> arr[i];
  }

  int ans = 0;
  for (auto val : arr) {
    ans = ans ^ val;
  }
  return ans;
}

int main() {
  int num;
  cout << "Enter size of array" << endl;
  cin >> num;
  vector<int> arr(num);
  num = findUniqueNumber(num, arr);
  cout << "Unique number is " << num << endl;

  return 0;
}
