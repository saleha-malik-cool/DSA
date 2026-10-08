/*
QUESTION:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a 
given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

*/

/*
APPROACH:

1. Use Binary Search to find the first occurrence of the target.
2. When the target is found, store its index in `first` and continue searching in the left half.
3. Use Binary Search again to find the last occurrence of the target.
4. When the target is found, store its index in `last` and continue searching in the right half.
5. Return `{first, last}` as the answer.
6. If the target is not present, both values remain `-1`.

Time Complexity:** O(log n)

Space Complexity:** O(1)

*/

//CODE:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0; 
        int end = n - 1;
        int first = -1;
        int last = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(nums[mid] == target) {
                first = mid;
                end = mid-1;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        start = 0;
        end = n - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(nums[mid] == target) {
                last = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }


        return {first, last};
    }
};
