// TC-o(n)
// SC-o(1)

#include <iostream>
#include <string.h>
using namespace std;

void convertToUpperCase(char arr[]) {
  int n = strlen(arr);
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 'a' && arr[i] <= 'z')
      arr[i] = arr[i] - 'a' + 'A';
  }
}

int main() {
  char arr[100];
  cin >> arr;
  convertToUpperCase(arr);
  cout << arr;
}