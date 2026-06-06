/*
Quwstion:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example;
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

*/

//Code;
class Solution {
public:
    void subset(int n , vector<int>&curr, vector<int>&nums, vector<vector<int>>&ans, int i){
        if (i==n){
           ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        subset(n,curr,nums,ans,i+1);
        curr.pop_back();
        int index= i+1;
        while(index<n && nums[index-1]== nums[index]){
            index++;
           }
         subset(n,curr,nums,ans,index);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>curr;
        vector<vector<int>>ans;
        int n = nums.size();
        subset(n,curr,nums,ans,0);
        return ans;
        
    }
};

/*
Approach:
This is the same Include/Exclude backtracking approach used in the Power Set problem.
The only difference is that the array may contain duplicates, so we must avoid generating duplicate subsets.
Step 1:
Sort the array first.
Example:
[2,1,2] -> [1,2,2]
Sorting places duplicate elements together, making them easy to skip.
Step 2:
At every index, we have two choices:
1. Take nums[i]
2. Don't Take nums[i]
Take Branch:
Add nums[i] to the current subset and move to the next index.
Don't Take Branch:
If we decide not to take nums[i], we should also skip all of its duplicates.
Otherwise, duplicate subsets will be generated.
Example:
nums = [1,2,2]
At the first 2:
Take 2:
[1,2]
Don't Take 2:
We must skip all remaining 2's and jump directly to the next different element.
That's why we use:
int index = i + 1;
while(index < n && nums[index] == nums[i])
    index++;
}
subset(..., index);
Why not subset(..., i)?
Because it would call recursion on the same index again and cause infinite recursion.
Why not subset(..., index + 1)?
Because index already points to the first different element.
Using index + 1 would skip that element too.
Base Case:
When i == n, all elements have been processed.
Store the current subset in the answer.

*/

//Time Complexity:O(n × 2^n) 
/*
We generate up to 2^n subsets using backtracking, and each subset may take up to O(n) time to copy into the answer, 
giving O(n×2^)time complexity
*/

/*
Space Complexity: O(n)
Reason:
The maximum depth of the recursion stack is n, and the current subset can contain at most n elements at any point in
time. Therefore, the auxiliary space used by the algorithm is O(n).
Auxiliary Space Complexity: O(n)
The recursion stack and current subset together require at most O(n) extra space.
Output Space: O(n × 2^n)
Since all possible subsets are stored in the answer vector, the output itself requires O(n × 2^n) space.
*/
