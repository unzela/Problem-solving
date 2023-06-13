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
      int element2 = arr[j];

      for (int k = j + 1; k < arr.size(); k++) {
        int element3 = arr[k];

        if (element + element2 + element3 == sum)
          cout << "Found Pair " << element << "," << element2 << "," << element3
               << endl;
      }
    }
  }
}