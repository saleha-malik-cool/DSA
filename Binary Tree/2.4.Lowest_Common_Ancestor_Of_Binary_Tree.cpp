/*
QUESTION:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as
the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
*/

/*
APPROACH:

1. Start traversing the tree from the root using recursion.
2. If the current node is NULL, return NULL because no node is found in this path.
3. If the current node is equal to p or q, return the current node because we have found one of the required nodes.
4. Recursively search for p and q in the left subtree and store the result in 'left'.
5. Recursively search for p and q in the right subtree and store the result in 'right'.
6. If both 'left' and 'right' are not NULL, it means one node is found in the left subtree and the other is found 
in the right subtree. Therefore, the current node is the Lowest Common Ancestor, so return the current node.
7. If only 'left' is not NULL, it means both nodes (or the LCA) are present in the left subtree, so return 'left'.
8. If only 'right' is not NULL, it means both nodes (or the LCA) are present in the right subtree, so return 'right'.
9. The answer returned by the initial function call is the Lowest Common Ancestor of p and q.
*/

//CODE:
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)
            return root;
        if(left!=NULL){
            return left;
        }
        return right;

    }
};

/*
Time Complexity: O(N)
Reason:
Each node is visited only once during the recursive traversal of the tree.

Space Complexity: O(H)
Reason:
The extra space is used only by the recursive call stack, where H is the height of the tree.
Balanced Tree: O(log N)
Skewed Tree: O(N)
*/
