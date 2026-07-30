/*
QUESTION:
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge
connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass 
through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/

/*
APPROACH:

1. Use postorder traversal (Left → Right → Root) because the answer at each node depends on its left and right 
subtrees.
2. For every node, recursively calculate the maximum contribution from the left and right child.
3. Ignore negative contributions:
   left = max(0, solve(root->left))
   right = max(0, solve(root->right))
   A negative path decreases the total sum, so it is better not to include it.
4. Calculate the maximum path passing through the current node:
   currentPath = root->val + left + right
5. Update the global answer:
   maxsum = max(maxsum, currentPath)
   This checks whether the path passing through the current node gives a better answer.
6. Return only one branch to the parent:
   return root->val + max(left, right)
   because a path cannot split into both left and right while moving upward.
7. After visiting all nodes, maxsum stores the maximum path sum in the entire tree.

*/

//CODE;
class Solution {
public:
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int maxi =INT_MIN;
        int left = max(0,solve(root->left));
        int right =max(0,solve(root->right));
        maxsum = max(maxsum , root->val + left + right);
        return root->val + max(left,right);

    }
    int maxsum;
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
        
    }
};
//Time Complexity: O(N)
//Space Complexity: O(H), where H is the height of the tree.
