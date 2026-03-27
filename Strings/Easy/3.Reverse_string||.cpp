/*
Question:-
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k 
characters, then reverse the first k characters and leave the other as original.

*/
/*
Example:-
Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
*/
/*
Approach:-
1.for loop from 0 to n in gap of 2k.
2.start =i; and end = min(i+k-1,n-1) to prevent from crossing last index.
3. Then swap inside loop.
*/
//code:-
class Solution {
public:
    string reverseStr(string s, int k) {
        int n= s.length();
        for(int i =0; i<n;i+=2*k){
            int start =i;
            int end= min(i+k-1, n-1);
            while(start<end){
                swap(s[start++],s[end--]);
            }
        }
        return s;
    }
};
