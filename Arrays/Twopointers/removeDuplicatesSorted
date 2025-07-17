/*
Problem: Remove duplicates from a sorted array in-place such that each element appears only once 
and return the new length.

Example:
Input:  [1, 1, 2, 2, 3]
Output: [1, 2, 3]  (length = 3)

Note: Modify the array in-place. The elements beyond the returned length do not matter.

Pattern: Two Pointers
Approach:
- Use a slow pointer `j` to mark the position of the last unique element.
- Traverse with a fast pointer `i` from index 1 to end.
- If current element `nums[i] != nums[j]`, it's a new unique element → increment `j` and assign it to `nums[j] = nums[i]`.

Time Complexity: O(n)
Space Complexity: O(1)
Company Tags: Infosys, TCS, Wipro, Amazon
*/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int j = 0; // index of last unique element

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }

    return j + 1; // length of unique part of array
}

// Driver code to test the function
int main() {
    vector<int> arr = {1, 1, 2, 2, 3};

    int len = removeDuplicates(arr);

    cout << "After removing duplicates: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
