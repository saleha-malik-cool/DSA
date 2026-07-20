/*
QUESTION:
Given the root of a Binary Tree with n nodes, check whether it is a Sum Tree and return true if it is, 
otherwise return false.
A Sum Tree is a Binary Tree in which the value of every non-leaf node is equal to the sum of all nodes present 
in its left and right subtrees. An empty tree and a leaf node are also considered Sum Trees.
Examples:

Input: root[] = [3, 1, 2]
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. 
Therefore, the given binary tree is a sum tree.
*/

/*
Brute Force APPROACH:
1. Create a function Sum() to calculate the total sum of a subtree.
2. If the node is NULL, return 0 because an empty tree contributes no value.
3. Otherwise, return:
   Current Node Value + Left Subtree Sum + Right Subtree Sum.
4. In isSumTree(), if the current node is NULL, return true because an empty tree is a Sum Tree.
5. If the current node is a leaf node, return true because a leaf node has no children.
6. Calculate the total sum of the left subtree using Sum(node->left).
7. Calculate the total sum of the right subtree using Sum(node->right).
8. Check whether:
   node->data == leftSum + rightSum.
9. If the condition is false, return false.
10. If the current node satisfies the condition, recursively check the left subtree.
11. Recursively check the right subtree.
12. Return true only if both left and right subtrees are also Sum Trees.


*/

//CODE:
class Solution {
  public:
    int Sum(Node* node){
        if(node==NULL){
            return 0;
        }
       
        return (node->data) +Sum(node->left) +Sum(node-> right);
    }
    bool isSumTree(Node* node) {
       if(node==NULL){
           return true;
       }
       if(node->right==NULL && node->left == NULL){
           return true;
       }
       int left = Sum(node->left);
       int right = Sum(node->right);
       
       if(node->data != left+right)
       return false;
       
       return isSumTree(node->left) && isSumTree(node->right);
       
        
    }
};

/*
Time Complexity
O(n²)
Why?
Har node par hum Sum() call karte hain.
Aur Sum() dobara us subtree ke saare nodes visit karta hai.
Example:
Root
↓
Sum(left)
↓
Visits all left nodes
↓
isSumTree(left)
↓
Again Sum(left->left)
↓
Again visits nodes
Same nodes baar-baar visit hote hain.
Isliye O(n²).

Space Complexity
O(h)
where h = height of the tree.
This space is used by the recursive call stack.
*/

/*
OPTIMAL APPROACH:
1. Create a recursive function sum().
2. If the current node is NULL, return 0 because an empty tree has sum 0.
3. If the current node is a leaf node, return its value because a leaf node is always a Sum Tree.
4. Recursively calculate the sum of the left subtree.
5. If the left subtree returns -1, it means it is not a Sum Tree, so return -1 immediately.
6. Recursively calculate the sum of the right subtree.
7. If the right subtree returns -1, it means it is not a Sum Tree, so return -1 immediately.
8. Check whether:
   node->data == leftSum + rightSum.
9. If the condition is false, return -1 because the current subtree is not a Sum Tree.
10. If the condition is true, return the total sum of the current subtree.
    Since:
    node->data = leftSum + rightSum,
    Total Subtree Sum = node->data + leftSum + rightSum
                      = 2 × node->data.
11. In isSumTree(), call sum(root).
12. If sum(root) returns -1, return false.
    Otherwise, return true.

*/

//CODEL:
class Solution {
  public:
  int sum(Node* node){
      if(node==NULL){
          return 0;
      }
      if(node->left==NULL && node->right==NULL){
          return node->data;
      }
     int left = sum(node->left);
        if(left == -1) return -1;

        int right = sum(node->right);
        if(right == -1) return -1;

        if(node->data != left + right){
            return -1;
        }
         return 2 * node->data;}
 
    bool isSumTree(Node* node) {
        // code here
        int ans = sum(node);
        
        if(ans != -1){
             return true;
                }
        else{
            return false;
                }   
    }
};

/*
Time Complexity
O(n)
Each node is visited only once.

Space Complexity
O(h)
where h is the height of the tree.
Balanced Tree → O(log n)
Skewed Tree → O(n)
*/
