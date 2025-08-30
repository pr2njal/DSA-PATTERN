#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Problem Statement:
Given an array arr[] of size n, for each element,
find the **Next Greater Element (NGE)** to the right.
If no greater element exists, output -1 for that index.

Example:
Input: arr = [4, 5, 2, 25]
Output: [5, 25, 25, -1]

Input: arr = [13, 7, 6, 12]
Output: [-1, 12, 12, -1]
-----------------------------------------------------
*/

/*
=====================================================
 Approach: Monotonic Stack
-----------------------------------------------------
1. Traverse array from RIGHT to LEFT.
2. Maintain a stack that stores elements in decreasing order.
3. For each element arr[i]:
   - While stack is not empty and stack.top() <= arr[i], pop the stack.
   - If stack is empty → no greater element → result[i] = -1
   - Else → stack.top() is the Next Greater Element → result[i] = stack.top()
   - Push arr[i] onto the stack
4. Return result array.

 Complexity:
- Time:  O(n) (each element pushed & popped once)
- Space: O(n) (stack + result)
=====================================================
*/

vector<int> nextGreaterElement(vector<int>& arr){
    int n=arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    //start from the right side
    for(int i=n-1;i>=0;i--){
        //pop smaller or equal elements
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        //if stack not empty , top is the next greater
        if(!st.empty()){
            result[i]=st.top();
        }
        //push current element
        st.push(arr[i]);
    }
    return result;
}