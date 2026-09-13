/*
QUESTION:
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/

/*
APPROACH:

Use Binary Search because the array is sorted.
1. Initialize start = 0 and end = n-1.
2. Find the middle element.
3. If nums[mid] == target, return mid.
4. If target < nums[mid], search in the left half.
5. If target > nums[mid], search in the right half.
6. If target is not found, start will point to the correct insertion position.
7. Return start.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

//CODE:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n =nums.size();
        int start = 0; 
        int end = n-1;
        int phla=-1;
        int baad = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }

        }
        return start;
    }
};
