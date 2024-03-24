// Given an array of integers heights representing the histogram’s bar height where the width of each bar is 1  return the area of the largest rectangle in
// histogram.

// TC - O(N)
// SC - O(3N) ,3 is for the stack, left small array and a right small array
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 2 pass solution
int largestRectangleArea(vector<int> &heights) {
  stack<int> st;
  int n = heights.size();
  int leftSmall[n], rightSmall[n];
  int maxArea = 0;

  // To compute left small
  for (int i = 0; i <= n; i++) {
    while (!st.empty() && heights[st.top()] >= heights[i]) {
      st.pop();
    }
    if (st.empty()) {
      leftSmall[i] = 0;
    } else {
      leftSmall[i] = st.top() + 1;
    }
    st.push(i);
  }

  // clear the stack to be re-used
  while (!st.empty()) {
    st.pop();
  }

  // To compute right small
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && heights[st.top()] >= heights[i])
      st.pop();

    if (st.empty())
      rightSmall[i] = n - 1;
    else
      rightSmall[i] = st.top() - 1;

    st.push(i);
  }

  for (int i = 0; i < n; i++) {
    maxArea = max(maxArea, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
  }

  return maxArea;
}

int main() {
  vector<int> histogram = {2, 1, 5, 6, 2, 3, 1};
  cout << "The largest area in the histogram is "
       << largestRectangleArea(histogram) << endl;
  return 0;
}