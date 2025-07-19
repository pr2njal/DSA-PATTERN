// Problem: Best Time to Buy and Sell Stock
// Description:
// You are given an array where each element represents the stock price on a given day.
// You can buy on one day and sell on a later day.
// Return the maximum profit you can achieve from a single transaction.
// If no profit is possible, return 0.

// Approach:
// - Track the minimum price seen so far.
// - At each step, calculate the profit if we sold today.
// - Keep updating the maximum profit.

// Time Complexity: O(n)
// Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        // Update the minimum price seen so far
        minPrice = min(minPrice, price);
        
        // Calculate profit if sold today
        int profit = price - minPrice;
        
        // Update the maximum profit
        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
