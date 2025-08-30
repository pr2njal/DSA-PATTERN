/*
==============================================
 Problem: Find the Middle Node of a Linked List
==============================================

 Description:
Given the head of a singly linked list, return the middle node of the list.
If there are two middle nodes, return the second one.

----------------------------------------------
 Approach (Two Pointers):
- Use two pointers: slow and fast.
- Move slow by 1 step and fast by 2 steps.
- When fast reaches the end, slow will be at the middle.

 Time Complexity: O(n)
 Space Complexity: O(1)
==============================================
*/

#include <iostream>
using namespace std;

//  Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

//  Find middle node using slow & fast pointer
Node* findMiddle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//  Helper: Insert at tail
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

// Helper: Print the list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    for (int val : {10, 20, 30, 40, 50, 60}) {
        insertAtTail(head, val);
    }

    cout << " Linked List: ";
    printList(head);

    Node* mid = findMiddle(head);
    if (mid)
        cout << " Middle Node: " << mid->data << endl;
    else
        cout << "List is empty.\n";

    return 0;
}
