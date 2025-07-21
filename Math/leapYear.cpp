#include <iostream>
using namespace std;

/*
Problem Statement:
------------------
Check whether a given year is a Leap Year.

A year is a leap year if:
- It is divisible by 4
  AND
    - Not divisible by 100
    OR
    - Divisible by 400

Examples:
---------
- 2000 => Leap Year (divisible by 400)
- 1900 => Not a Leap Year (divisible by 100 but not 400)
- 2024 => Leap Year (divisible by 4 but not 100)

Approach:
---------
1. If the year is divisible by 4:
   a. If it's also divisible by 100:
      - Check if it is divisible by 400. If yes => Leap year.
      - Else => Not a leap year.
   b. Else => Leap year.
2. Else => Not a leap year.
*/

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0);
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if (isLeapYear(year))
        cout << year << " is a Leap Year." << endl;
    else
        cout << year << " is not a Leap Year." << endl;

    return 0;
}
