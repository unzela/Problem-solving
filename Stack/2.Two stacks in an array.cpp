#include <iostream>
using namespace std;

class Stack {
public:
  int *arr;
  int size;
  int top1;
  int top2;

  Stack(int size) {
    arr = new int[size];
    this->size = size;
    top1 = -1;
    top2 = size;
  }

  void push1(int data) {
    if (top2 - top1 == 0) {
      cout << "Overflow in Stack 1" << endl;
    } else {
      top1++;
      arr[top1] = data;
    }
  }

  void pop1() {
    if (top1 == -1) {
      cout << "Underflow in stack 1 " << endl;
    } else {
      arr[top1] = 0; // Just marking it as 0
      top1--;
    }
  }

  void push2(int data) {
    if (top2 - top1 == 0) {
      cout << "Overflow in Stack 2" << endl;
    } else {
      top2--;
      arr[top2] = data;
    }
  }

  void pop2() {
    if (top2 == size) {
      cout << "Underflow in stack 2 " << endl;
    } else {
      arr[top2] = 0;
      top2++;
    }
  }

  void print() {
    cout << endl;
    cout << "Top 1 :" << top1 << endl;
    cout << "Top 2 :" << top2 << endl;
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Stack s(10);
  s.push1(10);
  s.print();
  s.push1(20);
  s.print();
  s.push1(30);
  s.print();
  s.push1(40);
  s.print();
  s.push1(50);
  s.print();

  s.push2(100);
  s.print();
  s.push2(200);
  s.print();
  s.push2(300);
  s.print();
  s.push2(400);
  s.print();
  s.push2(500);
  s.print();

  s.pop1();
  s.print();
  s.pop1();
  s.print();
  s.pop1();
  s.print();
  s.pop1();
  s.print();
  s.pop1();
  s.print();
  s.push2(1000);
  s.print();
  s.pop1();
  s.print();

  return 0;
}