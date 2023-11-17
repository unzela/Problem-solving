// Sort an array of 0,1,2
#include <iostream>
#include <vector>
using namespace std;

// void sortColors(vector<int> nums) { // TC-O(n) SC-O(1)
// int zeros, ones, twos;
// zeros = ones = twos = 0;

// for (int i = 0; i < nums.size(); i++) {
//   if (nums[i] == 0)
//     zeros++;
//   else if (nums[i] == 1)
//     ones++;
//   else
//     twos++;
// }

// // Spread then back in array
// int i = 0;
// while (zeros--) {
//   nums[i] = 0;
//   i++;
// }
// while (ones--) {
//   nums[i] = 1;
//   i++;
// }
// while (twos--) {
//   nums[i] = 2;
//   i++;
// }
// }

void sortColors(vector<int> &nums) {
  int low = 0;
  int med = 0;
  int high = nums.size() - 1;

  while (med <= high) {
    if (nums[med] == 0) {
      swap(nums[med], nums[low]);
      med++;
      low++;
    } else if (nums[med] == 1) {
      med++;
    } else if (nums[med] == 2) {
      swap(nums[med], nums[high]);
      high--;
    }
  }
}

int main() {
  vector<int> nums = {2, 1, 2, 1, 0, 0, 1};
  sortColors(nums);

  for (auto val : nums) {
    cout << val << " ";
  }

  return 0;
}