//  Problem: Find the second largest element in an array
//  Description:
// Given an array of integers, return the second largest element.
// If the second largest doesn't exist (array size < 2), return -1.

//  Approach:
// - Traverse the array once.
// - Track the largest and second largest elements.
// - Time: O(n), Space: O(1)

#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int findSecondLargest(const vector<int>& arr) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int num : arr) {
        if (num > largest) {
            secondLargest = largest; // demote current largest
            largest = num;
        } else if (num > secondLargest && num != largest) {
            secondLargest = num;
        }
    }

    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

int main() {
    vector<int> arr = {10, 5, 20, 8, 15};
    cout << "Second largest element: " << findSecondLargest(arr) << endl;

    return 0;
}
