/*
QUESTION:

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum 
of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/

//CODE:
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            start = max(start, nums[i]);
            end += nums[i];
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (canplace(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    bool canplace(vector<int>& nums, int k, int mid) {
        int place = 1;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] > mid) {
                sum = nums[i];
                place++;
            } else {
                sum += nums[i];
            }
        }
        if (place <= k) {
            return true;
        } else {
            return false;
        }
    }
};
