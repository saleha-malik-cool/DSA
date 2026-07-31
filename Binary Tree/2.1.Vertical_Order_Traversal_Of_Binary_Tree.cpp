/*
QUESTION:
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and 
(row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting
from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same
column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
*/

/*
APPROACH:

1. We need to print the nodes according to three conditions:
   - First by Column (left to right).
   - If two nodes are in the same column, then by Row (top to bottom).
   - If both row and column are the same, then print the smaller node value first.
2. Perform a DFS traversal and assign every node a coordinate.
   - Root -> (row = 0, col = 0)
   - Left child -> (row + 1, col - 1)
   - Right child -> (row + 1, col + 1)
3. Choose the correct data structure:
   map<int, map<int, multiset<int>>> mp
   Reason:
   - Outer map -> Column
     Since the final answer is column-wise, the outer key must be the column. map automatically keeps columns sorted
     from left to right.
   - Inner map -> Row
     A single column can contain nodes from different rows, so we must also store the row. The inner map
     automatically keeps rows sorted from top to bottom.
   - Multiset -> Node Values
     If multiple nodes have the same row and the same column, multiset automatically stores their values in ascending
     order.
4. During DFS, store every node as:
   mp[col][row].insert(root->val);
   This means:
   - Go to the current column.
   - Inside that column, go to the current row.
   - Insert the node value in sorted order.
5. After DFS, the map contains all nodes arranged as:
   Column
      ↓
   Row
      ↓
   Sorted Node Values
6. Traverse the map to build the answer:
   - Traverse the outer map to visit columns from left to right.
   - For each column, create a temporary vector.
   - Traverse the inner map to visit rows from top to bottom.
   - Traverse the multiset and add all node values to the temporary vector.
   - Push the temporary vector into the final answer.
7. Return the final answer.
Why can't we use map<int, vector<int>>?
- It only groups nodes by column.
- It does not store row information.
- Therefore, we cannot maintain the required top-to-bottom order within a column.
Why can't we use vector instead of multiset?
- If two nodes have the same row and the same column, DFS may insert them in any order.
- LeetCode requires them to be sorted by value.
- multiset automatically maintains ascending order.
*/

//CODE:
class Solution {
public:
    map<int,map<int,multiset<int>>> mp;
    void solve(TreeNode* root, int row, int col){
        if(root==NULL){
            return ;
        }
        mp[col][row].insert(root->val);
       solve(root->left, row+1, col-1);
       solve(root->right, row+1,col+1);


    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        solve(root,0,0);
        vector<vector<int>> ans;
        for(auto col: mp ){
            vector<int>temp;
            for(auto row : col.second){
                for(auto val: row.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

/*
Time Complexity:
- DFS Traversal: O(N)
- Each insertion into map/multiset: O(log N)
- Overall: O(N log N)

Space Complexity:
- O(N)
*/
