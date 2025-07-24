/*
Problem: Generate All Permutations of a String

Approach:
- Use backtracking to generate all permutations.
- Swap characters at the current index with each index from current to end.
- Recurse for the next index.
- After recursion, backtrack by swapping back.

Time Complexity: O(n * n!) — total n! permutations, each taking O(n) time to print
Space Complexity: O(n) for recursion stack
*/

#include <iostream>
#include <string>
using namespace std;

void generatePermutations(string &s, int index) {
    // Base case: if index reaches the end, print permutation
    if (index == s.length()) {
        cout << s << endl;
        return;
    }

    for (int i = index; i < s.length(); ++i) {
        swap(s[i], s[index]);                     // Swap to fix a character
        generatePermutations(s, index + 1);       // Recurse for the rest
        swap(s[i], s[index]);                     // Backtrack
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "All permutations:\n";
    generatePermutations(input, 0);

    return 0;
}
