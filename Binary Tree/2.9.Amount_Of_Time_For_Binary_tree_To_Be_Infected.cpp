/*
QUESTION:
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection
starts from the node with value start.
Each minute, a node becomes infected if:
The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Example 1:
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

*/

/*
Approach:
1. First create a parent map using BFS because infection can spread from a node to its left child, right child,
and parent.
2. While creating the parent map, also find the actual TreeNode whose value is equal to `start` and store it in
`startval`, because `start` is an integer and the BFS queue stores `TreeNode*`.
3. Start BFS from `startval` and mark it as visited.
4. From every current node, move in three directions: left child, right child, and parent.
5. Use a visited map to avoid visiting the same node again.
6. Process the tree level by level because each level represents 1 minute of infection.
7. After processing one complete level, increase `minute` only if the queue is not empty, otherwise one extra 
minute will be counted.
8. When the queue becomes empty, all nodes are infected, so return `minute`.

Time Complexity: O(n)
Space Complexity: O(n)
*/

//CODE:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , TreeNode*> parent;
    TreeNode* startval= NULL;
    void markparent(TreeNode* root,int start){
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start){
                startval = node;
            }

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
    int amountOfTime(TreeNode* root, int start) {
        markparent(root, start);
        int minute =0;
        unordered_map <TreeNode* , bool> visited;
        queue<TreeNode*> q;
        q.push(startval);
        visited[startval] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i =0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
            if(!q.empty()){
            minute++;}
        }
        return minute;
    }
};
