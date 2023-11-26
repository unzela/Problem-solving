// Given that there are N books and M students. Also given are the number of
// pages in each book in ascending order. The task is to assign books in such a
// way that the maximum number of pages assigned to a student is minimum, with
// the condition that every student is assigned to read some consecutive books.
// Print that minimum number of pages.

// TC- O(N*log(N)), Where N is the total number of pages in the book.
#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSolution(int arr[], int N, int M, int sol) { // Sol= mid
  int pageSum = 0;                                          // For current sum
  int counter = 1;

  for (int i = 0; i < N; i++) {
    if (arr[i] > sol) { // Current book to be allocated has more no of pages
                        //  than the solution
      return false;
    }
    if (pageSum + arr[i] > sol) {
      counter++; // Allocate to next student
      pageSum = arr[i];
      if (counter > M) { // No of allocations is more than no of students
        return false;
      }
    } else {
      pageSum += arr[i];
    }
  }
  return true;
}

// Function to fing minimum no of pages
int findPages(int arr[], int N, int M) {
  if (M > N) { // If no of books is greater than no of students
    return -1;
  }

  int start = 0;
  int ans = -1;
  int end = accumulate(arr, arr + N, 0);
  // Inbuilt method to fimd sum of all elements of array
  // Takes 3 params - initial address, end address and initial value of sum

  while (start <= end) {
    int mid = (start + end) / 2;
    if (isPossibleSolution(arr, N, M, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}

int main() {
  int arr[] = {12, 34, 67, 90};
  int N = 4;
  int k = 2;
  cout << findPages(arr, N, k);
  return 0;
}