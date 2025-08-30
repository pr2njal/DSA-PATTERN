#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Problem Statement:
Given a string s containing just the characters
'(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

A string is valid if:
 1. Open brackets are closed by the same type of brackets
 2. Open brackets are closed in the correct order

Example:
Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false
-----------------------------------------------------
*/

/*
=====================================================
 Approach: Using Stack
-----------------------------------------------------
1. Traverse each character in the string.
2. If it’s an opening bracket ('(', '{', '['), push it onto the stack.
3. If it’s a closing bracket:
   - Check if the stack is empty → invalid
   - Otherwise, check top of stack:
        '(' matches ')'
        '{' matches '}'
        '[' matches ']'
     If mismatch → invalid
   - Pop the matching opening bracket
4. At the end, if the stack is empty → valid, else invalid.

⏱ Complexity:
- Time:  O(n) (each character processed once)
- Space: O(n) (stack in worst case all opens)
=====================================================
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            // If opening bracket, push
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If closing and stack is empty → invalid
                if(st.empty()) return false;
                char top = st.top();
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false; // mismatch
                }
                st.pop(); // matched successfully
            }
        }
        return st.empty();
    }
};

/*
-----------------------------------------------------
🔹 Driver Code
-----------------------------------------------------
*/
int main() {
    Solution sol;

    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "({[]})";

    cout << sol.isValid(s1) << endl; // 1 (true)
    cout << sol.isValid(s2) << endl; // 0 (false)
    cout << sol.isValid(s3) << endl; // 1 (true)

    return 0;
}
