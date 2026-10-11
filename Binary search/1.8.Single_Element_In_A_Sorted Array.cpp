/*
QUESTION:
You are given a sorted array consisting of only integers where every element appears exactly twice, except for
one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

//CODE;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start =0; 
        int end = n-1;
        while(start<=end){
            int mid = start +(end - start)/2;
            if (mid%2==1){
                mid--;
            }
            if(mid<n-1 && nums[mid]==nums[mid+1]){
                start= mid+2;
            }
            else{
                end = mid-2;
            }
        }
            return nums[start];
    }
};
