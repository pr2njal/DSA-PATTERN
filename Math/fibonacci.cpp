#include <iostream>
using namespace std;

/*
Problem Statement:
------------------
Find the n-th Fibonacci number.

The Fibonacci sequence is defined as:
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) for n >= 2

Examples:
---------
- Input: 5 => Output: 5  (Sequence: 0, 1, 1, 2, 3, 5)
- Input: 8 => Output: 21 (Sequence: ..., 8, 13, 21)

Approach:
---------
Iterative (Bottom-Up) Dynamic Programming:
1. Handle base cases: n = 0 or n = 1.
2. Use two variables to store the previous two Fibonacci numbers.
3. Loop from 2 to n, and compute the current Fibonacci number using the sum of the previous two.
4. Return the final result.
*/

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0;  // F(0)
    int prev1 = 1;  // F(1)
    int current;

    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int n;
    cout << "Enter the position (n >= 0): ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci number is not defined for negative positions." << endl;
    } else {
        cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    }

    return 0;
}
