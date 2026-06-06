/*
Question:
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example;
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

//Code:
class Solution {
public:
void power(vector<int>&nums,int n,vector<int>&curr,vector<vector<int>>&ans,int i){
    if(i==n){
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[i]);
    power(nums,n,curr,ans,i+1);

    curr.pop_back();
 
    power(nums,n,curr,ans,i+1);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>curr;
        power(nums,n,curr,ans,0);
        return ans;

        
    }
};

/*
Approach:
We use Backtracking (Include/Exclude technique) to generate all possible subsets.
For every element, we have two choices:
1. Include the current element in the subset.
2. Exclude the current element from the subset.
We recursively explore both possibilities. When we reach the end of the array (index == n), the current subset represents one valid subset, so we add it to the answer.
Steps:
1. Start with an empty subset and index 0.
2. Include the current element and recurse for the next index.
3. Backtrack by removing the element from the current subset.
4. Exclude the current element and recurse for the next index.
5. When index becomes n, store the current subset in the answer.

                    []
                 /      \
               [1]       []
              /  \      /  \
          [1,2] [1]   [2]  []
           / \   / \   / \  / \
      [1,2,3] ...     ...   ...

*/
//Time Complexity : O(N * 2^N) {2^N subsets with possibly N elements in all}
//Space Complexity : O(N) {recursion stack}
