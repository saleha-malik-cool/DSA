/*
QUESTION:
Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j)
where 0 <= i < j < n and nums[i] + nums[j] < target.

Example 1:
Input: nums = [-1,1,2,3,1], target = 2
Output: 3
Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
- (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target 
- (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the target.
*/

/*
BRUTE APPROACH:
Approach:
1. Use two nested loops to check every possible pair.
2. Fix the first element using index `i`.
3. Start the second element from `i + 1` using index `j`.
4. Check if `nums[i] + nums[j] < target`.
5. If the condition is true, increment `count`.
6. Since `j` starts from `i + 1`, we never use the same element twice.
7. It also ensures that every pair is counted only once.
8. Return `count`.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

//BRUTE CODE:
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int count =0;
        for(int i =0; i<n; i++){
            for(int j =i+1; j<n; j++){
                if((nums[i] + nums[j]) < target ){
                    count++;
                }
            }
        }
        return count;
    }
};

/*
OPTIMAL APPROACH:
Approach:
1. Sort the array in increasing order.
2. Use two pointers: `i = 0` and `j = n - 1`.
3. Check if `nums[i] + nums[j] < target`.
4. If the sum is less than target, then all elements between `i + 1` and `j` will also form a valid pair with 
`nums[i]` because the array is sorted.
5. Therefore, add `j - i` to `count`.
6. Move `i` one step forward.
7. If the sum is greater than or equal to target, move `j` one step backward.
8. Continue until `i >= j`.
9. Return `count`.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

//OPTIMAL CODE:
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j =n-1;
        int i =0;
        int count=0;
        while(i<j){
            if(nums[i]+nums[j] <target){
                count+=j-i;
                 i++;}
            else{
                    j--;
                }
        
        } 
        return count;  
    }
};
