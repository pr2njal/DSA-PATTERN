/*
Problem: Reverse a Linked List

Description:
Given the head of a singly linked list, reverse the list and return the new head.

Example:
Input: 10 -> 20 -> 30 -> NULL
Output: 30 -> 20 -> 10 -> NULL

Approach:
Use two pointers: prev and curr.
- Initialize prev as NULL and curr as head.
- Iterate through the list and for each node:
    - Store the next node.
    - Reverse the current node's pointer to point to prev.
    - Move prev and curr one step forward.
- At the end, prev will be the new head.
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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
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
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);

    cout << "Original List:\n";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List:\n";
    printList(head);

    return 0;
}
