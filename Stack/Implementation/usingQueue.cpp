#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------------
 Problem Statement:
Implement a Stack using Queue.
A stack follows Last In First Out (LIFO) order, while
a queue follows First In First Out (FIFO) order.

You need to design a stack class with:
 - push(x): Insert element into the stack
 - pop(): Remove the top element
 - top(): Get the top element
 - empty(): Return whether the stack is empty

-----------------------------------------------------
 Approach 1: Costly Push (Single Queue)
- Use only one queue.
- On push(x):
    1. Enqueue x into the queue
    2. Rotate all previous elements behind the new one
       (so the new element stays at the front)
- On pop(): simply dequeue from the front
- On top(): return the front element of the queue

⏱ Complexity:
- push: O(n)   (because of rotation)
- pop:  O(1)
- top:  O(1)
-----------------------------------------------------
*/

class MyStack {
    queue<int> q;
public:
    // Push element onto stack
    void push(int x) {
        q.push(x);
        int size = q.size();
        // Rotate the queue to move the new element to front
        for(int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack
    int pop() {
        if(q.empty()) return -1;
        int topVal = q.front();
        q.pop();
        return topVal;
    }

    // Get the top element
    int top() {
        return q.empty() ? -1 : q.front();
    }

    // Return whether the stack is empty
    bool empty() {
        return q.empty();
    }
};

// Driver code
int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30
    cout << st.pop() << endl; // 30
    cout << st.top() << endl; // 20
    cout << st.empty() << endl; // 0 (false)

    return 0;
}
