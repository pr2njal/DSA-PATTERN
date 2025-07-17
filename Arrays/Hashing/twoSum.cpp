/*
Problem: 
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers 
such that they add up to target.

Example:
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]  (because nums[0] + nums[1] == 9)

Pattern: Hashing
Approach:
- Traverse the array while maintaining a hash map of (value → index).
- For each element `x`, check if `target - x` exists in the map.
    - If yes, you've found the pair.
    - If not, store `x` and its index in the map.

Time Complexity: O(n)
Space Complexity: O(n)
Company Tags: Amazon, Adobe, Google, Infosys, Microsoft
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp; // value → index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (mpp.find(complement) != mpp.end()) {
            return {mpp[complement], i}; // pair found
        }

        mpp[nums[i]] = i;
    }

    return {}; // no pair found
}

// Driver code
int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(arr, target);

    cout << "Indices: ";
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
