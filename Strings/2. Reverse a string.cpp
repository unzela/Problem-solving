// 2 pointer approach
// Array is passed by reference, so any changes are reflected in main
// TC of both functions - o(n)
// SC of both functions - o(1)
#include <iostream>
#include <string>
using namespace std;

int getLength(char arr[]) {
  int length = 0;
  int i = 0;

  while (arr[i] != '\0') {
    length++;
    i++;
  }
  return length;
}

void reverseStr(char arr[]) {
  int i = 0;
  int n = getLength(arr);
  int j = n - 1;

  while (i <= j) { // for( ; i<=j ;)
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
}

int main() {
  char arr[100];
  cin >> arr;
  cout << "Reverse of sting " << arr << " is: ";
  reverseStr(arr);
  cout << arr;
  return 0;
}