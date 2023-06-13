#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> arr{1, 0, 0, 1, 0, 1, 0};

  int start = 0;
  int end = arr.size() - 1;
  int i = 0;
  while (start < end) {

    if (arr[i] == 0) {
      swap(arr[i], arr[start]);
      start++;
      i++;
    } else {
      swap(arr[i], arr[end]);
      end--;
    }
  }

  for (auto val : arr) {
    std::cout << val << std::endl;
  }

  return 0;
}
