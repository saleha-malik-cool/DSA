/*
QUESTION:
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive
1s is 3.
*/

/*
Approach:

1. Array ko left se right traverse karenge.
2. `count` variable consecutive 1s ko count karega.
3. Agar `nums[i] == 1` hai:
   - `count++`
   - `ans = max(ans, count)`
4. Agar `nums[i] == 0` hai:
   - Consecutive sequence break ho gayi.
   - `count = 0` kar denge.
5. End mein `ans` maximum consecutive 1s return karega.

TC: O(n)
Array ko ek baar traverse kar rahe hain.

SC: O(1)
Koi extra space use nahi ki.
*/

//CODE:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int count =0;
        int ans =0;
        for(int i =0; i<n; i++){
            if(nums[i] == 1){
                count++;
                ans = max(count,ans);

            }
            else{
            count=0;}
        }
        return ans;
    }
};
