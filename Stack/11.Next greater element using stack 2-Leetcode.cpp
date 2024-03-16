// You are given two arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] ==
// nums2[j] and determine the next greater element of nums2[j] in nums2. If
// there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next
// greater element as described above.

// TC-O(2N+2N) = O(N)
// SC-O(N)
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(const vector<int> &nums1, const vector<int> &nums2) {
    int n = nums1.size();
    vector<int> ans(n, -1);
    stack<int> st;
    unordered_map<int, int> nextGreater;

    // Find next greater element for each element in nums2
    for (int i = 0; i < nums2.size(); ++i) {
        while (!st.empty() && nums2[i] > nums2[st.top()]) {
            nextGreater[nums2[st.top()]] = nums2[i];
            st.pop();
        }
        st.push(i);
    }

    // Populate the result for each element in nums1
    for (int i = 0; i < nums1.size(); ++i) {
        if (nextGreater.find(nums1[i]) != nextGreater.end()) {
            ans[i] = nextGreater[nums1[i]];
        }
    }

    return ans;
}

int main() {
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
