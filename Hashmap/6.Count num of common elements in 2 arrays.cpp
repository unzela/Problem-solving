#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int countCommonElements(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> elementsInA;
    int count = 0;

    // Add elements of array a to the set
    for (int num : a) {
        elementsInA.insert(num);
    }

    // Check elements of array b against the set
    for (int num : b) {
        if (elementsInA.find(num) != elementsInA.end()) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 5};
    vector<int> b = {3, 4, 5, 6, 7};
    int commonCount = countCommonElements(a, b);
    cout << "Number of common elements: " << commonCount << endl;
    return 0;
}
