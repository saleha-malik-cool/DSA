/*
QUESTION:
Given an array of integers nums, return the value of the largest element in the array

Example 1
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6
*/

/*
APPROACH:
1. Assume the first element is the largest.
2. Traverse the remaining elements.
3. Use max() to compare the current largest with nums[i].
4. Update largest.
5. Return largest.

TC: O(n)
SC: O(1)
*/

//CODE:
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i =0; i<n; i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
