/*
QUESTION:-
There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
1. The value of the given node should not exist in the linked list.
2. The number of nodes in the linked list should decrease by one.
3. All the values before node should be in the same order.
4. All the values after node should be in the same order.

Example:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
*/
/*
Approach:-
1.Make a new node name temp and assign value of node next.
2. Make node value as same as next element.
3. Now we have two same element name temp next as node next.
4.Now free temp
*/
//code:-
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val= temp->val;
        node->next= temp->next;
        delete(temp);
    }
};

//Time complexity=O(1)
//Space complexity=O(1)
