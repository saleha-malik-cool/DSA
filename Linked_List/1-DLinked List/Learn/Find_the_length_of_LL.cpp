/*
QUESTION:-
You are given the head of a singly linked list. Your task is to return the number of nodes in the linked list.

Example:

Input: head = [1, 2, 3, 4, 5]
Output: 5
*/

/*
APPROACH:
1. We make a new node as temp and assign value of head.
2. initiate a count variable as 0;
3. also put the edge case when only head is present so return 1;
4.While temp != null count++ and temp = temp->next.
5.return count.
*/

//CODE:
class Solution {
public:
    int getLength(ListNode* head) {
        // Your code goes here
        if(head->next == NULL){
            return 1;
        }
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
};
