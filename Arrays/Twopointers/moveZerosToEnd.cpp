/*
Problem: Move all zeros to the end of the array without changing the relative order of non-zero elements.

Example:
Input:  {0, 1, 0, 3, 12}
Output: {1, 3, 12, 0, 0}

Pattern: Two Pointers
Approach:
- Use two pointers: one for traversing (`i`) and one (`j`) to track the position to place non-zero elements.
- Traverse the array:
    - If the current element is non-zero, place it at index `j` and increment `j`.
- After placing all non-zero elements at the start, fill the remaining positions with 0s.

Time Complexity: O(n)
Space Complexity: O(1)
Company Tags: Amazon, Adobe, Microsoft
*/

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0; // Position to place the next non-zero element

    // First pass: move all non-zero elements to the beginning
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    // Second pass: fill remaining positions with 0s
    while (j < nums.size()) {
        nums[j] = 0;
        j++;
    }
}

// Driver code to test the function
int main() {
    vector<int> arr = {0, 1, 0, 3, 12};

    moveZeroes(arr);

    cout << "After moving zeros to end: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
