/*
QUESTION:
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/

/*
APPROACH:
1. If both nodes are NULL, return true because both trees have ended.
2. If one node is NULL and the other is not, return false because the structures are different.
3. If the values of both nodes are different, return false.
4. Recursively compare the left subtrees.
5. Recursively compare the right subtrees.
6. If both the left and right subtrees are identical, return true.
   Otherwise, return false.


Intuition
At every node, check three things:
1. Both nodes should exist (or both should be NULL).
2. The values of both nodes should be equal.
3. The left subtrees should be identical and the right subtrees should also be identical.
If all three conditions are satisfied for every node, the two trees are the same.
*/

//CODE:
class Solution {
public:
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== NULL && q== NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }
        
        if(p->val != q->val){
            return false;
        }
        

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
Time Complexity
O(n)
Each corresponding pair of nodes is visited only once.

Space Complexity
O(h)
where h is the height of the tree.
Balanced Tree: O(log n)
Skewed Tree: O(n)
*/
