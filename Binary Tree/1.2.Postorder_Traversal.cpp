/*
QUESTION:
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]
*/

/*
APPROACH:
1. Start from the root node.
2. If the current node is NULL, return.
3. Recursively traverse the left subtree.
4. Recursively traverse the right subtree.
5. Visit the current node and store its value in the answer vector.
6. Repeat the process until all nodes are visited.
7. Return the answer vector.
*/

//CODE:
class Solution {
public:
    vector<int> ans;
    void postorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};

/*
Time Complexity
O(n)

Space Complexity
O(h)
*/
