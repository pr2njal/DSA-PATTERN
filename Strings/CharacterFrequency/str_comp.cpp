/*
Problem: String Compression

Approach:
1. Traverse the string and count consecutive repeating characters.
2. Append the character and its count to the result string.
3. If the compressed string is not shorter, return the original.

Time Complexity: O(n)
Space Complexity: O(n) for the result string
*/

#include <iostream>
#include <string>
using namespace std;

string compressString(const string& s) {
    string compressed = "";
    int count = 1;

    for (int i = 1; i <= s.length(); ++i) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            compressed += s[i - 1] + to_string(count);
            count = 1;
        }
    }

    return compressed.length() < s.length() ? compressed : s;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = compressString(input);
    cout << "Compressed string: " << result << endl;

    return 0;
}
