/*
QUESTION:
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

*/

/*
APPROACH: 

1. If the root is NULL, return an empty answer.
2. Use a queue to perform Level Order Traversal (BFS) and push the root node into it.
3. Process the tree level by level. For each level:
   - Find the number of nodes present in the current level.
   - Create a vector `level` to store the values of that level.
4. Traverse all nodes of the current level:
   - Pop the front node from the queue.
   - Store its value in the `level` vector.
   - Push the right child first and then the left child into the queue (if they exist).
5. After processing one complete level, increment the level counter.
   - If the current level number is odd, reverse the `level` vector to obtain the required zigzag order.
6. Store the `level` vector in the final answer.
7. Repeat the above steps until the queue becomes empty.
8. Return the final answer.
*/

//CODE:
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       queue<TreeNode* > q;
       vector<vector<int>>ans;
       if(root==NULL){
        return ans;
       }
       int num=0;
       q.push(root);
       while(!q.empty()){
        int size= q.size();
        vector<int>level;
        for(int i =0; i<size; i++){
            TreeNode* node= q.front();
            q.pop();
            level.push_back(node->val);
            if(node->right!= NULL){
                q.push(node->right);
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
           

        }
         num++;
        if(num%2==1){
            reverse(level.begin(),level.end());
        }
        ans.push_back(level);
       }
       return ans;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)
