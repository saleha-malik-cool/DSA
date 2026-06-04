/*
Question:
Given an integer n, return all binary strings of length n that do not contain consecutive 1s. 
Return the result in lexicographically increasing order.

Example:
Input: n = 3
Output: ["000", "001", "010", "100", "101"]
Explanation: All strings are of length 3 and do not contain consecutive 1s.
*/
//Code:
class Solution {
public:
    void solve(int n , string curr, vector<string>& ans){
        int len = curr.length();
        if(len==n){
            ans.push_back(curr);
            return;
        }
       if(len==0){
        curr.push_back('0');
        solve(n,curr,ans);
        curr.pop_back();
        curr.push_back('1');
        solve(n,curr,ans);
       }
       else if(curr[len-1]=='1'){
        curr.push_back('0');
        solve(n,curr,ans);
       }
       else{
        curr.push_back('0');
        solve(n,curr,ans);
        curr.pop_back();
        curr.push_back('1');
        solve(n,curr,ans);
       }
       return;
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string>ans;
        solve( n, "",  ans);
        return ans;
        

    }
};
class Solution {
public:
    void solve(int n , string curr, vector<string>& ans){
        int len = curr.length();
        if(len==n){
            ans.push_back(curr);
            return;
        }
       if(len==0){
        curr.push_back('0');
        solve(n,curr,ans);
        curr.pop_back();
        curr.push_back('1');
        solve(n,curr,ans);
       }
       else if(curr[len-1]=='1'){
        curr.push_back('0');
        solve(n,curr,ans);
       }
       else{
        curr.push_back('0');
        solve(n,curr,ans);
        curr.pop_back();
        curr.push_back('1');
        solve(n,curr,ans);
       }
       return;
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string>ans;
        solve( n, "",  ans);
        return ans;
        

    }
};
/*
Approach:
1. Start with an empty string curr.
2. At every recursive call, check the current length of the string.
3. If curr.length() == n, then a valid binary string of length n is formed. Store it in the answer vector and return.
4. If the current string is empty, both '0' and '1' can be placed because there is no previous character.
5. If the last character is '1', then only '0' can be appended. Appending another '1' would create consecutive 1s ("11"), which is not allowed.
6. If the last character is '0', then both '0' and '1' can be appended because neither choice violates the condition.
7. Use backtracking (push_back() and pop_back()) to explore all valid possibilities and then undo the choice before trying the next one.
8. Since '0' is explored before '1', the generated strings automatically appear in lexicographical order.

Dry Run (n = 3)
             ""
           /    \
         0        1
       /  \        \
     00   01       10
    / \    |      /  \
 000 001 010   100 101

 Time Complexity:O(Number of Valid Strings × N)
 Reason:
Every valid string is generated once.
When a valid string is found, it is copied into the answer vector, which takes O(N) time.

Space Complexity;O(N)
Reason:
Maximum recursion depth is N.
Extra space is used only by the recursion stack (excluding the answer vector).

1. Choice lo
2. Recursive call karo
3. Choice undo karo (pop_back)
4. Next choice try karo
*/
