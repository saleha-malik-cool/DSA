/*
QUESTION:
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true
*/

/*
APPROACH:

1. A tree is symmetric if its left subtree is the mirror image of its right subtree.
2. Create a helper function isMirror(left, right) to compare two nodes.
3. If both nodes are NULL, return true because they are symmetric.
4. If one node is NULL and the other is not, return false.
5. If both node values are different, return false.
6. Recursively compare:
   - left->left with right->right
   - left->right with right->left
   because in a mirror image, the outer children and inner children should match.
7. If both recursive calls return true, then the current pair of nodes is symmetric.
8. In the main function, call:
   isMirror(root->left, root->right)
9. If the helper function returns true, the tree is symmetric; otherwise, it is not.
*/

//CODE:
class Solution {
public:
    bool mirror( TreeNode*left , TreeNode*right){
        if(left == NULL && right==NULL){
            return true;
        }
        if(left == NULL ||right==NULL){
            return false;
        }
        if(left->val!= right->val){
            return false;
        }
        return mirror(left->left ,right->right)&& 
        mirror(left->right , right->left);
        

    }
    bool isSymmetric(TreeNode* root) {
         if(root==NULL){
            return true;
        }
        return mirror(root->left, root->right);

    }
};

/*
Time Complexity: O(N)
Reason:
Each node is visited only once during the recursive mirror check.

Space Complexity: O(H)
Reason:
Recursive calls use stack space equal to the height of the tree.
Balanced Tree  → O(log N)
Skewed Tree    → O(N)
*/
