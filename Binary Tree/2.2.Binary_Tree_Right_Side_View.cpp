/*
QUESTION:
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the
nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
*/

/*
APPROACH:
1. If the root is NULL, return an empty vector.
2. Create a queue and push the root node into it.
3. While the queue is not empty:
   - Find the number of nodes at the current level (size = q.size()).
   - Traverse all nodes of that level.
   - Pop the front node from the queue.
   - Push its left child into the queue (if it exists).
   - Push its right child into the queue (if it exists).
   - If the current node is the last node of this level (i == size - 1),
     store its value in the answer because it is visible from the right side.
4. Repeat the above steps until all levels are processed.
5. Return the answer vector.
*/

//CODE:
while(!q.empty()){

    int size = q.size();

    for(int i = 0; i < size; i++){

        TreeNode* node = q.front();
        q.pop();

        if(node->left)
            q.push(node->left);

        if(node->right)
            q.push(node->right);

        if(i == size-1)
            ans.push_back(node->val);
    }
}

/*
Time Complexity: O(N)
- Every node is visited exactly once.
- Each node is pushed into and popped from the queue only one time.

Space Complexity: O(N)
- The queue stores the nodes of one level.
- In the worst case, it may contain O(N) nodes.
- Therefore, the overall space complexity is O(N).
*/
