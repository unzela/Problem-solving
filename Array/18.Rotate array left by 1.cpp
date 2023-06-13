#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cout << "Enter the numbers of elements ";
  cin >> n;
  vector<int> arr(n);

  cout << "Enter the elements: ";
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < arr.size() - 1; i++) {
    swap(arr[i], arr[i + 1]);
  }

  cout << "Rotated array by is ";

  for (auto val : arr) {
    cout << val << " ";
  }
  cout << endl;
}