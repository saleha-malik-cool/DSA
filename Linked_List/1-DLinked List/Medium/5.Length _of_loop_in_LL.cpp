/*
QUESTION:-
Given the head of a singly linked list, find the length of the loop in the linked list if it exists. Return the length of the loop if it exists; otherwise, return 0.

Example:

Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1
Output: 4
Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.
*/

//BRUTE-FORCE CODE:

/*
APPROACH:
1. We initialise an unordered map, which will store listnodes and it's index.
2. We initialise a node with the value of head, and index from 0.
3. While temp != NULL, we check if the current node has already been saved. If not, we save the index with the node.
4. Else, we return current index - index of the same node that was last saved.
5. We do index++, so that every node is saved on a different index.
6. We keep moving temp to the next node.
7. If the loop is exited without returning anything, that means there's no loop. Return 0.
*/

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head;
        int index = 0;

        while(temp != NULL) {
            if(!mpp.count(temp)) mpp[temp] = index;
            else {
                return index - mpp[temp];
            }
            index++;
            temp = temp->next;
        }
        return 0;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)

/*
Optimal Code:-
1. We initialise two pointers, fast and slow.
2. While fast != NULL && fast->next != NULL {for odd number of nodes}, we move fast to the next to next node, and slow to the next node.
3. Once we find fast == slow, it confirms the presence of a loop. We initialise count from one and start slow from the next node of the the current node.
4. We keep doing count++ and moving slow to the next node, till we again reach the same node as fast.
5. Once slow == fast again, we return count.
6. If the loop is exited without returning anything, return 0.
*/

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) {
                int count = 1;
                slow = slow->next;
                while(slow != fast) {
                    count++;
                    slow = slow->next;
                }
                return count;
            }
        }
        return 0;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
*/
