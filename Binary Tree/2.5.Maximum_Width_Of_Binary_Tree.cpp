/*
QUESTION:
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes),
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that
level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
*/

/*
Approach (Maximum Width of Binary Tree)
1. We use Level Order Traversal (BFS) because the width is calculated level by level.
2. Store every node in the queue along with its index.
   - Root index = 0
   - Left child = 2 * index + 1
   - Right child = 2 * index + 2
3. For every level:
   - Store the number of nodes present in that level.
   - Store the first index of the level as `mini`.
   - We subtract `mini` from every index of the current level to normalize the indices.
   - This prevents integer overflow for very deep trees.
4. Traverse all nodes of the current level.
   - Pop the front node and its index.
   - Compute:
     index = curr.second - mini
   - If it is the first node of the level, store it as `start`.
   - If it is the last node of the level, store it as `end`.
   - Push the left child with index = 2 * index + 1.
   - Push the right child with index = 2 * index + 2.
5. After processing the complete level, calculate:
   width = end - start + 1
   Update the answer:
   maxWidth = max(maxWidth, width)
6. Return the maximum width.
Important Mistakes to Avoid
• Handle the edge case:
  if(root == NULL) return 0;
• Queue stores pair<TreeNode*, long long>, so use:
  auto curr = q.front();
• Never write:
  index = q.front().second - mini;
  after q.pop().
  After popping, q.front() points to the next node.
  Always use:
  index = curr.second - mini;
• Use long long for indices to avoid overflow.
• Normalize every level:
  index = curr.second - mini
• Update start when i == 0 and end when i == size - 1.
• Calculate the width only AFTER the entire level is processed.
  Do not calculate it inside the for loop because `end` is not known until the last node of the level.
• Width Formula:
  width = end - start + 1

*/

//CODE:
while(!q.empty()) {

    int size = q.size();
    long long start, end;
    long long mini = q.front().second;

    for(int i = 0; i < size; i++) {

        auto curr = q.front();
        q.pop();

        long long index = curr.second - mini;

        if(i == 0)
            start = index;

        if(i == size - 1)
            end = index;

        if(curr.first->left)
            q.push({curr.first->left, 2 * index + 1});

        if(curr.first->right)
            q.push({curr.first->right, 2 * index + 2});
    }

    maxwidth = max(maxwidth, (int)(end - start + 1));
}
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
