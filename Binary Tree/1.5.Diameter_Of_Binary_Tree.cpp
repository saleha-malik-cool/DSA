/*
QUESTION:
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the 
root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
*/

/*
BRUTE FORCE APPROACH:
1. If the current node is NULL, return 0.
2. Calculate the diameter of the left subtree.
3. Calculate the diameter of the right subtree.
4. Calculate the height of the left subtree.
5. Calculate the height of the right subtree.
6. The diameter passing through the current node is:
   height(left) + height(right)
   (For LeetCode 543, diameter is measured in edges.)
7. The final diameter is the maximum of:
   - Diameter of the left subtree.
   - Diameter of the right subtree.
   - Diameter passing through the current node.
8. Return the maximum value.

Intuition
At every node, there are 3 possible cases:
1. The longest path lies completely in the left subtree.
2. The longest path lies completely in the right subtree.
3. The longest path passes through the current node.

*/

//CODE:
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right);

        return max(op3, max(op1, op2));
    }
};

/*
Time Complexity
O(n²)
Because every call to diameterOfBinaryTree() calls height(), and height() traverses the subtree again.

Space Complexity
O(h)
where h is the height of the tree.
*/

/*
OPTIMAL APPROACH:
1. Initialize a variable 'diameter' to store the maximum diameter.
2. Create a recursive function height(root).
3. If the current node is NULL, return 0.
4. Recursively find the height of the left subtree.
5. Recursively find the height of the right subtree.
6. The diameter passing through the current node is:
   leftHeight + rightHeight.
7. Update the maximum diameter:
   diameter = max(diameter, leftHeight + rightHeight).
8. Return the height of the current node:
   1 + max(leftHeight, rightHeight).
9. Call height(root).
10. Return the value of diameter.

Intuition
Instead of calculating the height separately for every node,
calculate the height while traversing the tree.
At each node:
1. Get the left subtree height.
2. Get the right subtree height.
3. Update the diameter using leftHeight + rightHeight.
4. Return the current node's height.
This way, every node is visited only once.
*/

//CODE:
class Solution {
public:
    int diameter =0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left= height(root->left);
        int right= height(root->right);
         diameter= max(diameter,left + right );
        return max(left,right) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;    }
};

/*
Time Complexity
O(n)
Every node is visited exactly once.

Space Complexity
O(h)
where h is the height of the tree.
Balanced Tree: O(log n)
Degenerate Tree: O(n)
*/
