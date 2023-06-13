#include <iostream>
using namespace std;

int main() {
  // int digit[] = {4, 8, 2, 6};
  // int ans = 0;
  // for (int i = 0; i < 4; i++) {
  //   ans = ans * 10 + digit[i];
  // }
  // cout << ans << endl;

  int n;
  cout << "Enter the count of digits ";
  cin >> n;
  int arr[10];
  cout << "Enter the digits ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans1 = 0;
  for (int i = 0; i < n; i++) {
    ans1 = ans1 * 10 + arr[i];
  }
  cout << "Formed number " << ans1;
}