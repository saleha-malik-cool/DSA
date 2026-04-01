/*
QUESTION:-
You are given the head of a singly linked list and an integer key.
Return true if the key exists in the linked list, otherwise return false.

Example:

Input: head = [1, 2, 3, 4], key = 3
Output: true
Explanation: The linked list is 1 → 2 → 3 → 4. The key 3 is present in the list.
*/

/*
APPROACH:
1. Assign the node head to a new listnode temp.
2. While temp != NULL, we check if current node value is equal to key.
3. If yes, return true.
4. Else check for the next node.
5. If full linked list is traversed, return false;
*/
//Code:-
class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        // Your code goes here
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val==key){
                return true;
            }
            else{
                temp=temp->next;
            }
        }
        return false;
    }
};
//Time Complexity :-O(N)
//Space Complexity : O(1)
