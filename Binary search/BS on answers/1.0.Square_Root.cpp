/*
QUESTION:
Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number.

Examples:

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
*/

/*
Approach: Floor Square Root using Binary Search**

1. Initialize `start = 0`, `end = n`, and `ans = 0`.
2. Calculate the middle element using `mid = start + (end - start) / 2`.
3. If `mid * mid == n`, return `mid` because the exact square root is found.
4. If `mid * mid > n`, search in the left half by updating `end = mid - 1`.
5. If `mid * mid < n`, store `mid` in `ans` as a possible answer and search in the right half by updating `start = mid + 1`.
6. Repeat until `start > end`, then return `ans`, which contains the floor square root.

*/

//CODE:
class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int start =0;
        int end = n;
        int ans = 0;
        while(start<=end){
            int mid = start +(end - start)/2;
            if(mid*mid==n){
                return mid;
            }
            else if(mid*mid > n){
                end = mid-1;
            }
            else{
                ans = mid;
                start = mid+1;
            }
        }
        return ans;
    }
};
