/*
QUESTION:-
Given the head of a singly linked list and an integer X, insert a node with value X at the head of the linked list and return the head of the modified list.

Example:

Input: linkedList = [1, 2, 3], X = 7
Output: [7, 1, 2, 3]
Explanation:
7 was added as the 1st node.
*/

/*
APPROACH:
1. We create a new node of the value X.
2. We point that node to the head of the original linked list.
3. We update the head to the newnode.
4. Return head.
*/
//Code:-
class Solution {
    public:
        ListNode* insertAtHead(ListNode* &head, int X) {
            //your code goes here
            ListNode* newNode= new ListNode(X);
            newNode->next=head;
            head=newNode;
            return head;
        }
};
