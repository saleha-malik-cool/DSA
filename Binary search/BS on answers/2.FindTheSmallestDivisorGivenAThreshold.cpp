/*
QUESTION:-
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer.

Example:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
*/

/*
APPROACH:
1. We apply binary search from 1 to the maximum element in the array {because that will be the minimum we divide all elements with, and will result in the number of elements in the array}.
2. For all elements in the array, we do ceil division with mid, and add it to count.
3. If count is less than or equal to threshold, that means that it can be the answer or something lower can be. So, we save it in ans, and check the left part of the array.
4. Else, we check the right part of the array.
5. Return ans.
*/

//CODE:
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start= 1;
        int end =*max_element(nums.begin(),nums.end());
        while(start<=end){
            int mid = start +(end - start)/2;
            int sum =0;
            
            for (int i =0; i<nums.size(); i++){
                int ans = (nums[i]+mid-1)/mid;
                sum+=ans;
            }

            if(sum<=threshold){
                end= mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start ;
    }
};
