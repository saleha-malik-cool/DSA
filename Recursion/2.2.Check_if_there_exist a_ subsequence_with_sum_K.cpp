/*
Question:
Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements
in subsequences is equal to k else false.

Example:
Input : nums = [1, 2, 3, 4, 5] , k = 8
Output : Yes
Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.
*/
//Code:
class Solution{
    public:
   void solve(int k , int sum, vector<int>&nums,int i, bool&exist){
        if (exist)return;
        if(sum==k){
            exist=true;
            return;
        }
        if (i == nums.size())
            return;

         
         solve(k,sum+nums[i],nums,i+1,exist);
         solve(k,sum,nums,i+1,exist);
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        bool exist= false;
         solve(k,0,nums,0,exist);
         return exist;
         
    }
};

/*
Approach:
1. Use recursion and backtracking to generate all possible subsequences.
2. Maintain:
   - i    -> current index
   - sum  -> sum of the current subsequence
   - exist -> stores whether a valid subsequence has been found
3. At every index, we have two choices:
   - Include nums[i] in the subsequence.
   - Exclude nums[i] from the subsequence.
4. If sum becomes equal to k:
   - Set exist = true.
   - Return immediately.
5. If a valid subsequence has already been found
   (exist == true), stop further recursion.
6. When i reaches nums.size(), return because all
   elements have been processed.
7. After exploring all possibilities, return the
   value of exist.
Time Complexity: O(2^n)

Space Complexity: O(n)
*/
