#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Problem Statement:
The stock span problem is a financial problem where we have
a series of daily stock prices. For each day, the span of the
stock’s price is defined as the number of consecutive days
before today (including today) for which the price of the stock
was less than or equal to today’s price.

Given an array price[] of size n, return an array span[]
where span[i] denotes the stock span for day i.

Example:
Input:  price[] = [100, 80, 60, 70, 60, 75, 85]
Output: span[]  = [1,   1,  1,  2,  1,  4,  6]
-----------------------------------------------------
*/

/*
=====================================================
Approach: Monotonic Stack
-----------------------------------------------------
1. Maintain a stack of indices where prices are in
   decreasing order (top has last greater price).
2. For each day i:
   - While stack not empty and price[i] >= price[st.top()],
     pop the stack (remove smaller prices).
   - If stack empty → all previous prices are smaller → span[i] = i + 1
   - Else → span[i] = i - st.top()
   - Push current index onto stack.

⏱ Complexity:
- Time:  O(n) (each element pushed/popped once)
- Space: O(n) (stack + result array)
=====================================================
*/

vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st; // stores indices

    for(int i = 0; i < n; i++) {
        // Pop all smaller or equal prices
        while(!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // If stack empty, span = i+1 (all previous smaller)
        span[i] = st.empty() ? (i + 1) : (i - st.top());

        // Push current day index
        st.push(i);
    }

    return span;
}

/*
-----------------------------------------------------
 Driver Code
-----------------------------------------------------
*/
int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> result = stockSpan(prices);

    cout << "Stock Spans: ";
    for(int s : result) cout << s << " ";
    cout << endl;
    // Output: 1 1 1 2 1 4 6

    return 0;
}