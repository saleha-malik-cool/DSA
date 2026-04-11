/*
QUESTION:-
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

Example:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/

//BRUTE-FORCE CODE:

/*
APPROACH:
1. We initialise an unordered set, which will contain listnodes visited.
2. We create a listnode temp, and initialise it with head.
3. While temp != NULL, we check if we already have the current node in the set. If not, we insert temp to the set.
4. If yes, we return that node, because that is the first node that is visited twice, hence the first node of the loop.
5. If the loop breaks without returning anything, return NULL.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>mpp;
        ListNode*temp = head;
        
        while(temp!=NULL){
            if(!mpp.count(temp)){
                mpp.insert(temp);
            }
            
            else{
                return temp; 
            }
        
            temp = temp->next;
        }
        return NULL;
        
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)

/*
APPROACH:
1. We create two pointers, fast and slow, initialising them to head.
2. While fast != NULL && fast->next != NULL {for odd number of nodes}, we move fast to the next to next node, and slow to the next node.
3. If slow == fast, we know it's a loop.
4. When slow and fast meet, by mathematical calculation, we get that the first node of the loop is equally far from the head, as it is from the node where slow and fast meet.
5. So, we reinitialise slow to head. We move fast and slow both once at a time.
6. When slow and fast meet again, that is the first node of the loop. Return fast.
7. If the loop is exited without returning anything, that means loop does not exist. So, return NULL.
*/
//Code:-
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
