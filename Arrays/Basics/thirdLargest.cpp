//  Problem: Find the third largest element in an array
//  Description:
// Given an array of integers, return the third largest distinct element in the array.
// If the third largest does not exist, return -1.

//  Approach:
// - Use three variables to track first, second, and third largest distinct values.
// - Traverse the array once.
// - Time: O(n), Space: O(1)
#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

int findThirdLargest(const vector<int>& arr) {
    long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;

    for (int num : arr) {
        if (num == first || num == second || num == third) {
            continue; // Skip duplicates
        }

        if (num > first) {
            third = second;
            second = first;
            first = num;
        }
        else if (num > second) {
            third = second;
            second = num;
        }
        else if (num > third) {
            third = num;
        }
    }

    return (third == LONG_MIN) ? -1 : third;
}

int main() {
    vector<int> arr = {10, 5, 20, 8, 15, 20}; // Example input
    cout << "Third largest element: " << findThirdLargest(arr) << endl;
    return 0;
}

