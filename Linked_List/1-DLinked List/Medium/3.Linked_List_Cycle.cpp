/*
Question:- 
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 */
/*
example:-
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/
/*
Optimal Approach:-
1. We initialise two nodes, fast and slow. Fast will jump two nodes at a time. Slow will jump to the next node.
2. While fast != NULL && fast->next != NULL {in case of odd number of nodes}, we move fast to the next to next node and slow to the next node.
3. If there will ever be a loop in the linked list, slow and fast will eventually meet. So, we check if fast == slow. If yes, return true.
4. If loop is broken, that means fast reached NULL. That means there is no loop. Return false.
*/
//Code:-
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast!=NULL && fast->next!=NULL){
           slow= slow-> next;
            fast = fast-> next->next;
            if (fast==slow){
                return true;
            }
           
        }
        return false;
    }
};
//Time complexity=O(N)
//Space Complexity : O(1)

/*
Brute force:-
1. We create an unordered set to store the nodes, while traversing through the linked list.
2. We initialise a new listnode, temp and assign it the value of head.
3. While temp != NULL, we check if we have already saved the current node in the set. If not,
we insert temp in the set.
4. Else, return true {since that means the same node is visited again, which means there exists a loop}.
5. Keep moving temp to the next node and checking for the same thing.
6. If the loop is broken without returning anything, that means no loop exists in the linked list. Return false.
*/
//Code:-
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>mpp;
        ListNode* temp = head;
        while(temp!=NULL){
            if(!mpp.count(temp)){
                mpp.insert(temp);
            }
            else{
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
//Time Complexity : O(N)
//Space Complexity : O(N)
