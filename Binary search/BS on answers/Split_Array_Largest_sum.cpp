/*
QUESTION:-
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.

Example:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/

/*
APPROACH:
1. We first initialise a function, which checks if mid is a possible answer for the minimised largest sum of subarrays.
2. We initialise count from 1, because there will be a min. of 1 subarray. We initialise sum to check the sum of array elements to be less than mid.
3. Traversing through the array, we check if adding nums[i] to sum will be less than or equal to mid. If yes, we add nums[i] to sum.
4. Else, we reinitialise sum from nums[i] and do count++. If count becomes more than k, we return false.
5. If the loop is broken without any return, we return true.
6. In our main function, we check if the number of elements in our array is less than the number of subarrays. If so, we return -1.
7. We apply binary search from the max element in the array {because thats the minimum sum we need, so that we can assign it to any subarrays} to the sum of all elements in the array.
8. If mid is a possible solution, we save it in ans, and check for a smaller mid.
9. Else, we check for a greater mid {i.e. the right part}.
10. Return ans.
*/
//code:-

class Solution {
public:
bool if_possible(vector<int>&arr, int mid,int k){
    int count=1;
    int sum=0;
    for(int i =0; i<arr.size(); i++){
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else{
            count++;
            sum=arr[i];
            if(count>k){
                return false;
            }
        }
    }
    return true;
}

   int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(),nums.end());
         int end = 0;
         int ans =-1;
         for(auto i: nums){
            end+=i;
         }
         while(start<=end){
            int mid= start+(end - start)/2;
            if(if_possible(nums,mid,k)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
         }
        return ans;
    }
};
