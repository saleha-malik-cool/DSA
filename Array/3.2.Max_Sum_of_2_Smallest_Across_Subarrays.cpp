/*
QUESTION:
Given an array arr[] of integers. Find the maximum sum of the smallest and second smallest elements across all 
subarrays (of size >= 2) of the given array.

Examples :
Input: arr[] = [4, 3, 5, 1]
Output: 8
Explanation: All subarrays with at least 2 elements and find the two smallest numbers in each:
[4, 3] -> 3 + 4 = 7
[4, 3, 5] -> 3 + 4 = 7
[4, 3, 5, 1] -> 1 + 3 = 4
[3, 5] -> 3 + 5 = 8
[3, 5, 1] -> 1 + 3 = 4
[5, 1] -> 1 + 5 = 6
Maximum Score is 8.

*/

/*
Approach:

1. Array mein humein maximum sum of two consecutive elements find karna hai.
2. `i = 0` se `n-2` tak traverse karenge.
3. Har index par current element aur next element ka sum calculate karenge:
   `sum = arr[i] + arr[i+1]`
4. `ans` mein ab tak ka maximum sum store karenge:
   `ans = max(ans, sum)`
5. Loop ke end mein `ans` return kar denge.

TC: O(n)
Array ko ek baar traverse kar rahe hain.

SC: O(1)
Koi extra space use nahi ho rahi.
*/

//CODE:
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int sum=0;
        int ans =0;
        for(int i =0; i<n-1; i++){
            sum= arr[i] + arr[i+1];
            ans = max(ans,sum);
        }
        return ans;
    }
};
