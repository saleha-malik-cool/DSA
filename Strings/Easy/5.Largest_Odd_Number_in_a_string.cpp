/*
QUESTION:-
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.

Example:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
*/

/*
APPROACH:
1. Traversing through the string backwards, we check to find the first odd element.
2. To convert elements into numbers, we subtract their ASCII value from '0'.
3. Once we find an odd element, we return the substring of the string, from 0 to i i.e. i+1 elements.
4. If loop is broken without returning anything, that means the number is even. So, we return "".
*/

//CODE:
 class Solution {
public:
    string largestOddNumber(string num) {     
        for (int i = num.length()-1; i>=0; i--){
            int numi = num[i]-'0';
            if(numi%2==1){
            return num.substr(0,i+1);

            }
        }
        return "";
        
    }
};
