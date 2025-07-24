/*
Problem: Longest Repeating Character Replacement

Approach:
- Use sliding window from left to right.
- Track the count of the most frequent character in the current window.
- If (window size - maxFreq) > k, shrink the window from the left.
- Else, expand the window and update the max length.

Time Complexity: O(n)
Space Complexity: O(1) — constant space for 26 uppercase letters
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);
    int maxFreq = 0, maxLen = 0, left = 0;

    for (int right = 0; right < s.size(); ++right) {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // If we need to change more than k characters, shrink window
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s;
    int k;
    cout << "Enter the string (only uppercase letters): ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = characterReplacement(s, k);
    cout << "Longest substring length after at most " << k << " replacements: " << result << endl;

    return 0;
}
