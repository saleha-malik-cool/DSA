/*
QUESTION:
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
*/

/*
APPROACH:

We use Prefix Sum + Unordered Map.

1. Calculate the prefix sum while traversing the array.
2. For every current prefix sum, calculate:
   value = prefixsum - k
3. If this value exists in the map, then there are previous prefix sums which can form a subarray with sum k.
4. Add the frequency of value to count.
5. If prefixsum == k, increment count because the subarray from index 0 to current index has sum k.
6. Store the current prefixsum in the map with its frequency.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

//CODE:
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int prefixsum =0;
        int count =0;
        for(int i =0; i<n; i++){
            prefixsum+=nums[i];
            int value = prefixsum - k;
            if(prefixsum == k){
                count++;
            }
            else if(mp.find(value) != mp.end()){
                count+=mp[value];
            }
            if(mp.find(prefixsum) == mp.end()){
                mp[prefixsum] = 1;
            }
            else if(mp.find(prefixsum) != mp.end()){
                mp[prefixsum]++;
            }
        }
        return count;
    }
};
