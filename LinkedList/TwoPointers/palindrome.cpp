/*
Problem: Check if Linked List is a Palindrome

Description:
Given the head of a singly linked list, return true if it is a palindrome, else false.

Example:
Input: 1 -> 2 -> 2 -> 1
Output: true

Approach:
1. Use slow and fast pointers to reach the middle of the list.
2. Reverse the second half of the list.
3. Compare the first and second halves node by node.
4. (Optional) Restore the list to original by reversing the second half again.

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

// Helper function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Main function to check palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;

    // Find middle (slow will be at middle)
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    Node* secondHalf = reverseList(slow);
    Node* temp = secondHalf;

    // Compare first and second halves
    Node* firstHalf = head;
    while (temp) {
        if (firstHalf->data != temp->data)
            return false;
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return true;
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
    insertAtTail(head, 2);
    insertAtTail(head, 1);

    if (isPalindrome(head))
        cout << "The linked list is a palindrome.\n";
    else
        cout << "The linked list is NOT a palindrome.\n";

    return 0;
}
