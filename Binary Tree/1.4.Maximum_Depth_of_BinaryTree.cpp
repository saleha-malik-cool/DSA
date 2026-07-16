/*
QUESTION:
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest
leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
*/

/*
APPROACH:
1. If the current node is NULL, return 0 because an empty tree has depth 0.
2. Recursively calculate the maximum depth of the left subtree.
3. Recursively calculate the maximum depth of the right subtree.
4. Compare both depths and take the maximum.
5. Add 1 to include the current node.
6. Return the final depth.
*/

//CODE:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left= maxDepth(root->left);
        int right= maxDepth(root->right);
        int depth = 1+ max(left,right);
        return depth;
    }
};

/*
Time Complexity
O(n)
Every node is visited exactly once.

Space Complexity
O(h)
where h is the height of the tree.
Balanced Tree: O(log n)
Degenerate Tree: O(n)
*/
