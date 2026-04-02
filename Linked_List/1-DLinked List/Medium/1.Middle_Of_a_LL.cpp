/*
QUESTION:-
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
*/
/*
Brute force:-
1.traverse the linked list by making temp node and count number of element in linked list.
2.Calculate the middle element by (count/2+1) 
3.Now traverse again by making one more temp and in every traversal middle= middle-1
4.check everytime if middle==0 after minus, if it is 0 break and come out of loop
5.Return temp
*/
//Code:-
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
Node*Middleofll(Node*head){
    Node*temp = head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp= temp->next;
    }
    int middle= (count/2 +1);
   temp = head;
    while(temp!=NULL){
        middle=middle-1;
        if(middle==0){
            break;
        }
        temp=temp->next;
    }
    return temp;
}
/*
Optimal Approach:-
1. We initialise two listnodes, slow and fast. Fast will jump 2 nodes at a time. Slow will jump to the next node 
itself.
2. While fast != NULL && fast->next != NULL {since for odd number of nodes, if we reach the last node,
fast will jump NULL, and hence reach an unknown pointer}, we jump fast to next to next and slow to the next node.
3. After traversing through the loop, return slow {the middle node of the linked list}.
*/

//Code:-
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode*fast= head;
       ListNode*slow= head;
       while(fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast=fast->next->next;
       }
       return slow;
        
        
    }
};
//Time Complexity : O(N)
//Space Complexity : O(1)

