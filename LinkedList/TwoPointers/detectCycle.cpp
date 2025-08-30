/*
Problem: Detect a Cycle in a Linked List

Description:
Given the head of a linked list, determine if the linked list has a cycle in it.
A cycle occurs when a node’s next pointer points back to a previous node, forming a loop.

Example:
Input: 1 -> 2 -> 3 -> 4 -> 2 (cycle back to node with value 2)
Output: true

Approach:
Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare).
- Use two pointers: slow and fast.
- Move slow by one step and fast by two steps.
- If there is a cycle, they will eventually meet.
- If fast reaches NULL, no cycle exists.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    // Creating a cycle: node 5 points back to node 2
    head->next->next->next->next->next = head->next;

    if (hasCycle(head))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
