/*
Question:
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array 
with at least two elements.You may return the answer in any order.

Example:
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
*/
//Code:
class Solution {
public:
    void subset(int n, vector<int>&curr, vector<vector<int>>&ans, vector<int>&nums,int i){
        if(i==n){
            if(curr.size()>=2)
            ans.push_back(curr);
            return;
        }
        if(curr.empty() || nums[i]>=curr.back()){
            curr.push_back(nums[i]);
            subset(n,curr,ans,nums,i+1);
            curr.pop_back();
        }
        if(curr.empty() || nums[i]!=curr.back()){
            subset(n,curr,ans,nums,i+1);  
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>curr;
        int n = nums.size();
        vector<vector<int>>ans;
        subset(n,curr,ans,nums,0);
        return ans;
    }
};

/*
Approach:
We use Backtracking (Take / Not Take) to generate all possible subsequences.
For every index, we have two choices:
1. Take the current element.
2. Do not take the current element.
Since the problem asks for non-decreasing subsequences, we can take an element only when it is greater than or 
equal to the last element already present in the current subsequence.
Condition:
curr.empty() || nums[i] >= curr.back()
If this condition is true, we include the current element in the subsequence and recursively process the 
remaining elements.
After returning from the recursive call, we backtrack by removing the element from the current subsequence.
To avoid duplicate subsequences, we carefully handle the "not take" branch. If the current element is equal to the
last element of the current subsequence, skipping it may generate the same subsequence again.
Therefore, we execute the "not take" branch only when:
curr.empty() || nums[i] != curr.back()
This pruning prevents duplicate subsequences from being added to the answer.
Base Case:
When we reach the end of the array (i == n), we check the size of the current subsequence. If it contains at least 
two elements, it is a valid non-decreasing subsequence, so we add it to the answer.
Why does this work?
- The Take branch explores all subsequences that contain the current element.
- The Not Take branch explores all subsequences that exclude the current element.
- The non-decreasing condition ensures only valid subsequences are formed.
- The duplicate pruning condition prevents the same subsequence from being generated multiple times.

Time Complexity: 2^n subsequences × O(n) copying cost = O(n × 2^n)
Reason:
Each element can either be included or excluded, resulting in at most 2^n recursive states and done for n times.
Space Complexity: O(n)
Reason:
The maximum depth of the recursion stack is n, and the temporary subsequence can contain at most n elements.
*/
// CODE 2 Set used
class Solution {
public:
    void solve(int index,vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr,int n){
        if(curr.size()>=2){
            ans.push_back(curr);
        }
        unordered_set<int>st;
        for(int i = index; i<n; i++){
            if((curr.empty()||curr.back()<=nums[i])&&  st.find(nums[i])== st.end()){
                st.insert(nums[i]);
                curr.push_back(nums[i]);
                solve(i+1,nums,ans,curr,n);
                curr.pop_back();
                
            }

        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>ans;
        int n = nums.size();
        solve(0,nums,ans,curr,n);
        return ans ;
    }
};

/*
Approach:
1. Use backtracking to generate all possible subsequences.
2. Maintain a vector `curr` to store the current subsequence.
3. If the size of `curr` becomes greater than or equal to 2,
   add it to the answer because it forms a valid non-decreasing subsequence.
4. At each recursion level, iterate through all elements from
   the current index to the end of the array.
5. Before choosing an element:
   - Check if `curr` is empty OR `curr.back() <= nums[i]`.
   - This ensures the subsequence remains non-decreasing.
6. Use an `unordered_set` at every recursion level to avoid
   picking the same value twice at the same level.
   This prevents duplicate subsequences.
7. Choose the current element:
   - Add it to `curr`.
   - Recursively call the function for the remaining elements (`i + 1`).
8. After returning from recursion, remove the last element
   from `curr` to explore other possibilities (backtracking).
9. Continue until all valid subsequences have been generated.
Time Complexity: O(n * 2^n)

Space Complexity: O(n)
*/
  
