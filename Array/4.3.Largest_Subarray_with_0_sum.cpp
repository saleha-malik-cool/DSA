/*
QUESTION:
Given an array arr[] containing both positive and negative integers, the task is to find the length of the 
longest subarray with a sum equals to 0.
Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while 
maintaining their original order.

Examples:
Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].
*/

/*
APPROACH:

1. Find the prefix sum of the array.
2. Store each prefix sum with its first index in a hashmap.
3. If `sum == 0`, then the subarray from index `0` to `i` has sum `0`.
4. If the same prefix sum is found again, then the elements between the previous index and current index have sum `0`.
5. Calculate the length using:
   `i - mp[sum]`
6. Update the maximum length.
7. Store a prefix sum only when it occurs for the first time.

Time Complexity: O(n)
Space Complexity: O(n)
*/

//CODE:
class Solution {
public:
    int maxLength(vector<int>& arr) {

        unordered_map<int,int> mp;
        int longest = 0;
        int sum = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {

            sum = sum + arr[i];

            if(sum == 0) {
                longest = max(longest, i + 1);
            }

            if(mp.find(sum) != mp.end()) {
                longest = max(longest, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }

        return longest;
    }
};
