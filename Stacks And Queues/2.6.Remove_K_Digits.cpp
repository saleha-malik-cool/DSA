/*
QUESTION:
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer
after removing k digits from num.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/

/*
APPROACH:
1. Create an empty string and use it as a stack.
2. Traverse each digit of the given number from left to right.
3. For every current digit:
   - While the stack is not empty,
   - k > 0,
   - and the last digit in the stack is greater than the current digit,
     remove the last digit from the stack and decrement k.
4. Push the current digit into the stack.
5. After processing all digits, if k is still greater than 0, remove the last k digits from the stack.
6. Remove all leading zeros from the resulting string.
7. If the string becomes empty, return "0".
8. Otherwise, return the final string.
*/

//CODE:
class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int n = num.size();
        for(char ch :num){
            while(!st.empty() && k>0 && ch < st.back() ){
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }
        while(!st.empty() && k>0){
           st.pop_back();
           k--;
        }
        int i =0;
        while(i< st.size() && st[i]=='0'){
            i++;
        }
        st = st.substr(i);
        if(st.empty()){
            return "0";
        }
        return st;
    }
};
/*
Time Complexity
O(n)
Each digit is pushed once and popped at most once.
Space Complexity
O(n)
The string (used as a stack) stores at most n digits.

Trick to Remember:
If the previous digit is bigger than the current digit, remove the previous digit first. This greedy choice always 
makes the resulting number as small as possible.
*/
