/*
Question:
Given an array of distinct integers candidates and a target integer target, return a list of all unique 
combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 
combinations for the given input.

Example:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
*/
//Code:
class Solution {
public:
void solve(int n, int target, vector<int>&candidates, vector<int>&curr, vector<vector<int>>&ans, int i){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    if(n==i || target<0){
        return;
    }
    
    curr.push_back(candidates[i]);
    solve(n,target-candidates[i],candidates,curr,ans,i);
    curr.pop_back();
    solve(n,target,candidates,curr,ans,i+1);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        int n = candidates.size();
        solve(n,target,candidates,curr,ans,0);
        return ans;
        
    }
};
/*
Approach:
1. We use backtracking to generate all possible combinations
   whose sum is equal to the target.
2. Maintain:
   - curr   -> stores the current combination.
   - target -> remaining sum that we still need to achieve.
   - i      -> current index in the candidates array.
3. At every index, we have two choices:
   Choice 1: Take the current element
   ----------------------------------
   - Add candidates[i] to curr.
   - Reduce target by candidates[i].
   - Recur with the same index i.
   Why same index?
   Because in Combination Sum, a number can be used
   unlimited times. Therefore, after taking a number,
   we keep the index unchanged so that it can be chosen again.
4. Choice 2: Do not take the current element
   -----------------------------------------
   - Skip candidates[i].
   - Move to the next index (i + 1).
5. Base Cases:
   a) If target == 0
      - We have found a valid combination.
      - Store curr in the answer.
      - Return.
   b) If target < 0
      - The sum has exceeded the target.
      - No valid combination can be formed.
      - Return.
   c) If i == n
      - All elements have been processed.
      - Return.
6. Backtracking:
   - Before the recursive call, add the element to curr.
   - After returning, remove the element from curr.
   - This restores the previous state so that other
     combinations can be explored.
7. Continue exploring both choices recursively until
   all valid combinations are generated.
*/
//Time Complexity: Exponential (number of possible combinations)
/*
At each step, we either:
1. Take the current element
2. Skip the current element
This creates an exponential recursion tree.
*/

//Space Complexity: O(target)
/*
candidates = [1]
target = 100
100
*/
