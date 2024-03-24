// Given an array of integers heights representing the histogram’s bar height
// where the width of each bar is 1  return the area of the largest rectangle in
// histogram.

// TC - O(N)+O(N)
// SC - O(N)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Single pass solution
int largestRectangleArea(vector<int> &histogram) {
  stack<int> st;
  int n = histogram.size();
  int maxArea = 0;

  for (int i = 0; i <= n; i++) {
    while (!st.empty() && (i == n || histogram[st.top()] >= histogram[i])) {
      int height = histogram[st.top()];
      st.pop();

      int width;
      if (st.empty()) {
        width = i;
      } else {
        width = i - st.top() - 1;
      }
      maxArea = max(maxArea, height * width);
    }
    st.push(i);
  }
  return maxArea;
}

int main() {
  vector<int> histogram = {2, 1, 5, 6, 2, 3, 1};
  cout << "The largest area in the histogram is "
       << largestRectangleArea(histogram) << endl;
  return 0;
}