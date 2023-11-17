#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int minimumTimeDifference(vector<string> &timePoints) {
  // Step 1 - Convert time string to mins interger
  vector<int> minutes;
  for (int i = 0; i < timePoints.size(); i++) {
    string curr = timePoints[i];

    int hrs = stoi(curr.substr(0, 2));
    int min = stoi(curr.substr(3, 2));
    int totalMinutes = hrs * 60 + min;
    minutes.push_back(totalMinutes);
  }

  // Step 2 - Sort
  sort(minutes.begin(), minutes.end());

  // Step 3 - Difference and calculate min diff
  int minimum = INT_MAX;
  int n = minutes.size();
  for (int i = 0; i < n - 1; i++) {
    int diff = minutes[i + 1] - minutes[i];
    minimum = min(minimum, diff);
  }
  // Imp - Calculate diff with 1st and last element
  int lastDiff1 =
      (minutes[0] + 1440) -
      minutes[n - 1]; // last element of array is greater than 720 min
  int lastDiff2 = minutes[n - 1] - minutes[0]; //<720 min
  int lastDiff = min(lastDiff1, lastDiff2);
  minimum = min(minimum, lastDiff);

  return minimum;
}

int main() {
  vector<string> timePoints = {"23:50", "00:00"};
  cout << minimumTimeDifference(timePoints);
}