// https://www.spoj.com/problems/PRATA/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> cooksRanks, int nP, int mid) {
  int currP = 0; // Inital cooked paratha count
  for (int i = 0; i < cooksRanks.size(); i++) {
    int R = cooksRanks[i];
    int j = 1;
    int timeTaken = 0;

    while (true) {
      if (timeTaken + j * R <= mid) {
        ++currP;
        timeTaken += j * R;
        ++j;
      } else {
        break;
      }
    }
    if (currP >= nP) {
      return true;
    }
  }
  return false;
}

int minTimeToCompleteOrder(vector<int> cooksRanks, int nP) {
  int start = 0;
  int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
  int end = highestRank * (nP * (nP + 1) / 2);
  int ans = -1;

  while (start <= end) {
    int mid = start + end / 2;
    if (isPossibleSolution(cooksRanks, nP, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T; // No of test cases
  while (T--) {
    int nP, nC;
    cin >> nP >> nC;
    vector<int> cooksRanks;
    while (nC--) {
      int R;
      cin >> R;
      cooksRanks.push_back(R);
    }
    cout << minTimeToCompleteOrder(cooksRanks, nP) << endl;
  }
  return 0;
}

// Input:
//  10
//  4 1 2 3 4
//  8
//  1 1
//  8
//  8 1 1 1 1 1 1 1 1

// Output:
//  12
//  36
//  1