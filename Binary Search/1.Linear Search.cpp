#include <iostream>
using namespace std;

int main() {
  int arr[10], key, n;
  cout << "Enter the size of array ";
  cin >> n;

  cout << "Enter the elements of array ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter the key to search ";
  cin >> key;

  bool flag = 0; // 0->Not Found 1->Found
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << "Present";
  } else {
    cout << "Not Found";
  }
}