/*
QUESTION:
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that
the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it 
is not in nums.
You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

*/

/*
APPROACH;

1. Initialize two pointers, `start = 0` and `end = n - 1`.
2. Run a loop while `start <= end` and calculate the middle index `mid`.
3. If `nums[mid] == target`, return `true`.
4. If `nums[start] == nums[mid]`, increment `start` by one because duplicates make it difficult to identify the sorted half.
5. If the left half is sorted (`nums[start] < nums[mid]`):

   * If the target lies between `nums[start]` and `nums[mid]`, set `end = mid - 1`.
   * Otherwise, set `start = mid + 1`.
6. Otherwise, the right half is sorted:

   * If the target lies between `nums[mid]` and `nums[end]`, set `start = mid + 1`.
   * Otherwise, set `end = mid - 1`.
7. If the target is not found after the loop, return `false`.

Time Complexity:** Average case: O(log n); worst case: O(n) due to duplicates.

Space Complexity:** O(1)

*/

//CODE:

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[start] == nums[mid]) {
                start++;
            }
            else if (nums[start] < nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return false;
    }
};
