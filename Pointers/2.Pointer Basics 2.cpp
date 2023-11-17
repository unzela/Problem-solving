#include <iostream>
using namespace std;

void solve(int arr[]) {
  cout << "Size inside solve function " << sizeof(arr) << endl;
  cout << "Arr :" << arr << endl;
  cout << "&arr :" << &arr << endl;
  arr[0] = 50;
}

void update(int *p) {
  cout << "Address stored inside p is :" << p << endl;
  cout << "Address of p is :" << &p << endl;
  *p = *p + 10;
}

int main() {
  // int arr[4] = {2, 4, 6, 1};
  // int *p = arr;

  // cout << arr << endl;
  // cout << arr[0] << endl;
  // cout << &arr << endl;
  // cout << &arr[0] << endl;

  // cout << p << endl;
  // cout << &p << endl;

  // cout << *arr << endl;
  // cout << *arr + 1 << endl;
  // cout << *(arr) + 1 << endl;
  // cout << *(arr + 1) << endl;
  // cout << arr[1] << endl;
  // cout << *(arr + 2) << endl;
  // cout << arr[2] << endl;

  // int i = 0;
  // cout << arr[i] << endl;
  // cout << i[arr] << endl;
  // cout << *(arr + i) << endl;
  // cout << *(arr + i) << endl;

  // cout << sizeof(arr) << endl;
  // cout << sizeof(p) << endl;

  // char ch[10] = "Unzela";
  // char *c = ch;

  // cout << ch << endl;
  // cout << &ch << endl;
  // cout << ch[0] << endl;
  // cout << &c << endl;
  // cout << *c << endl;
  // cout << c << endl;

  // char name[14] = "UnzelaInamdar";
  // char *cptr = &name[0];

  // cout << name << endl;
  // cout << &name << endl;
  // cout << *(name + 3) << endl;
  // cout << cptr << endl;
  // cout << &cptr << endl;
  // cout << *(cptr + 3) << endl;
  // cout << cptr + 2 << endl;
  // cout << *cptr << endl;
  // cout << cptr + 8 << endl;

  // int arr[6] = {1, 4, 6, 8};
  // cout << "Size inside main function :" << sizeof(arr) << endl;
  // cout << arr << endl;
  // cout << &arr << endl;

  // printing array inside main
  // for (int i = 0; i < 10; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;
  // cout << "Now calling solve function: " << endl;
  // solve(arr);

  // cout << "Now again in main function " << endl;
  // for (int i = 0; i < 10; i++) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;

  int a = 5;
  int *ptr = &a;
  cout << "Address of a is :" << &a << endl;
  cout << "Address stored in ptr is :" << ptr << endl;
  cout << "Address of ptr is :" << &ptr << endl;
  update(ptr);
  cout << "Valur of a is :" << a << endl;
  return 0;
}