/*
QUESTION:
Given a binary tree
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer 
should be set to NULL.
Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to
its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
*/

/*
APPROACH:
1. We need to connect nodes present at the same level using the `next` pointer.
2. If the root is NULL, return.
3. First connect the left child to the right child of the current node:
   root->left->next = root->right
4. For a non-perfect binary tree, the right child of the current node may need to connect to a child of some node 
present further in the `next` chain.
5. So, if `root->next` exists, create a temporary pointer:
   temp = root->next
6. Traverse the `next` chain using a while loop.
7. For every `temp` node:
   - If `temp->left` exists, connect the current node's child to `temp->left`.
   - Otherwise, if `temp->right` exists, connect the current node's child to `temp->right`.
   - Once a child is found, stop using `break`.
8. If the current `temp` node has no children, move to the next node:
   temp = temp->next
9. We process the right subtree before the left subtree:
   ans(root->right);
   ans(root->left);
   This ensures that the `next` pointers on the right side are already available when the left subtree needs to 
   search through the `next` chain.
10. Finally, return the root.
Example:

        1
      /   \
     2     3
    / \     \
   4   5     6
  /           \
 7             8

Connections:
Level 0:
1 -> NULL
Level 1:
2 -> 3 -> NULL
Level 2:
4 -> 5 -> 6 -> NULL
Level 3:
7 -> 8 -> NULL

*/

//CODE:
class Solution {
public:
    void ans(Node* root) {
        if(root == NULL) {
            return;
        }

        // Connect left child to right child
        if(root->left && root->right) {
            root->left->next = root->right;
        }

        // Find next available child
        if(root->next) {
            Node* temp = root->next;

            while(temp) {

                if(temp->left) {
                    if(root->right) {
                        root->right->next = temp->left;
                    }
                    else if(root->left) {
                        root->left->next = temp->left;
                    }
                    break;
                }

                if(temp->right) {
                    if(root->right) {
                        root->right->next = temp->right;
                    }
                    else if(root->left) {
                        root->left->next = temp->right;
                    }
                    break;
                }

                temp = temp->next;
            }
        }

        // Right first, then left
        ans(root->right);
        ans(root->left);
    }

    Node* connect(Node* root) {
        ans(root);
        return root;
    }
};

/*
Time Complexity: O(N) approximately, with traversal of next pointers.
Space Complexity: O(H), where H is the height of the tree due to recursion.
*/
