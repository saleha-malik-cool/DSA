/*
QUESTION:
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of 
the values of all nodes that have a distance k from the target node.
You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
*/

/*
APPROACH:
1. Create a parent map to store the parent of every node because in a binary tree we can normally move only from 
parent to child.
2. Use BFS to create the parent mapping.
3. Start another BFS from the target node.
4. Maintain a `visited` map so that we do not visit the same node again.
5. From every current node, we can move in 3 directions:
   - Left child
   - Right child
   - Parent
6. Initially, target is at distance 0.
7. Process the tree level by level using BFS.
8. After processing one complete level, increase `distance` by 1.
9. When `distance == k`, stop the BFS because all nodes currently present in the queue are exactly `k` distance
away from the target.
10. Store the values of all nodes remaining in the queue into the answer vector.
11. Return the answer.

Time Complexity: O(n)
Space Complexity: O(n)
*/

//CODE:
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void markparent(TreeNode* root){
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            parent[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parent[node->right] = node;
            q.push(node->right);
        }
       }


    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markparent(root);
        unordered_map <TreeNode* , bool> visited;
        queue <TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance =0;

        while(!q.empty()){
            int size = q.size();

            if(distance==k){
                break;
            }
        

        for(int i =0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }

            if(node->right && !visited [node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parent[node] && !visited[parent[node]]){
                q.push(parent[node]);
                visited[parent[node]] = true;
            }
        }
        distance++;}

        vector <int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

        
    }
};
