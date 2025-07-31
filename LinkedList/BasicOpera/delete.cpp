/*
==============================================
 Problem: Implement All Deletion Operations in Singly Linked List
==============================================

 Description:
Design a singly linked list and implement the following deletion operations:
1. Delete the head node
2. Delete the tail node
3. Delete node at a specific position (1-based index)
4. Delete node by value (first occurrence)

You should also be able to print the linked list after each operation.

----------------------------------------------
 Approach:
- Use a helper function to traverse and delete nodes safely.
- For head: just move head pointer forward.
- For tail: traverse to the second last node.
- For position: reach (pos - 1)th node and unlink next.
- For value: find first matching value and unlink it.

- Edge cases: empty list, single node, invalid positions.
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

//  Print the list
void printList(Node* head) {
    cout << " Linked List: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

//  Delete Head Node
void deleteHead(Node*& head) {
    if (!head) {
        cout << " List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

//  Delete Tail Node
void deleteTail(Node*& head) {
    if (!head) {
        cout << " List is empty.\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

//  Delete at Position (1-based)
void deleteAtPosition(Node*& head, int pos) {
    if (pos <= 0 || !head) {
        cout << " Invalid position or empty list.\n";
        return;
    }

    if (pos == 1) {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp && temp->next && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << " Position out of bounds.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

//  Delete by Value (first occurrence)
void deleteByValue(Node*& head, int val) {
    if (!head) {
        cout << " List is empty.\n";
        return;
    }

    if (head->data == val) {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }

    if (!temp->next) {
        cout << " Value not found.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

//  Helper to build list
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

    // Create a list: 10 -> 20 -> 30 -> 40 -> 50
    for (int val : {10, 20, 30, 40, 50})
        insertAtTail(head, val);

    cout << " Initial List:\n";
    printList(head);

    cout << "\n Deleting Head:\n";
    deleteHead(head);
    printList(head); // 20 -> 30 -> 40 -> 50

    cout << "\n Deleting Tail:\n";
    deleteTail(head);
    printList(head); // 20 -> 30 -> 40

    cout << "\n Deleting at Position 2:\n";
    deleteAtPosition(head, 2);
    printList(head); // 20 -> 40

    cout << "\n Deleting by Value 40:\n";
    deleteByValue(head, 40);
    printList(head); // 20

    cout << "\n Trying to delete non-existent value (100):\n";
    deleteByValue(head, 100);

    cout << "\n Deleting last remaining node:\n";
    deleteHead(head);
    printList(head); // NULL

    return 0;
}
