#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Problem Statement:
Reverse a given stack using recursion,
without using any extra data structures 
(like arrays, queues, etc.).

Example:
Input:  stack = [1, 2, 3, 4, 5]   (top = 5)
Output: stack = [5, 4, 3, 2, 1]   (top = 1)
-----------------------------------------------------
*/

/*
=====================================================
 Approach: Recursion
-----------------------------------------------------
Idea:
1. Pop all elements recursively until stack becomes empty.
2. While backtracking, insert each element at the bottom 
   of the stack instead of the top.

We need two recursive functions:
- reverseStack(): removes all elements then inserts them back at bottom.
- insertAtBottom(): inserts an element at the bottom 
  by popping everything until empty, then pushing back.

⏱ Complexity:
- Time:  O(n^2) (inserting at bottom takes O(n), repeated n times)
- Space: O(n)   (recursive call stack)
=====================================================
*/

//helper funcn for inserting element at bottom
void insertAtBottom(stack<int>& st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int topVal=st.top();
    st.pop();

    insertAtBottom(st, x);
    st.push(topVal);
}

void reverseStack(stack<int>& st){
    if(st.empty()) return;

    int topVal=st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, topVal);
}