#include <iostream>
#include <stack>
using namespace std;

void sortStackUsingAnotherStack(stack<int>& s1) {
    stack<int> s2;

    while (!s1.empty()) {
        int temp = s1.top();
        s1.pop();
        
        while (!s2.empty() && s2.top() > temp) {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(temp);
    }
    
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

int main() {
    stack<int> s1;
    s1.push(5);
    s1.push(2);
    s1.push(9);
    s1.push(1);
    s1.push(8);

    cout << "Original Stack: ";
    stack<int> temp = s1; 
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStackUsingAnotherStack(s1);

    cout << "Sorted Stack: ";
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    return 0;
}
