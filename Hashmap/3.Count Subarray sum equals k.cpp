#include <iostream>
#include <map>
#include <vector>
using namespace std;

// TC-O(n^3)
int findAllSubarraysWithGivenSumBruteForce(vector<int> &arr, int k) {
  int n = arr.size();
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {

      // calculate the sum of subarray [i...j]
      int sum = 0;
      for (int K = i; K <= j; K++)
        sum += arr[K];

      if (sum == k)
        cnt++;
    }
  }
  return cnt;
}

// TC-O(n^2)
// SC-O(1)
int findAllSubarraysWithGivenSumBetterApproach(vector<int> &arr, int k) {
  int n = arr.size();
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      // calculate the sum of subarray [i...j]
      // sum of [i..j-1] + arr[j]
      sum += arr[j];

      if (sum == k)
        cnt++;
    }
  }
  return cnt;
}

// TC-O(N) or O(N*logN) depending on map
// SC-O(N) as we are using map
int findSubarraysWithGivenSum(vector<int> &arr, int k) {
  map<int, int> mpp; // mpp=(preSum,Count)
  mpp[0] = 1;        // Setting 0 in the map with value 1
  int preSum = 0;
  int count = 0;
  for (int i = 0; i < arr.size(); i++) {
    preSum += arr[i];        // add current element to prefix Sum:
    int remove = preSum - k; // Calculate x-k:
    count += mpp[remove];    // Add the number of subarrays to be removed
    mpp[preSum] += 1;        // Update the count of prefix sum in the map
  }
  return count;
}

int main() {
  vector<int> arr{3, 1, 2, 4};
  int k = 6;
  cout << findAllSubarraysWithGivenSumBruteForce(arr, k) << endl;
  cout << findAllSubarraysWithGivenSumBetterApproach(arr, k) << endl;
  cout << findSubarraysWithGivenSum(arr, k) << endl;

  return 0;
}