/*
QUESTION:
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any
order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

/*
APPROACH:

1. Permutation banane ke liye backtracking use karenge.
2. `ind` batayega ki current position par kaunsa element fix karna hai.
3. Har position ke liye `ind` se `n-1` tak ek-ek element ko current position par laayenge using swap.
4. Swap karne ke baad recursively next position ke liye call karenge:
   `per(nums, ind + 1, ans)`
5. Jab `ind == n` ho jaaye, iska matlab poori permutation ready hai.
   Is permutation ko `ans` mein store kar denge.
6. Recursive call ke baad swap ko undo karenge.
   Ye backtracking hai:
   `swap(nums[ind], nums[i])`
7. Is process se saari possible permutations generate ho jaayengi.

Example: [1,2,3]

ind = 0:
→ 1 ko first position par rakho
→ 2 ko first position par rakho
→ 3 ko first position par rakho

Har choice ke baad next index ke liye same process repeat hoga.

TC: O(n × n!)
SC: O(n) auxiliary space
Output space: O(n × n!)
*/

//CODE:
class Solution {
public:
    void per (vector <int> &nums , int ind , vector<vector <int>> & ans ){
        int n = nums.size();
        if (ind == n ){
            ans.push_back(nums);
            return;
        }
        for(int i = ind ; i<n; i++){
            swap(nums[ind], nums[i]);
            per(nums,ind+1,ans);
            swap(nums[ind],nums[i]);}
    
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        per(nums,0,ans);
        return ans;

        
    }
};
