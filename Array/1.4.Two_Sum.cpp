/*
QUESTION:
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add
up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + n
*/

/*
APPROACH:
1. Use a HashMap to store each number and its index.
2. Traverse the array from left to right.
3. For every element, calculate `val = target - nums[i]`.
4. Check if `val` already exists in the HashMap.
5. If it exists, return the index of `val` and the current index `i`.
6. If it does not exist, store `nums[i]` with its index in the HashMap.
7. Continue until a valid pair is found.
8. Return an empty vector if no pair exists.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

//CODE:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i =0; i<n; i++){
            int val = target - nums[i];
            if(mp.find(val) != mp.end()){
                return{mp[val] , i};
            }
            mp[nums[i]] = i;
        }
        return{};
    }
};
