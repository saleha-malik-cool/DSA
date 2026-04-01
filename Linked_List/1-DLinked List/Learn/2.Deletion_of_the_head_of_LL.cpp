/*
QUESTION:-

Given the head of a singly linked list, delete the head of the linked list and return the head of the modified list. The head is the first node of the linked list.

Example:

Input: linkedList = [1, 2, 3]
Output: [2, 3]
Explanation:
The first node was removed.
*/

/*
APPROACH:
1. If our head is already NULL, return NULL.
2. Create a new node, and assign it head, so that we don't lose the deleted node, and face a memory leak.
3. We update head to the next node.
4. Delete temp.
5. Return head.
*/

//CODE:
class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if(head == NULL) return NULL;
         ListNode* temp = head;
        head = head->next;
        delete temp;
        
        return head;
    }
};

//Time Complexity : O(1)
//Space Complexity : O(1)
