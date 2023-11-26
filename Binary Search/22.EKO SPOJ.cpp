// https://www.spoj.com/problems/EKO/cstart=80

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<long long int> trees, long long int m,
                        long long int mid) {
  long long int woodCollected = 0;
  for (long long int i = 0; i < trees.size(); i++) {
    if (trees[i] > mid) {
      woodCollected += trees[i] - mid;
    }
  }
  return woodCollected >= m;
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int m) {
  long long int start = 0, ans = -1;
  long long int end = *max_element(trees.begin(), trees.end());

  while (start <= end) {
    long long int mid = start + (end - start) / 2;
    if (isPossibleSolution(trees, m, mid)) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  long long int n, m;
  vector<long long int> trees; //{20,15,10,17}
  cout << "Enter the value of n : " << endl;
  cin >> n; // 4
  cout << "Enter the value of m : " << endl;
  cin >> m; // 7

  while (n--) {
    long long int height;
    cin >> height;
    trees.push_back(height);
  }
  cout << maxSawBladeHeight(trees, m); // 15
  return 0;
}