// Given a sorted array of positive integers. Your task is to rearrange the
// array elements alternatively i.e first element should be max value, second
// should be min value, third should be second max, fourth should be second min
// and so on.Note : Modify the original array itself.Do it without using any
// extra space.You do not have to return anything.

#include <iostream>
using namespace std;

void rearrange(int arr[], int n) {
  int max_index = n - 1;
  int min_index = 0;
  int max = arr[n - 1] + 1; // Divisor; Add 1 to find effective modulo

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      arr[i] = (arr[max_index] % max) * max + arr[i];
      max_index--;
    } else {
      arr[i] = (arr[min_index] % max) * max + arr[i];
      min_index++;
    }
  }
  for (int i = 0; i < n; i++) {
    arr[i] = arr[i] / max;
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};
  int size = sizeof(arr) / sizeof(arr[0]);
  rearrange(arr, size);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}