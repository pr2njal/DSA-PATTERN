#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Problem Statement:
Design a stack that supports push, pop, top, 
and retrieving the minimum element in O(1) time.

Implement the following functions:
- push(x): Push element x onto stack.
- pop(): Removes the element on top of the stack.
- top(): Get the top element.
- getMin(): Retrieve the minimum element in the stack.

Example:
Input:
push(-2), push(0), push(-3), getMin(), pop(), top(), getMin()
Output:
-3, 0, -2
-----------------------------------------------------
*/

/*
=====================================================
 Approach: Two Stacks
-----------------------------------------------------
- Maintain two stacks:
  1. mainStack → stores all elements.
  2. minStack  → stores current minimum at each push.
- On push(x):
    - Push x onto mainStack.
    - If minStack empty or x <= minStack.top(), push x onto minStack.
- On pop():
    - Pop from mainStack.
    - If popped element == minStack.top(), pop from minStack as well.
- getMin():
    - Return minStack.top() (current minimum).

⏱ Complexity:
- Time:  O(1) for all operations.
- Space: O(n) (extra stack for minimums).
=====================================================
*/

class MinStack {
    stack<int> mainStack, minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if(minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if(mainStack.empty()) return;
        int topVal = mainStack.top();
        mainStack.pop();
        if(!minStack.empty() && topVal == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return mainStack.empty() ? -1 : mainStack.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

/*
-----------------------------------------------------
 Driver Code
-----------------------------------------------------
*/
int main() {
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "Current Min: " << st.getMin() << endl; // -3
    st.pop();

    cout << "Top Element: " << st.top() << endl;    // 0
    cout << "Current Min: " << st.getMin() << endl; // -2

    return 0;
}
