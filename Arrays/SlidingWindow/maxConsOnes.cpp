//  Problem: Max Consecutive 1s in a Binary Array
//  Description:
// Given a binary array (containing only 0s and 1s), return the maximum number
// of consecutive 1s in the array.
//
//  Approach: Simple Traversal + Counter
// - Traverse the array while counting 1s.
// - Reset count if a 0 is found.
// - Keep track of the maximum count so far.
//
//  Time: O(n),   Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0;
    int currentCount = 0;

    for (int num : nums) {
        if (num == 1) {
            currentCount++;
            maxCount = max(maxCount, currentCount);
        } else {
            currentCount = 0; // Reset count on 0
        }
    }

    return maxCount;
}

int main() {
    vector<int> binaryArr = {1, 1, 0, 1, 1, 1, 0, 1};  // Example input
    cout << "Max consecutive 1s: " << findMaxConsecutiveOnes(binaryArr) << endl;
    return 0;
}
