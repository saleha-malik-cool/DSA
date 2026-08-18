/*
QUESTION:
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that
is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since 
it does not appear in nums.
*/

/*
APPROACH 1:

1. Sort the array.
2. Let n = nums.size().
3. Initially assume the missing number is nums[n-1] + 1.
4. If nums[0] != 0, then 0 is missing.
5. Traverse from right to left:
   - If nums[i] != nums[i-1] + 1, then nums[i-1] + 1 is missing.
   - Break after finding it.
6. Return ans.

TC: O(n log n) because of sorting.
SC: O(1) auxiliary space (excluding the sorting implementation).
*/

//CODE 1;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         int n = nums.size();
         int ans = nums[n-1] + 1;
         if(nums[0] != 0){
                ans = 0;
            }
         for(int i =n-1; i>0; i--){
            if (nums[i]!= nums[i-1] + 1){
               ans = nums[i-1] + 1;
               break;
            }
            
         }
         return ans;
        
    }
};


/*
APPROACH 2:

1. Find the size of the array and store it in n.
2. Calculate the sum of numbers from 0 to n using:
   total = n * (n + 1) / 2
3. Calculate the sum of all elements present in the array.
4. Subtract the array sum from the total sum.
5. The result will be the missing number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

//CODE 2:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int total = n * (n + 1) / 2;
        int sum = 0;

        for(int num : nums) {
            sum += num;
        }

        return total - sum;
    }
};

/*
APPROACH 3:

1. Let n = nums.size().
2. The numbers should be from 0 to n.
3. XOR all numbers from 0 to n and all elements of the array.
4. Every number that exists in both will cancel because:
   x ^ x = 0
5. Only the missing number will remain.
6. Return the remaining value.

Time Complexity: O(n)
Space Complexity: O(1)
*/

//CODE 3:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;

        for(int i = 0; i < n; i++) {
            ans = ans ^ i ^ nums[i];
        }

        return ans;
    }
};
