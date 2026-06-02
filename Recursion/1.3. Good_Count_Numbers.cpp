/*
Question:
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
*/
/*
Example:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
*/
//Code:
class Solution {
public:
    long long power(long long x, long long n){
        long long mod = 1000000007;
        x= x%mod;
        if(n==0){
            return 1;
        }
        if(n%2==0){
            return power((x*x)%mod,n/2);
        }
        else{
            return (x*power(x*x%mod,(n-1)/2))%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd=n/2;
        long long evenways = power(5,even);
        long long oddways = power(4,odd);
        return (evenways* oddways)% 1000000007;

        
    }
};

/*
APPROACH:
1. In this, we create a new function with two arguments : n and index {to track which index we are at in the number}.
2. If index == n, that means we exceeded the digit string. Return 1.
3. If index is even, then for each of the even digits i.e. 5 times, we add count(n, index+1) to the ans. This creates one number at a time and adds 1 to answer. Hence, by recursion, we create all numbers one by one, and add 1 to ans.
4. If index is odd, then for each of the prime digits i.e. 4 times, we add count(n, index+1) to the ans.
5. Return ans % cont.
6. Now in the original function, return count(n, 0).
*/

class Solution {
public:
    int count(long long n, int index) {
        int ans = 0;
        if(index == n) return 1;

        if(index % 2 == 0) {
            for(int digit : {0, 2, 4, 6, 8}) {
                ans = ans + count(n, index + 1);
            }
        }
        else {
            for(int digit : {2, 3, 5, 7}) {
                ans = ans + count(n, index + 1);
            }
        }
        return ans % 1000000007;
    }

    int countGoodNumbers(long long n) {
        return count(n, 0);
    }
};

//Time Complexity : [exponential] {due to recursion}
//Space Complexity : O(N) {linear recursion stack}

//{In this approach, recursion tree grows so exponentially that it exceeds time limit even at small values of n.}
