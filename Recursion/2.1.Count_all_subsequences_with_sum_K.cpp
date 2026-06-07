/*
Question:
Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all 
elements in the subsequence is equal to k.

Example:
Input : nums = [4, 9, 2, 5, 1] , k = 10
Output : 2
Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].
*/
//Code:
class Solution{
    public:
    int count=0;
    void solve (int k ,  vector<int>&nums, int sum, int i) {
        if (i==nums.size()){
            if (sum==k){
                count++;
            }
             return;
        }
        solve(k,nums,sum+nums[i],i+1);
        solve(k,nums,sum,i+1);

    }   	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
       
        solve(k,nums,0,0);
        return count;
    	
    }
};

/*
Approach:
1. Use recursion to generate all possible subsequences.
2. Maintain:
   - i    -> current index
   - sum  -> sum of the current subsequence
3. At every index, we have two choices:
   - Include nums[i] in the subsequence.
   - Exclude nums[i] from the subsequence.
4. For the include case:
   - Add nums[i] to sum.
   - Recur for the next index.
5. For the exclude case:
   - Keep sum unchanged.
   - Recur for the next index.
6. When i reaches nums.size():
   - If sum == k, increment the count.
   - Return to the previous recursive call.
7. After exploring both choices for every element,
   the count variable stores the total number of
   subsequences whose sum is equal to k.

At each index:

            nums[i]
           /       \
      Include     Exclude
         /            \
     i+1,sum+     i+1,sum

Time Complexity: O(2^n), because for each element we have two choices (include or exclude),
generating all possible subsequences.
Space Complexity: O(n), due to the recursion stack depth.
*/
