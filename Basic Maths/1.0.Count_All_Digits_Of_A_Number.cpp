/*
Question:
You are given an integer n. You need to return the number of digits in the number.
The number will have no leading zeroes, except when the number is 0 itself.

Example 1
Input: n = 4
Output: 1
Explanation: There is only 1 digit in 4.

*/

/*
APPROACH 1:
Approach

1. Initialize a variable `count = 0`.
2. Repeat until the number becomes 0:
   - Increment the count.
   - Divide the number by 10 using integer division (n = n / 10).
3. Every division by 10 removes the last digit of the number.
4. When the number becomes 0, all digits have been removed.
5. Return the count.
Special Case:
If n == 0, return 1 because 0 has one digit.

*/

//CODE:
int countDigits(int n) {
    if (n == 0)
        return 1;

    int count = 0;

    while (n > 0) {
        count++;
        n /= 10;
    }

    return count;
}
/*
Time Complexity = O(log₁₀N)
Space Complexity: O(1)
*/

/*
APPROACH 2:

1. Every d-digit number lies in the range:
   10^(d-1) ≤ Number < 10^d
2. Taking log10 on the number gives a value between (d-1) and d.
3. Taking the floor of this value gives (d-1).
4. Add 1 to get the total number of digits.
5. Handle the special case when n = 0, since log10(0) is undefined. In that case, the answer is 1.

Formula:
Digits = floor(log10(n)) + 1
*/

//CODE:
class Solution {
public:
    int countDigit(int n) {
        if(n==0){
            return 1;
        }
        int count =floor(log10(n))+1; 
        
        return count;
    }
};

/*
Time Complexity: O(1)
Space Complexity: O(1)
*/
