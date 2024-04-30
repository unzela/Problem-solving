#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool isSubset(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> frequency;

    // Count the frequency of each element in arr2
    for (int num : arr2) {
        frequency[num]++;
    }

    // Check if all elements of arr1 are present in arr2
    for (int num : arr1) {
        if (frequency[num] == 0) {
            return false;
        }
        frequency[num]--;
    }
    return true;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 3};
    vector<int> arr2 = {3, 1, 2, 4, 5};

    if (isSubset(arr1, arr2)) {
        cout << "arr1 is a subset of arr2" << endl;
    } else {
        cout << "arr1 is not a subset of arr2" << endl;
    }

    return 0;
}
