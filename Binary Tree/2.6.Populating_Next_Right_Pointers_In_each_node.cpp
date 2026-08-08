/*
QUESTION:
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition:
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should
be set to NULL.
Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to
point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next
pointers, with '#' signifying the end of each level.
*/

/*
APPROACHL:
Approach:

1. We need to connect all nodes present at the same level using the `next` pointer.
2. For this, we use Level Order Traversal (BFS) with a queue.
3. Push the root into the queue.
4. At the start of every level, store the current queue size in `size`.
5. Process exactly `size` nodes because these nodes belong to the current level.
6. For every node:
   - Remove it from the queue.
   - If it is not the last node of the current level, connect it to the next node using:
     `value->next = q.front();`
   - Push its left child into the queue if it exists.
   - Push its right child into the queue if it exists.
7. The last node of every level is not connected to another node, so its `next` remains `NULL`.
8. Repeat until the queue becomes empty.
*/

//CODE:
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                Node* value = q.front();
                q.pop();

                if(i != size - 1) {
                    value->next = q.front();
                }

                if(value->left) {
                    q.push(value->left);
                }

                if(value->right) {
                    q.push(value->right);
                }
            }
        }

        return root;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

/*
APPROACH 2:
1. Since the tree is a Perfect Binary Tree, every node has either 0 or 2 children.
2. If the root is NULL or it has no left child, return.
3. First connect the left child to the right child:
   root->left->next = root->right
4. Now connect the right child to the left child of the next node:
   root->right->next = root->next->left
5. We check root->next because we need to connect nodes across different parent nodes.
6. Recursively perform the same process on the left and right subtrees.
7. Initially, root->next is NULL because there is no node to the right of the root.
8. Finally, return the root.

Example:

        1
      /   \
     2     3
    / \   / \
   4   5 6   7

Connections:
2 -> 3 -> NULL
4 -> 5 -> 6 -> 7 -> NULL

*/

//CODE:
class Solution {
public:
    void solve(Node* root) {
        if(root == NULL || root->left == NULL) {
            return;
        }

        // Connect left child to right child
        root->left->next = root->right;

        // Connect right child to next node's left child
        if(root->next) {
            root->right->next = root->next->left;
        }

        solve(root->left);
        solve(root->right);
    }

    Node* connect(Node* root) {
        if(root == NULL) {
            return NULL;
        }

        root->next = NULL;
        solve(root);

        return root;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(H), where H is the height of the tree.
*/
