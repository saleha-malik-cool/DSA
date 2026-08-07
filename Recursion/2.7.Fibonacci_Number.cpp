/*
QUESTION:
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number 
is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
*/

/*
APPROACH:
1. Fibonacci series follows a simple recurrence relation:
   fib(n) = fib(n-1) + fib(n-2)
2. Handle the base cases first:
   - If n == 0, return 0.
   - If n == 1, return 1.
3. For any n > 1:
   - Recursively calculate fib(n-1).
   - Recursively calculate fib(n-2).
   - Return the sum of both values.
4. The recursion keeps breaking the problem into smaller subproblems until it reaches the base cases (0 or 1).
5. Once the base cases return their values, the recursive calls combine the results while returning back up the call
stack to produce the final Fibonacci number.
*/

//CODE:
class Solution {
public:
    int fib(int n) {
        int ans =0;
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if (n>1){
         ans = fib(n-1) + fib(n-2);
        }
        return ans;

    }
};

/*
Time Complexity : O(2^n)
Space Complexity: O(n)
*/
