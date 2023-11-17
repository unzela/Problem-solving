#include <iostream>
using namespace std;

int main() {
  int a = 5;
  int *ptr = &a;

  cout << "Address of a is " << &a << endl;
  cout << "Value stored at ptr is " << ptr << endl;
  cout << "Value ptr is pointind to is" << *ptr << endl;
  cout << &ptr << endl;

  int b = 5;
  int *p = &b;
  cout << sizeof(p) << endl;

  char ch = 'a';
  char *c = &ch;
  cout << sizeof(c) << endl;

  double d = 5.231;
  double *dtr = &d;
  cout << sizeof(dtr) << endl;

  // Bad Practice
  int *pointer;
  cout << *pointer << endl;

  // NULL Pointer
  int *ptrr = 0;
  // or int *ptrr = NULL;
  // or int *ptrr = nullptr;
  cout << *ptrr;

  // Copy Pointer
  int x = 5;
  int *firstPtr = &a;
  int *secondPtr = firstPtr;

  cout << firstPtr << endl;
  cout << secondPtr;
}