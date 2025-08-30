#include <bits/stdc++.h>
using namespace std;

/*
=====================================================
🔹 Approach 2: Costly Pop (Two Queues)
-----------------------------------------------------
- Maintain two queues (q1, q2).
- On push(x):
    - Simply enqueue x into q1 (O(1))
- On pop():
    1. Move all elements except the last from q1 → q2
    2. Remove the last element from q1 (this is the stack top)
    3. Swap q1 and q2 (so q1 always has elements)

⏱ Complexity:
- push: O(1)
- pop:  O(n)
- top:  O(n) (similar to pop but return last element instead of removing)
=====================================================
*/
class MyStack2 {
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if(q1.empty()) return -1;

        // Leave last element in q1, move others to q2
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topVal = q1.front(); // Last element = top of stack
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
        return topVal;
    }

    int top() {
        if(q1.empty()) return -1;

        // Similar to pop, but return last element instead of removing
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topVal = q1.front();
        q2.push(topVal); // Put it back into q2
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
        return topVal;
    }

    bool empty() {
        return q1.empty();
    }
};

/*
-----------------------------------------------------
🔹 Driver Code
-----------------------------------------------------
*/
int main() {

    cout << "\nUsing Approach 2 (Costly Pop):\n";
    MyStack2 st2;
    st2.push(10);
    st2.push(20);
    st2.push(30);

    cout << st2.top() << endl; // 30
    cout << st2.pop() << endl; // 30
    cout << st2.top() << endl; // 20
    cout << st2.empty() << endl; // 0 (false)

    return 0;
}