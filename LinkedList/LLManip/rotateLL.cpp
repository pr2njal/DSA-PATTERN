/*
Problem: Rotate a Linked List

Description:
Given the head of a singly linked list and an integer k, rotate the list to the right by k places.

Example:
Input: 10 -> 20 -> 30 -> 40 -> 50, k = 2  
Output: 40 -> 50 -> 10 -> 20 -> 30

Approach:
1. Count the total number of nodes (len).
2. Make the list circular by connecting the last node to the head.
3. Find the new tail: (len - k % len - 1)th node.
4. The new head will be next of the new tail.
5. Break the circle by setting newTail->next = NULL.

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

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    int len = getLength(head);
    k = k % len;
    if (k == 0) return head;

    // Make the list circular
    Node* tail = head;
    while (tail->next)
        tail = tail->next;
    tail->next = head;

    // Find new tail: (len - k - 1)th node
    int stepsToNewTail = len - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++)
        newTail = newTail->next;

    // Set new head and break the circle
    Node* newHead = newTail->next;
    newTail->next = nullptr;

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
    for (int val : {10, 20, 30, 40, 50})
        insertAtTail(head, val);

    cout << "Original List:\n";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    cout << "Rotated List (k = 2):\n";
    printList(head);

    return 0;
}
