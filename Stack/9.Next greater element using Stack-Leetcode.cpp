// Given a circular integer array A, return the next greater element for every
// element in A. The next greater element for an element x is the first element
// greater than x that we come across while traversing the array in a clockwise
// manner. If it doesn’t exist, return -1 for this element.

// TC-O(2N+2N) = O(N)
// SC-O(N)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Since this can be the NGE for some other element, we push it in stack.
// Keep popping from the stack until the element at the top of the stack is
// smaller than A[i]
// If the top element of S is greater than A[i] then this is NGE of A[i] and we
// will assign it to res[i], where res is the resultant array. If the stack
// becomes empty then it implies that no element at the right of A[i] is greater
// than it and we assign -1. At last, we push A[i] in S.
vector<int> nextGreaterElements(vector<int> &nums) {
  int n = nums.size();
  vector<int> nge(n, -1);
  stack<int> st;

  // Start from end of array
  // 2n-1 for circular iteration
  // Replace [i%n] by i for non circular iteration
  for (int i = 2 * n - 1; i >= 0; i--) {             // TC-O(2N)
    while (!st.empty() && st.top() <= nums[i % n]) { // TC-O(2N)
      st.pop();
    }

    if (i < n) { // nge will only be there for n elements and not 2n
      if (!st.empty())
        nge[i] = st.top();
    }
    st.push(nums[i % n]);
  }
  return nge;
}

int main() {
  vector<int> arr{5, 7, 1, 2, 6, 0};
  vector<int> res = nextGreaterElements(arr);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}