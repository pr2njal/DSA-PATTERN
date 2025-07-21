#include <iostream>
#include <cmath>
using namespace std;

/*
Problem Statement:
------------------
Check whether a given number is an Armstrong number.

A number is called an Armstrong number if the sum of its own digits each raised 
to the power of the number of digits is equal to the number itself.

For example:
153 => 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153 (Armstrong)
9474 => 9^4 + 4^4 + 7^4 + 4^4 = 9474 (Armstrong)

Approach:
---------
1. Count the number of digits in the given number (n).
2. For each digit, compute digit^number_of_digits and add it to a sum.
3. Compare the final sum with the original number.
   - If equal => Armstrong number.
   - Else => Not an Armstrong number.
*/

bool isArmstrong(int n) {
    int original = n;
    int digits = 0;
    int temp = n;

    // Step 1: Count number of digits
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    int sum = 0;
    temp = n;

    // Step 2: Compute the sum of each digit raised to the power of 'digits'
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    // Step 3: Compare sum with original number
    return sum == original;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num))
        cout << num << " is an Armstrong number." << endl;
    else
        cout << num << " is not an Armstrong number." << endl;

    return 0;
}
