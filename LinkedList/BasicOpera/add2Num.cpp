/*
     Problem: Add Two Numbers (LeetCode #2)
    Link: https://leetcode.com/problems/add-two-numbers/

     Problem Statement:
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

     Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807

     Approach:
    - Initialize a dummy head to simplify result list creation.
    - Use a `carry` variable to store sum overflow for each digit.
    - Traverse both lists until all digits and carry are processed.
    - At each step, add corresponding digits from both lists and the carry.
    - Create a new node with `sum % 10` and update carry as `sum / 10`.
    - Move the pointers forward in the input lists.
    - Finally, return the `next` of the dummy node (head of resulting list).

     Pattern: Linked List + Math (Elementary Addition)
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // to store the result
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummyHead->next;
    }
};

//  Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

//  Example usage
int main() {
    // Linked list l1 = 2 -> 4 -> 3 (represents 342)
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));

    // Linked list l2 = 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2); // Expected output: 7 -> 0 -> 8 (represents 807)

    cout << "Result: ";
    printList(result);

    return 0;
}
