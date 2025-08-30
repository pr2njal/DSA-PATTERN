/*
Problem: Delete a Node in a Linked List Without Head Pointer

Description:
You are given a node that needs to be deleted from a singly linked list.
You are **not** given access to the head of the list.
The node to be deleted is **not the last node**.

Example:
Input: Node to delete = 5 from 4 -> 5 -> 1 -> 9
Output: 4 -> 1 -> 9

Approach:
- Copy the data from the next node into the current node.
- Then delete the next node by skipping it.
- This makes it seem like the current node is deleted.

Constraints:
- The given node is guaranteed **not to be the tail node**.

Time Complexity: O(1)
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

void deleteGivenNode(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        cout << "Cannot delete this node (it's either null or the last node).\n";
        return;
    }

    Node* temp = node->next;
    node->data = temp->data;     // Copy next node’s data to current node
    node->next = temp->next;     // Unlink the next node
    delete temp;                 // Free memory of skipped node
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
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 1);
    insertAtTail(head, 9);

    cout << "Original List:\n";
    printList(head);

    // Suppose we want to delete node with value 5
    Node* nodeToDelete = head->next; // 5
    deleteGivenNode(nodeToDelete);

    cout << "List after deletion:\n";
    printList(head);

    return 0;
}
