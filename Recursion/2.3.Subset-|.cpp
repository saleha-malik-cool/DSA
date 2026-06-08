/*
Question:
Given an array nums of n integers. Return array of sum of all subsets of the array nums.
Output can be returned in any order.

Example:
Input : nums = [2, 3]
Output : [0, 2, 3, 5]
Explanation :
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then sum = 2+3 = 5
*/
//CodE:
class Solution {
  public:
  void solve(int n, vector<int>&nums, vector<int>&ans,int i,int sum){
    if(i==n){
        ans.push_back(sum);
        return;
    }
    solve(n,nums,ans,i+1,sum+nums[i]);
    solve(n,nums,ans,i+1,sum);

  }
    vector<int> subsetSums(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        solve(n,nums,ans,0,0);
        return ans;
        
    }
};

/*
Approach:
1. Use recursion to generate all possible subsets.
2. Maintain:
   - i   -> current index
   - sum -> sum of the current subset
3. At every index, we have two choices:
   - Include nums[i] in the subset.
   - Exclude nums[i] from the subset.
4. For the include case:
   - Add nums[i] to sum.
   - Recur for the next index.
5. For the exclude case:
   - Keep sum unchanged.
   - Recur for the next index.
6. When i reaches n:
   - A complete subset has been formed.
   - Store its sum in the answer vector.
7. After exploring all possibilities, return the answer vector.
Time Complexity: O(2^n)
Space Complexity: O(n)
*/
