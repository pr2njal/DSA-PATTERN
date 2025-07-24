/*
Problem: Minimum Window Substring

Approach:
- Use two hash maps: one for characters needed (targetFreq), one for current window (windowFreq).
- Expand the right pointer to include valid characters.
- Once the current window has all required characters, try to shrink from the left.
- Update the minimum window if valid and smaller than previous.

Time Complexity: O(n)
Space Complexity: O(128) => O(1) for ASCII characters
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    unordered_map<char, int> targetFreq;
    for (char c : t) targetFreq[c]++;

    int left = 0, right = 0, required = targetFreq.size();
    int formed = 0;
    unordered_map<char, int> windowFreq;

    int minLen = INT_MAX;
    int startIndex = 0;

    while (right < s.length()) {
        char c = s[right];
        windowFreq[c]++;

        if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIndex = left;
            }

            char removeChar = s[left];
            windowFreq[removeChar]--;
            if (targetFreq.count(removeChar) && windowFreq[removeChar] < targetFreq[removeChar]) {
                formed--;
            }
            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    string result = minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;

    return 0;
}
