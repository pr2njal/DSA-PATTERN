/*
Problem:
Given an array of integers and a number `k`, 
find the maximum sum of a subarray of size `k`.

Example:
Input:  arr = [2, 1, 5, 1, 3, 2], k = 3
Output: 9   → Subarray with max sum = [5,1,3]

Pattern: Sliding Window (Fixed Size)

Approach:
- Use a sliding window of size `k`.
- Calculate the sum of the first window.
- Slide the window forward by 1 element at a time:
    - Subtract the element going out.
    - Add the new element coming in.
- Track the maximum sum seen so far.

Time Complexity: O(n)
Space Complexity: O(1)
Company Tags: Amazon, Infosys, TCS
*/

#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarrayOfSizeK(vector<int>& arr, int k) {
    int n = arr.size();
    int windowSum = 0, maxSum = 0;

    // Compute sum of first window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k]; // add next, remove first of window
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

// Driver code
int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int result = maxSumSubarrayOfSizeK(arr, k);
    cout << "Maximum sum of subarray of size " << k << " is: " << result;

    return 0;
}
