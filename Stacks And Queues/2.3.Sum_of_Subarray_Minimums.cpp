/*
QUESTION:
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
*/

/*
BRUTE APPROACH:
1. Initialize a variable `sum` to store the sum of minimums of all subarrays.
2. Traverse the array using index `i` as the starting point of each subarray.
3. Initialize `mini = arr[i]` because a subarray containing only `arr[i]` has `arr[i]` as its minimum.
4. Extend the subarray one element at a time using index `j` from `i` to `n-1`.
5. Update the minimum element of the current subarray:
      mini = min(mini, arr[j])
6. Add the current minimum to the answer:
      sum = (sum + mini) % MOD
7. Repeat the process for every starting index.
8. Return `sum`.
*/

//CODE:
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = (1e9+7);
        int sum=0;
        int n = arr.size();
        for(int i =0; i<n; i++){
            int mini= arr[i];
            for(int j =i; j<n; j++){
                mini= min(arr[j],mini);
                sum= (sum+mini)% mod;
            } 
        }
        return sum;
    }
};
/*
Time Complexity: O(n²)
- There are O(n²) subarrays, and the minimum is updated in O(1) while extending each subarray.

Space Complexity: O(1)
- Only a few extra variables are used.
*/
