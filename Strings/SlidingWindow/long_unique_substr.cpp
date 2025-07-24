/*
Problem: Longest Substring Without Repeating Characters

Approach:
- Use sliding window with two pointers: left and right.
- Use an unordered_map to store last seen index of characters.
- If character repeats, move left pointer past the last seen index.
- Track max window size.

Time Complexity: O(n)
Space Complexity: O(128) => O(1) constant space (ASCII chars)
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int maxLen = 0, left = 0;

    for (int right = 0; right < s.length(); ++right) {
        char ch = s[right];

        if (lastIndex.find(ch) != lastIndex.end() && lastIndex[ch] >= left) {
            left = lastIndex[ch] + 1;
        }

        lastIndex[ch] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = lengthOfLongestSubstring(input);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
