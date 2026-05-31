/*
QUESTION:-
Implement pow(x, n), which calculates x raised to the power n (i.e. x^n).

Example:
Input: x = 2.00000, n = -2
Output: 0.25000
*/
//Code:
class Solution {
public:
    double power(double x, long long n) {
        if (n == 0)
            return 1;

        if (n % 2 == 0)
            return power(x * x, n / 2);

        return power(x * x, (n - 1) / 2) * x;
    }

    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }
};

/*
Approach:
1. The problem is to calculate xⁿ efficiently.
2. A simple solution multiplies x by itself n times, which takes O(n) time.
3. To improve efficiency, we use Exponentiation by Squaring.
4. If n is even:
   xⁿ = (x²)ⁿᐟ²
   So we square x and divide n by 2.
5. If n is odd:
   xⁿ = (x²)⁽ⁿ⁻¹⁾ᐟ² × x
   So we square x, reduce the exponent, and multiply by one extra x.
6. We continue this process recursively until n becomes 0.
7. Since the exponent is divided by 2 at every recursive call, the time complexity becomes O(log n).
Why Use a Helper Function?
The original function signature provided by LeetCode is:
double myPow(double x, int n)
The parameter n is of type int.
For negative exponents, we need to convert n into a positive value. However, there is a special case:
n = -2147483648 (INT_MIN)
Its positive value is:
2147483648
which cannot be stored in an int.
Therefore, we create a helper function:
double power(double x, long long n)
The helper function uses long long so that very large positive values can be handled safely without overflow.
Why Use long long?
An int can store values only from:
-2147483648 to 2147483647
When n = -2147483648:
-n = 2147483648
This value is larger than the maximum int value and causes overflow.
To avoid this problem, we convert n to long long:
long long N = n;
Now N can safely store 2147483648.
Handling Negative Powers
For negative exponents:
x⁻ⁿ = 1 / xⁿ
Steps:
1. Convert n to long long.
2. If n is negative:
   * Replace x with 1/x.
   * Make n positive.
3. Call the helper function power(x, n).
Base Case
If n == 0:
x⁰ = 1
So return 1*/
/*Complexity Analysis
Time Complexity: O(log n)
Reason:
At every recursive call, n is divided by 2.
Space Complexity: O(log n)
Reason:
The recursive call stack stores approximately log₂(n) function calls*/

