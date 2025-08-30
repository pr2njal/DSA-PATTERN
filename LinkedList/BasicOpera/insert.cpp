/*
==============================================
 Problem: Implement All Insertion Operations in Singly Linked List
==============================================

 Description:
Design a singly linked list and implement the following insertion operations:
1. Insert at the beginning (head)
2. Insert at the end (tail)
3. Insert at a specific position (1-based index)

You should also be able to print the linked list after each insertion.

----------------------------------------------
 Approach:
- Define a Node class with `data` and `next` pointer.
- For each insertion type:
    → At Head: Create a node, point it to current head, update head.
    → At Tail: Traverse to last node, attach new node.
    → At Position: Traverse to (pos - 1)th node and insert in between.

- Use a helper function `printList()` to display the list after operations.
==============================================
*/
#include <iostream>
using namespace std;

//Node Structure
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

//Insert at head
void insertAtHead(Node*& head, int val){
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;
}
//Insert at Tail
void insertAtTail(Node*& head, int val){
    Node* newNode=new Node(val);
    if(!head){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next)
    temp=temp->next;
    temp->next=newNode;
}
//Insert at a specific position
void insertAtPosition(Node*& head, int pos, int val){
   if(pos<=0){
    cout<<"invalid position"<<endl;
    return;
   } 
   if(pos==1){
    insertAtHead(head, val);
    return;
   }
   Node* newNode=new Node(val);
   Node* temp=head;

   for(int i=1;temp && i<pos-1;i++){
    temp=temp->next;
   }
   if(!temp){
    cout<<"invalid position"<<endl;
    return;
   }
   newNode->next=temp->next;
   temp->next=newNode;
}

void printList(Node* head){
    cout<<"Linked list:";
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL\n";
}
int main() {
    Node* head = nullptr;

    cout << "🔹 Inserting at Head:\n";
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    printList(head); // 10 -> 20 -> 30 -> NULL

    cout << "\n🔹 Inserting at Tail:\n";
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    printList(head); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    cout << "\n🔹 Inserting at Specific Positions:\n";
    insertAtPosition(head, 3, 25);  // Insert 25 at position 3
    insertAtPosition(head, 1, 5);   // Insert 5 at head
    insertAtPosition(head, 10, 60); // Invalid position
    printList(head); // 5 -> 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> NULL

    return 0;
}