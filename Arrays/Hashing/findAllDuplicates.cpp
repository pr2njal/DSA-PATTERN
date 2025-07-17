/*
Problem: 
Given an integer array `nums` of length n where each element is between 1 and n (inclusive),
some elements appear twice and others once. Return all elements that appear twice.

Example:
Input:  [4,3,2,7,8,2,3,1]
Output: [2,3]

Pattern: Hashing / In-Place Index Marking
Approach:
- Loop through the array:
    - For each number `num`, get index as `abs(num) - 1`.
    - If the value at that index is already negative → it's a duplicate.
    - Otherwise, mark the number at that index as visited by making it negative.
- Restore the array if needed after the operation.

Time Complexity: O(n)
Space Complexity: O(1) extra (not counting output)
Company Tags: Amazon, Adobe, Flipkart
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;

        if (nums[index] < 0) {
            result.push_back(abs(nums[i])); // already visited
        } else {
            nums[index] = -nums[index]; // mark as visited
        }
    }

    return result;
}

// Driver code
int main() {
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> duplicates = findDuplicates(arr);

    cout << "Duplicate elements are: ";
    for (int num : duplicates) {
        cout << num << " ";
    }

    return 0;
}
