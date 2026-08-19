/*
QUESTION:
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero 
elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

/*
APPROACH:
1. i points to the position where the next non-zero element should go.
2. j traverses the complete array.
3. If nums[j] is non-zero:
   - Swap nums[i] and nums[j].
   - Increment i.
4. Zeroes automatically move towards the end.
5. Return nothing because the function is void.

TC: O(n)
SC: O(1)
*/

//CODE:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i =0; 
        for(int j =0; j<n; j++){
            if(nums[j] !=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        
    }
};
