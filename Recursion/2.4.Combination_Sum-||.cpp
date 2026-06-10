/*
Question:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
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
    for(int j = i; j<n; j++){
        if(j>i && candidates[j]==candidates[j-1])
        continue;
        if(candidates[j]>target){
            break;
        }

    curr.push_back(candidates[j]);
    solve(n,target-candidates[j],candidates,curr,ans,j+1);
    curr.pop_back();
         } }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        vector<vector<int>>ans;
        int n = candidates.size();
        solve(n,target,candidates,curr,ans,0);
        return ans;
        
    }
};
/*
Approach:
1. First sort the array.
   Why sort?
   * Duplicate elements become adjacent.
   * It becomes easy to skip duplicates.
   * We can stop early when an element becomes greater than the remaining target.
2. Use backtracking to build combinations.
   Maintain
   * curr   -> current combination
   * target -> remaining sum needed
   * i      -> starting index for the current recursion level
3. At each recursion level, try every element from index i onwards.
   for(int j = i; j < n; j++)
   Here, j represents the element we are choosing next.
4. Skip duplicates.
   if(j > i && candidates[j] == candidates[j-1])
   continue;
   This means:
   * At the same recursion level, if we have already considered a value,
     do not consider the same value again.
   * This prevents duplicate combinations.
5. Choose the current element.
   curr.push_back(candidates[j])
   Reduce the target:
   target = target - candidates[j]
6. Move to the next index.
   solve(j + 1, target - candidates[j])
   Why j + 1 ?
   Because each element can be used only once.
   After choosing an element, we cannot choose the same index again.
7. Backtrack.
   curr.pop_back();
   Remove the last chosen element so that other combinations
   can be explored.
8. Base Case
   If target == 0:
   * A valid combination is found.
   * Store curr in the answer.
9. Optimization
   Since the array is sorted:
   if(candidates[j] > target)
   break;
   If the current element is already greater than target,
   all further elements will also be greater.
   Therefore, no valid combination can be formed.
   At every level:
Choose one number
↓
Go forward only
↓
Never come back to previous indices
↓
Skip duplicate numbers at the same level
↓
Backtrack and try the next choice
*/
//Time Complexity: O(2^n)
//Space Complexity: O(n)

//Code for while:
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
    solve(n,target-candidates[i],candidates,curr,ans,i+1);
    curr.pop_back();
    int j =i+1;
    while(j<n && candidates[j-1]== candidates[j]){
        j++;
    }
    solve(n,target,candidates,curr,ans,j);
    
          }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        vector<vector<int>>ans;
        int n = candidates.size();
        solve(n,target,candidates,curr,ans,0);
        return ans;
        
    }
};

//Here the while loop is used only in the not-take branch to skip all duplicate values.
/*
Summary Table
Take/Not-Take + While          	                For-Loop Backtracking
Two recursive calls	One                         recursive call inside loop
Explicit Take branch           	                Choose current loop element
Explicit Not-Take branch                       	Not-Take handled by loop progression
Duplicates skipped using while    	             Duplicates skipped using continue
Easier to understand recursion                   tree	More compact and commonly used
*/
