/*
Problem: Valid Palindrome (LeetCode #125)

 Statement:
Given a string s, determine if it is a palindrome,
considering only alphanumeric characters and ignoring cases.

 Example 1:
Input:  "A man, a plan, a canal: Panama"
Output: true

 Example 2:
Input:  "race a car"
Output: false

----------------------------------------

 Approach: Two-Pointer Technique

1. Initialize two pointers — left at the beginning and right at the end of the string.
2. Skip non-alphanumeric characters using `isalnum()`.
3. Compare characters at left and right after converting both to lowercase using `tolower()`.
4. If any mismatch is found, return false.
5. If all characters matched, return true.

 Time Complexity: O(n), where n = length of the string
 Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <cctype> // for isalnum and tolower
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(s[left])) left++;
        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(s[right])) right--;

        // Compare characters ignoring case
        if (tolower(s[left]) != tolower(s[right])) return false;

        left++;
        right--;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input))
        cout << " It is a valid palindrome.\n";
    else
        cout << " It is not a valid palindrome.\n";

    return 0;
}
