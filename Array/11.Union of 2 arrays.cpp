#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<int> unionOfArray(vector<int> array_one, vector<int> array_two) {
  for (auto val : array_two) {
    if (val != INT_MIN) {
      array_one.push_back(val);
    }
  }
  return array_one;
}

int main() {
  vector<int> array_one{1, 2, 3, 4, 5, 6, 9, 8};
  vector<int> array_two{2, 2, 3, 4, 4, 8, 7, 9};

  for (int i = 0; i < array_one.size(); i++) {
    for (int j = 0; j < array_two.size(); j++) {
      if (array_one[i] == array_two[j]) {
        array_two[j] = INT_MIN;
      }
    }
  }

  array_one = unionOfArray(array_one, array_two);
  for (auto val : array_one) {
    cout << val << endl;
  }

  return 0;
}
