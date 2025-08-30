#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Problem Statement:
Given a stack of integers, sort it in ascending order
using recursion (without using any extra data structures).

Example:
Input:  stack = [3, 1, 4, 2]   (top = 2)
Output: stack = [1, 2, 3, 4]   (top = 4)
-----------------------------------------------------
*/

/*
=====================================================
 Approach: Recursion
-----------------------------------------------------
Idea:
1. Pop the top element from the stack.
2. Recursively sort the remaining stack.
3. Insert the popped element back into the stack 
   in its correct sorted position.

We need two functions:
- sortStack(): pops elements recursively and sorts remaining stack.
- insertSorted(): inserts element into correct position in sorted stack.

⏱ Complexity:
- Time:  O(n^2) (each insert may take O(n), repeated n times)
- Space: O(n)   (recursion call stack)
=====================================================
*/
//helper funcn for inserting elements in sorted order
void insertedSorted(stack<int>& st, int x){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return;
    }
    int topVal=st.top();
    st.pop();

    insertedSorted(st, x);

    st.push(topVal);

}

void sortStack(stack<int>& st){
    if(st.empty()) return;

    int topVal=st.top();
    st.pop();

    sortStack(st);

    insertedSorted(st, topVal);
}

