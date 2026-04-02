/*
QUESTION:-
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

/*
APPROACH:
1. We initialise two listnodes, one will indicate the prev node and the other will indicate the temp listnode.
2. While temp != NULL, we initialise a listnode, which indicates the next listnode.
3. We point the next of temp listnode to prev.
4. Update prev to temp listnode.
5. Move temp to current.
6. Return prev.
*/
//Code:-
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp = head;
        ListNode*prev= NULL;
      while(temp!=NULL){
        ListNode* current = temp->next;
        temp->next= prev;
        prev= temp;
        temp = current;
      }
        return prev;
    }
};
//Time Complexity : O(N)
//Space Complexity : O(1)
