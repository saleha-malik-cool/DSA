/*
QUESTION:
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]
*/

/*
APPROACH:
1. Start from the root node.
2. If the current node is NULL, return.
3. Recursively traverse the left subtree.
4. Visit the current node and store its value in the answer vector.
5. Recursively traverse the right subtree.
6. Repeat the process until all nodes are visited.
7. Return the answer vector.
*/

//CODE:
class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

/*
Time Complexity
O(n)

Space Complexity
O(h)
*/
