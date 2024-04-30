#include <iostream>
#include <map>
using namespace std;

void max_occuring_char(string& s) {
    map<char, int> char_count;
    
    // Count occurrences of each character
    for (char c : s) {
        char_count[c]++;
    }
    
    // Find the character with the maximum count
    char max_char;
    int max_count = 0;
    for (const auto& pair : char_count) {
        if (pair.second > max_count) {
            max_char = pair.first;
            max_count = pair.second;
        }
    }
    
    cout << "The maximum occurring character is " << max_char << "' with a count of " << max_count << "." <<endl;
}

int main() {
    string str = "helloWorldddd";
    max_occuring_char(str);
    
    return 0;
}
