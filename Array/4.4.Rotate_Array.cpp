/*
QUESTION:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

/*
APPROACH:

1. First calculate `d = k % n` because if `k` is greater than the array size, extra rotations are repeated.
2. Reverse the first `n-d` elements.
3. Reverse the last `d` elements.
4. Reverse the complete array.
This results in rotating the array to the right by `k` positions.

**Time Complexity:** O(n)

**Space Complexity:** O(1)

*/

//CODE:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int d = k%n;
        reverse(nums.begin(), nums.begin()+(n-d));
        reverse(nums.begin()+(n-d),nums.end());
        reverse(nums.begin(),nums.end());
        
    }
   
};
