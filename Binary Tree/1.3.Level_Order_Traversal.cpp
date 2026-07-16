/*
QUESTION:
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/

/*
APPROACH:
1. If the root is NULL, return an empty answer.
2. Create a queue and push the root node into it.
3. While the queue is not empty:
   a. Store the current size of the queue (this is the number of nodes in the current level).
   b. Create a temporary vector to store the current level.
   c. Repeat 'size' times:
      - Remove the front node from the queue.
      - Store its value in the temporary vector.
      - If the left child exists, push it into the queue.
      - If the right child exists, push it into the queue.
   d. Add the temporary vector to the final answer.
4. Return the final answer.
*/

//CODE;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left != NULL) {
                    q.push(node->left);
                }

                if(node->right != NULL) {
                    q.push(node->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};

/*
Time Complexity
O(n)

Every node is visited exactly once.

Space Complexity
O(n)

In the worst case, the queue may contain all nodes of the largest level of the tree.
*/
