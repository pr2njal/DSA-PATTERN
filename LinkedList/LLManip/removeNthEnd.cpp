/*
Problem: Remove Nth Node From End of Linked List

Description:
Given the head of a linked list, remove the nth node from the end of the list and return the head.

Example:
Input: 1 -> 2 -> 3 -> 4 -> 5, n = 2
Output: 1 -> 2 -> 3 -> 5

Approach:
Use two pointers (fast and slow).
- Move the fast pointer n steps ahead.
- Then move both fast and slow one step at a time until fast reaches the end.
- Now slow is at the previous node of the target.
- Change slow->next to skip the target node.

Edge Case:
- If n is equal to the length of the list, we remove the head.

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

Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* fast = dummy;
    Node* slow = dummy;

    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; ++i) {
        if (fast)
            fast = fast->next;
    }

    // Move fast to the end, maintaining the gap
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the nth node
    Node* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
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

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    cout << "Original List:\n";
    printList(head);

    int n = 2;
    head = removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from end:\n";
    printList(head);

    return 0;
}
