// TC - O(n1+n2+n3)
// SC - O(n1) -n1 is largest arr
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
  vector<int> ans;
  set<int> st;
  int i, j, k;
  i = j = k = 0;

  while (i < n1 && j < n2 && k < n3) {
    if (A[i] == B[j] && B[j] == C[k]) {
      // arr.push_back(A[i]);
      st.insert(A[i]); // to remove duplicate elements from array
      i++, j++, k++;
    } else if (A[i] < B[j]) {
      i++;
    } else if (B[j] < C[k]) {
      j++;
    } else {
      k++;
    }
  }

  for (auto i : st) {
    ans.push_back(i);
  }

  return ans;
}

int main() {
  int A[10] = {3, 3, 3, 1, 4, 2};
  int B[10] = {3, 3, 3, 4, 6, 8, 9};
  int C[10] = {3, 3, 3, 4, 6};
  int n1 = sizeof(A) / sizeof(A[0]);
  int n2 = sizeof(B) / sizeof(B[0]);
  int n3 = sizeof(B) / sizeof(C[0]);

  vector<int> ans = commonElements(A, B, C, n1, n2, n3);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}