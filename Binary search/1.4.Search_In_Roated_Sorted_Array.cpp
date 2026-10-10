/*
QUESTION:
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

*/

/*
### Approach: Binary Search

1. Initialize two pointers, `start = 0` and `end = n - 1`.
2. Run a loop while `start <= end` and calculate the middle index `mid`.
3. If `nums[mid] == target`, return `mid`.
4. If the left half is sorted (`nums[start] <= nums[mid]`):

   * Check whether the target lies between `nums[start]` and `nums[mid]`.
   * If yes, search the left half by setting `end = mid - 1`.
   * Otherwise, search the right half by setting `start = mid + 1`.
5. If the left half is not sorted, the right half must be sorted:

   * Check whether the target lies between `nums[mid]` and `nums[end]`.
   * If yes, search the right half by setting `start = mid + 1`.
   * Otherwise, search the left half by setting `end = mid - 1`.
6. If the target is not found, return `-1`.

**Time Complexity:** O(log n)

**Space Complexity:** O(1)

*/

//CODE:

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target == nums[mid]) {
                return mid;
            }
            else if (nums[start] <= nums[mid]) {
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

        return -1;
    }
};
