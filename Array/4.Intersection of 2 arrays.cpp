#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> intersection(vector<int> nums1, vector<int> nums2) {
  set<int> ans;

  for (auto val : nums1) {
    for (auto val2 : nums2) {
      if (val == val2) {
        ans.insert(val);  
        // break;
      }
    }
  }
  nums1.assign(ans.begin(), ans.end());
  return nums1;
}

int main() {
  vector<int> array_one{1, 2, 4, 5, 6, 9, 9, 9, 8};
  vector<int> array_two{9, 8, 7, 9};

  array_one = intersection(array_one, array_two);
  for (auto val : array_one) {
    cout << val << endl;
  }

  return 0;
}
