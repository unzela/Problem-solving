#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 1 based indexing;

// TC - o(n^2) - Not optimized
// SC - O(1)
// int firstRepeatingElement(vector<int> arr) {
//   bool isRepeated = false;
//   for (int i = 0; i < arr.size(); i++) {
//     for (int j = i + 1; j < arr.size(); j++) {
//       if (arr[i] == arr[j]) {
//         isRepeated = true;
//         return i + 1;
//       }
//     }
//   }
//   return -1;
// }

// TC - o(n)
// SC - O(1)
int firstRepeatingElement(vector<int> arr) {
  unordered_map<int, int> hash; // by default initialized with 0
  for (int i = 0; i < arr.size(); i++) {
    hash[arr[i]]++;
  }
  for (int i = 0; i < arr.size(); i++) {
    if (hash[arr[i]] > 1)
      return i + 1;
  }
  return -1;
}

int main() {
  vector<int> arr{1, 3, 2, 4, 2, 7};
  int ans = firstRepeatingElement(arr);
  cout << "First repeating element is found at index " << ans;
}