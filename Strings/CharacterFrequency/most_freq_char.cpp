/*
Problem: Most Frequent Character(s) in a String

Approach:
1. Use an unordered_map to store character frequencies.
2. Convert characters to lowercase for case-insensitive comparison.
3. Ignore spaces and non-alphabetic characters.
4. Find the character(s) with the highest frequency.

Time Complexity: O(n), where n is the length of the string
Space Complexity: O(1), since there are only 26 lowercase letters
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cctype>
using namespace std;

void mostFrequentCharacters(const string& s) {
    unordered_map<char, int> freq;
    int maxFreq = 0;

    for (char ch : s) {
        if (isalpha(ch)) {
            char lowerCh = tolower(ch);
            freq[lowerCh]++;
            maxFreq = max(maxFreq, freq[lowerCh]);
        }
    }

    vector<char> result;
    for (const auto& pair : freq) {
        if (pair.second == maxFreq) {
            result.push_back(pair.first);
        }
    }

    cout << "Most frequent character(s): ";
    for (char ch : result) {
        cout << ch << " ";
    }
    cout << "\nFrequency: " << maxFreq << endl;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    mostFrequentCharacters(input);
    return 0;
}
