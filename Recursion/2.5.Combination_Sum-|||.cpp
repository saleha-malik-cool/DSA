/*
Question:
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice,
and the combinations may be returned in any order.

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
*/

//Code:
class Solution {
public:
    void solve(int start, int k , int n , vector<int>&curr, vector<vector<int>>&ans,int j){
        if (n==0 && j==k){
            ans.push_back(curr);
            return;
        }
        if(n<0 || j>k){
            return;
        }
        for (int i =start; i<=9; i++){
            if(j<k){
                curr.push_back(i);
                solve(i+1,k,n-i,curr,ans,j+1);
                curr.pop_back();}}
        }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
         vector<vector<int>>ans;
         int j =0;
         solve(1,k,n,curr,ans,0);
         return ans;
    }
};

/*
Approach:
1. Use backtracking to generate all possible combinations
   of numbers from 1 to 9.
2. Maintain:
   - curr  -> current combination
   - start -> next number that can be chosen
   - n     -> remaining sum required
   - j     -> number of elements chosen so far
3. At each step, try every number from start to 9.
4. Choose the current number:
   - Add it to curr.
   - Reduce the remaining sum by that number.
   - Recur with i + 1 because each number can be used
     only once.
5. If n becomes 0 and exactly k numbers have been chosen,
   a valid combination is found.
   Store curr in the answer.
6. If:
   - n becomes negative, or
   - more than k numbers are chosen,
   return because no valid combination can be formed.
7. After recursion, remove the last chosen number
   from curr (backtracking) so that other combinations
   can be explored.
8. Continue until all valid combinations are generated.
For every number from 1 to 9:

Choose it
    ↓
Reduce the remaining sum
    ↓
Move to the next number
    ↓
Backtrack and try another choice

Since each number can be used only once,
we always recurse with i + 1.
*/
//Time Complexity: C(9,k) = 9! / (k! * (9-k)!)
//Space Complexity:  O(k)
