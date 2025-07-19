// Problem: Kth Smallest Element in a Sorted Matrix
// Description:
// Given an n x n matrix where each row and column is sorted in ascending order,
// return the kth smallest element in the matrix.

// Approach:
// - Perform binary search over the range of values in the matrix.
// - For a mid-value, count how many elements are less than or equal to it.
// - If the count is >= k, move the search range left (we may have passed the answer).
// - Else, move right.

// Time Complexity: O(n * log(max - min))
// Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to count elements <= mid in matrix
int countLessEqual(const vector<vector<int>>& matrix, int mid) {
    int count = 0;
    int n = matrix.size();
    int row = n - 1, col = 0;

    // Start from bottom-left and move accordingly
    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            count += (row + 1);
            col++;
        } else {
            row--;
        }
    }
    return count;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = countLessEqual(matrix, mid);

        if (count >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    cout << "Kth smallest element: " << kthSmallest(matrix, k) << endl;
    return 0;
}
