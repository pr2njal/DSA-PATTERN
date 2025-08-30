#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Problem Statement:
Given a stack of integers, delete the middle element
without using any extra data structure.

Middle element = ⌊ (size_of_stack / 2) ⌋ (0-based index)

Examples:
Input: stack = [1, 2, 3, 4, 5]   (top = 5)
Output: [1, 2, 4, 5]             (3 removed)

Input: stack = [1, 2, 3, 4]      (top = 4)
Output: [1, 3, 4]                (2 removed)
-----------------------------------------------------
*/

/*
=====================================================
 Approach: Recursion with Counter
-----------------------------------------------------
1. Maintain a counter `count` during recursion.
2. Pop the top element and increment counter.
3. When counter == size/2 → remove this element
   (don’t push it back → effectively deletes middle).
4. For all other elements, push them back after recursion.
5. Base case: when stack becomes empty.

⏱ Complexity:
- Time:  O(n)
- Space: O(n) (recursion call stack)
=====================================================
*/

void solve(stack<int>& st, int count, int size){
    if(count==size/2){
        st.pop();
        return;
    }
    int topVal=st.top();
    st.pop();

    solve(st, count+1, size);

    st.push(topVal);
}

void deleteMiddle(stack<int>& st){
    int size=st.size();
    solve(st, 0, size);
}