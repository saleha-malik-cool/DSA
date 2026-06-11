/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number
could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map
to any letters.

Example:
Input : s = "aabaa"
Output : [ [ "a", "a", "b", "a", "a"] , [ "a", "a", "b", "aa"] , [ "a", "aba", "a"] , [ "aa", "b", "a", "a"] 
, [ "aa", "b", "aa" ] , [ "aabaa" ] ]

Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is 
a palindrome.
*/

//Code:
class Solution {
public:
    void solve (int i,vector<string>&ans,string&curr,string&digits,vector<string>&mp,int n ){
    if(i==n){
        ans.push_back(curr);
        return;
    }
    int number= digits[i] - '0';
    string&letters= mp[number];
    for(char ch : letters){
        curr.push_back(ch);
        solve(i+1,ans,curr,digits,mp,n);
        curr.pop_back();
    }}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty())
        return ans;
        string curr;
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.size();
        solve(0,ans,curr,digits,mp, n);
        return ans;


    }
};

/*
Approach:
1. Each digit on a phone keypad corresponds to a set of letters.
   2 -> abc
   3 -> def
   4 -> ghi
   5 -> jkl
   6 -> mno
   7 -> pqrs
   8 -> tuv
   9 -> wxyz
2. We need to generate all possible strings by choosing
   one letter for each digit.
3. Use backtracking.
   Maintain:
   - i     -> current digit index
   - curr  -> current string being formed
   - ans   -> stores all valid combinations
4. For the current digit:
   - Find its corresponding letters from the mapping.
   - Try every letter one by one.
5. Choose a letter:
   - Add it to curr.
   - Recur for the next digit (i + 1).
6. When all digits have been processed
   (i == digits.size()):
   - A complete combination has been formed.
   - Store curr in ans.
7. After recursion, remove the last added letter
   from curr (backtracking).
   This restores the previous state so that the next
   letter can be tried.
8. Repeat this process until all possible combinations
   are generated.
Example:
digits = "23"
2 -> abc
3 -> def
Start with ""
Choose 'a'
    Choose 'd' -> "ad"
    Choose 'e' -> "ae"
    Choose 'f' -> "af"
Choose 'b'
    Choose 'd' -> "bd"
    Choose 'e' -> "be"
    Choose 'f' -> "bf"
Choose 'c'
    Choose 'd' -> "cd"
    Choose 'e' -> "ce"
    Choose 'f' -> "cf"
Answer:
[ad, ae, af, bd, be, bf, cd, ce, cf]
Time Complexity: O(4^n × n)
Reason:
- Each digit can contribute up to 4 letters.
- Therefore, at most 4^n combinations are generated.
- Each generated string has length n and is copied into
  the answer, costing O(n).
Space Complexity: O(n)
Reason:
- Recursion depth is at most n.
- Current string stores at most n characters.
*/
