#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, a, sum;
  vector<int> arr;
  vector<int> ans;

  cout << "Enter the size of array ";
  cin >> n;
  cout << "Enter the elements " << endl;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr.push_back(a);
  }

  cout << "Enter the sum you want to find from pair ";
  cin >> sum;

  for (int i = 0; i < arr.size(); i++) {
    int element = arr[i];

    for (int j = i + 1; j < arr.size(); j++) {
      // cout << "(" << arr[i] << "," << arr[j] << ")";
      if (element + arr[j] == sum)
        cout << "Found Pair " << element << "," << arr[j] << endl;
    }
  }
}