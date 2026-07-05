/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the
next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array,which
means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
*/
/*
Approach (Monotonic Stack + Circular Array)
1. Observation
For every element, we need to find the first greater element on its right.
Since the array is circular, if we reach the end of the array, we continue searching from the beginning.
For example:
nums = [1, 2, 1]
For the last 1:
Right side → (end)
Continue from beginning → 1, 2
Next greater = 2
2. Simulate a Circular Array
Instead of actually creating a new array, traverse the original array twice.
Loop from:
2*n - 1  →  0
Whenever we access an element, use:
nums[i % n]
This makes the traversal look like:
Original:
0 1 2
Traversal:
2 1 0 2 1 0
Thus, every element gets a chance to see all elements to its right, even after wrapping around.
3. Use a Monotonic Decreasing Stack
Maintain a stack that stores possible next greater elements.
For every element:
Remove all elements from the stack that are smaller than or equal to the current element because they can never be 
the next greater element.
After popping:
If the stack is not empty, the top of the stack is the next greater element.
Otherwise, the answer remains -1.
Push the current element onto the stack.
4. Why if (i < n)?
The loop has two passes:
First pass (i >= n): Build the stack with elements so that circular elements are available.
Second pass (i < n): Compute the answers for the original array.
We only store answers during the second pass because the first pass is used only to prepare the stack.

#Algorithm
1.Initialize an answer array with -1.
2.Create an empty stack.
3.Traverse from 2*n - 1 down to 0.
4.While the stack is not empty and its top is less than or equal to the current element, pop it.
5.If i < n and the stack is not empty, store the stack's top as the next greater element.
6.Push the current element (nums[i % n]) onto the stack.
7.Return the answer array.
*/

//CODE:
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack <int> s;
        for(int i = 2*n - 1; i>=0; i-- ){
            while(! s.empty() && s.top()<=nums[i%n]){
                s.pop();
            }
            if (i<n){
                if(!s.empty()){
                    ans[i]= s.top();
                }
               
            }
            s.push(nums[i%n]);
            
            }
            return ans;
        }
    }
;
/*
Time Complexity
O(n)
Each element is pushed and popped from the stack at most once per traversal, so the total number of stack 
operations is linear.
Space Complexity
O(n)
The stack can store at most n elements in the worst case, and the answer array also requires O(n) space.
*/
