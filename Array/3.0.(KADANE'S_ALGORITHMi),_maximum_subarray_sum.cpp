/*
QUESTION:
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The
*/

/*
APPROACH:

1. Ek variable `sum` rakho jo current subarray ka sum maintain kare.
2. Array ko left se right traverse karo.
3. Har element ko `sum` mein add karo:
   sum += nums[i]
4. Har step par maximum sum update karo:
   maxi = max(maxi, sum)
5. Agar `sum` negative ho jaaye, toh usse discard kar do:
   sum = 0
6. Reason:
   Negative sum future ke subarray ka sum kam karega, isliye us negative sum ko carry karne ka koi benefit nahi hai.
7. Important:
   `maxi` ko negative hone se pehle reset mat karo.
   Pehle `maxi` update karo, phir `sum < 0` check karo.
   Isse all-negative arrays bhi handle ho jaate hain.

TC = O(n)
SC = O(1)
*/

//CODE:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = INT_MIN;
        long long sum = 0;
        int n = nums.size();
        for(int i =0; i<n; i++){
            sum += nums[i];

            maxi = max (sum,maxi);
            if(sum<0){
                sum = 0;
            }

        
        }

        return maxi;
    }
};
