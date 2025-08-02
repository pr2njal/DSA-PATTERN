// Problem: Intersection of Two Linked Lists (LeetCode #160)
// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

/*
    Problem Statement:
    Given the heads of two singly linked lists headA and headB,
    return the node at which the two lists intersect.
    If the two linked lists have no intersection at all, return null.

    Note:
    - The linked lists must retain their original structure after the function returns.
    - You may assume there are no cycles in the linked lists.
    - The function should return the reference to the intersecting node, not a value.

    Approach:
    - Use two pointers: pointerA and pointerB.
    - Traverse both lists; when a pointer reaches the end, redirect it to the head of the other list.
    - If there is an intersection, the pointers will meet at the intersection node after at most 2 passes.
    - If no intersection, both will become null simultaneously.
    - Time Complexity: O(m + n)
    - Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pointerA = headA;
        ListNode* pointerB = headB;

        while (pointerA != pointerB) {
            pointerA = pointerA ? pointerA->next : headB;
            pointerB = pointerB ? pointerB->next : headA;
        }

        return pointerA; // Can be null (no intersection) or the intersection node
    }
};

// Sample test can be added if needed for demonstration purposes
