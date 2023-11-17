#include <iostream>
using namespace std;

void util(int *p) {
  // p = p + 1; //5 - pass by value - copy is created
  *p = *p + 1; // 6 - copy is not created, value is changed at original address
}

void solve(int **ptr) {
  ptr = ptr + 1;
  *ptr = *ptr + 1;
  **ptr = **ptr + 1;
}

void passByValue(int val) { // Pass by  value
  val++;
}

void passByReference(int &val) { // Pass by Reference
  val++;
}

void passingAddress(int *val) { *val = *val + 1; }

void test(int *&ptr) { ptr = ptr + 1; }

int main() {
  // int a = 5;
  // int *p = &a;
  // int **q = &p;

  // cout << &a << endl;
  // cout << a << endl;
  // cout << p << endl;
  // cout << &p << endl;
  // cout << *p << endl;
  // cout << q << endl;
  // cout << &q << endl;
  // cout << *q << endl;
  // cout << **q << endl;

  // cout << "Before" << endl;
  // cout << a << endl;
  // cout << p << endl;
  // cout << *p << endl;

  // util(p);
  // cout << "After" << endl;
  // cout << a << endl;
  // cout << p << endl;
  // cout << *p << endl;

  // solve(q);
  // cout << a << endl;

  //-----------Reference Variable---------
  // int x = 2;
  // int &b = a;
  // cout << x << endl;
  // cout << b << endl;
  // x++;
  // cout << x << endl;
  // cout << b << endl;
  // b++;
  // cout << x << endl;
  // cout << b << endl;

  // int w = 9;
  // passByValue(w);
  // cout << w << endl;
  // passByReference(w);
  // cout << w << endl;

  //----------
  // int s = 5;
  // passingAddress(&s);
  // cout << s << endl;

  // int a = 5;
  // int *p = &a;
  // cout << "Before " << p << endl;
  // test(p);
  // cout << "After " << p << endl;

  //-----------------
  int arr[10] = {2};
  cout << arr << endl << endl;
  int(*p)[10] = &arr;
  for (int i = 0; i < 10; i++) {
    cout << "Value :" << (*p)[i] << " Address :" << p[i] << endl;
  }
  return 0;
}