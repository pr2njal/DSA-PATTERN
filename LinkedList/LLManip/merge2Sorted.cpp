/*
Problem: Merge Two Sorted Linked Lists (In-place)

Description:
You are given the heads of two sorted singly linked lists.
Merge them into one sorted list by rearranging pointers in-place.

Example:
Input: 
    list1 = 1 -> 2 -> 4
    list2 = 1 -> 3 -> 4
Output:
    1 -> 1 -> 2 -> 3 -> 4 -> 4

Approach:
- Ensure list1 starts with the smaller value; if not, swap list1 and list2.
- Use a pointer `res` to store the start of merged list.
- Traverse both lists, and whenever list1's next value is greater than list2's value,
  insert list2’s node in between.
- Continue this until one list is exhausted, then append the rest of the other list.

Time Complexity: O(n + m)
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

Node* mergeInPlace(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    // Ensure list1 starts with the smaller value
    if (list1->data > list2->data) {
        swap(list1, list2);
    }

    Node* res = list1;

    while (list1 && list2) {
        Node* temp = nullptr;

        while (list1 && list1->data <= list2->data) {
            temp = list1;
            list1 = list1->next;
        }

        // Now list1->data > list2->data, insert list2 here
        temp->next = list2;
        swap(list1, list2);  // swap roles to continue comparison
    }

    return res;
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
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insertAtTail(list1, 1);
    insertAtTail(list1, 2);
    insertAtTail(list1, 4);

    insertAtTail(list2, 1);
    insertAtTail(list2, 3);
    insertAtTail(list2, 4);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* merged = mergeInPlace(list1, list2);
    cout << "Merged In-Place List: ";
    printList(merged);

    return 0;
}
