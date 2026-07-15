/*
QUESTION:
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]
*/

/*
APPROACH:
1. Start from the root node.
2. If the current node is NULL, return.
3. Visit the current node first and store its value in the answer vector.
4. Recursively traverse the left subtree.
5. Recursively traverse the right subtree.
6. Continue this process until all nodes are visited.
7. Return the answer vector.
*/

//CODE:
class Solution {
public:
    vector <int> ans;
    void preorder(TreeNode* root){
        if(root== NULL){
            return;
        }
        ans.push_back(root->val);  
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};

/*
Time Complexity (TC)
O(n)

Why?
n = total number of nodes.
Every node is visited exactly once.
At each node, we perform only constant-time work (push_back() and recursive calls).
So,
1 node → O(1)
n nodes → O(n)


Space Complexity (SC)
O(h)
where h = height of the tree.

Why?
The extra space comes from the recursion call stack.
At any moment, the maximum number of recursive calls equals the height of the tree.
*/
