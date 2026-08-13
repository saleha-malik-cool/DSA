/*
QUESTION:
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
*/

/*
BRUTE APPROACH:
1. Use two nested loops to check all possible subarrays.
2. The first loop chooses the starting index `i`.
3. For every `i`, initialize `sum = 0`.
4. The second loop chooses the ending index `j`.
5. Add `nums[j]` to `sum`.
6. If `sum == k`, increment `count`.
7. Return `count` after checking all subarrays.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

//BRUTE CODE:
lass Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
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
1. Use Prefix Sum + HashMap.
2. Maintain `sum` as the current prefix sum.
3. Add `nums[i]` to `sum` at every index.
4. Calculate `val = sum - k`.
5. If `sum == k`, increment `count`.
6. Check if `val` exists in the HashMap.
7. If it exists, add its frequency to `count`.
8. Store the current `sum` in the HashMap and increase its frequency.
9. Return `count`.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

//CODE:
lass Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum =0;
         unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
           sum+=nums[i];
           int val= sum - k;
           if(sum== k){
            count++;
           }
           if(mp.find(val) != mp.end()){
            count+= mp[val];
           }
           if(mp.find(sum) == mp.end()){
            mp[sum] = 1;
           }
           else{
            mp[sum]++;
           }

        }
       
        return count;
    }
};
