/*
QUESTION:
Given a binary tree, determine if it is height-balanced.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true
*/

/*
BRUTE APPROACH:
1. If the current node is NULL, return true because an empty tree is always balanced.
2. Calculate the height of the left subtree using the height() function.
3. Calculate the height of the right subtree using the height() function.
4. Find the absolute difference between the left and right heights.
5. If the difference is greater than 1, return false because the current node is not balanced.
6. If the current node is balanced, recursively check whether the left subtree is balanced.
7. Recursively check whether the right subtree is balanced.
8. Return true only if both the left and right subtrees are balanced.
*/

//CODE:
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left= height(root->left);
        int right= height (root->right);


        if(abs(left - right) >1){
            return false;
        }
        return (isBalanced(root->left) && isBalanced(root->right));

    }
};

/*
Complexity
Time Complexity: O(n²) (heights are recalculated for many nodes)
Space Complexity: O(h) (recursive call stack)
*/

/*
OPTIMAl APPROACH:
1. Create a recursive function height(root).
2. If the current node is NULL, return 0.
3. Recursively calculate the height of the left subtree.
4. If the left subtree is unbalanced (returns -1), immediately return -1.
5. Recursively calculate the height of the right subtree.
6. If the right subtree is unbalanced (returns -1), immediately return -1.
7. Check the height difference:
   abs(leftHeight - rightHeight).
8. If the difference is greater than 1, return -1 because the current subtree is unbalanced.
9. Otherwise, return the height of the current subtree:
   1 + max(leftHeight, rightHeight).
10. In isBalanced(), call height(root).
11. If height(root) returns -1, return false.
    Otherwise, return true.
*/

//OPTIMAL CODE:
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        if(left == -1){
            return -1;
        }

        int right= height(root->right);
        if(right==-1){
            return -1;
        }

        if(abs(left-right) >1){
            return -1;
        }
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(height(root)==-1){
            return false;
        }
        return true;
    }
};

/*
ime Complexity
O(n)

Each node is visited exactly once.

Space Complexity
O(h)

where h is the height of the tree.

Balanced Tree → O(log n)
Skewed Tree → O(n)
*/
