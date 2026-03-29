/*
QUESTION:-
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.

Example:

Input: s = "abcde", goal = "cdeab"
Output: true
*/

//BRUTE-FORCE CODE:

/*
APPROACH:
1. In this approach, we check for all possible rotations of the string and compare it with goal.
2. If length of both strings are unequal, return false.
3. To check for all rotations, we iterate through the length of the string, and initialise a new string which 
stores the concatenation of the substring from i to the end of s, and substring from 0, and of length i.
4. This concatenation creates all possible rotations of the string.
5. If any of it is equal to goal, return true.
6. Else, return false.
*/
//code:-
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length()!= goal.length()){
            return false;
        }
        for(int i =0; i<s.length(); i++){
            string check= s.substr(i)+ s.substr(0, i);
            if(check == goal)
            return true;
        }
        return false;
        
    }
};
//Time Complexity : O(N^2)
//Space Complexity : O(N)
/*
APPROACH:
 1. We know that all kinds of rotations of s will exist as a substring of the string, 's + s'.
 2. Using this, we create a new string, which stores the value of s+s.
 3. First, we check if the length of both strings are unequal. If yes, return false.
 4. Return the result of whether we can find goal in the ans string.
 5. strig::npos is a constant means not found.
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string ans = s + s;
        return ans.find(goal) != string::npos;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)
