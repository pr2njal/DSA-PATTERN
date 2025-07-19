//  Problem: Maximum Product of a Triplet
//  Description:
// Given an array of integers, find the maximum product of any three numbers from the array.
//
//  Note:
// The array can include negative numbers, so consider both:
// 1. Product of the top 3 largest numbers
// 2. Product of 2 smallest (negative) numbers and the largest number
//
//  Approach: Sorting + Greedy
// - Sort the array.
// - Compute:
//     max1 = product of last three elements (largest)
//     max2 = product of first two (possibly negative) and last element
// - Return max(max1, max2)
//
//  Time: O(n log n),   Space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductTriplet(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return -1; // Not enough elements

    sort(nums.begin(), nums.end()); // Sort the array

    // Case 1: Product of top 3 largest
    int max1 = nums[n-1] * nums[n-2] * nums[n-3];

    // Case 2: Product of two smallest (maybe negative) and largest
    int max2 = nums[0] * nums[1] * nums[n-1];

    return max(max1, max2);
}

int main() {
    vector<int> arr = {-10, -3, 5, 6, -20};  // Example input
    cout << "Maximum product of triplet: " << maxProductTriplet(arr) << endl;
    return 0;
}
