#include <iostream>
using namespace std;

/*
Problem Statement:
------------------
Find the factorial of a given non-negative integer n.

The factorial of a number n is the product of all positive integers from 1 to n.
It is denoted by n!

Examples:
---------
- 5! = 5 × 4 × 3 × 2 × 1 = 120
- 0! = 1 (by definition)

Approach:
---------
1. Initialize result = 1.
2. Multiply result by every number from 1 to n.
3. Return the result.
*/

long long factorial(int n) {
    long long result = 1;

    for (int i = 2; i <= n; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    }

    return 0;
}
