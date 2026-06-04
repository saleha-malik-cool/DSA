/*
Question:
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/
//Code:-
class Solution {
public:
    void bracket(int n , vector<string>&ans, string curr,int opening , int closing){
        if(curr.length()== 2*n){
            ans.push_back(curr);
            return;
        }
        if(opening == closing){
            curr.push_back('(');
            bracket(n,ans,curr,opening+1,closing);
        }
        else if(opening==n){
            curr.push_back(')');
            bracket(n,ans,curr,opening,closing+1);
        }
        else{
            curr.push_back('(');
            bracket(n,ans,curr,opening+1,closing);
            curr.pop_back();
            curr.push_back(')');
            bracket(n,ans,curr,opening,closing+1);
        }
        return;

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        bracket(n,ans,"",0,0);
        return ans;

    }
};

/*
APPROACH:
1. We create a recursive function bracket with arguments:
   int n, vector<string>& ans, string curr,
   int opening, and int closing.
2. The string curr stores the current parenthesis combination being formed.
3. If the length of curr becomes 2*n, a valid parenthesis string has been formed.
   We push curr into ans and return
4. If opening == closing, we cannot place ')' because it would make
   the string invalid.
   Therefore, we add '(' and recursively call the function.
5. Else if opening == n, all opening brackets have already been used.
   Therefore, we add ')' and recursively call the function.
6. Otherwise, both choices are possible:
   a) Add '(' and recursively call the function.
   b) Backtrack by removing '('.
   c) Add ')' and recursively call the function.
7. This recursion explores all valid parenthesis combinations using DFS.
8. In generateParenthesis(), create an answer vector ans.
9. Call:
      bracket(n, ans, "", 0, 0);
10. Return ans containing all valid parenthesis combinations.

##DFS Traversal
The recursion always explores the left branch first ('(') and then the right branch (')').
*/

//Time Complexity : O(number of valid strings * N)
//Space Complexity : O(N) {recursion stack}

//Code:
class Solution {
public:
    void bracket(int n , vector<string>&ans, string curr,int opening , int closing){
        if(curr.length()== 2*n){
            ans.push_back(curr);
            return;
        }
        if(opening <n){
            bracket(n,ans,curr+'(',opening+1,closing);
        }
       if(closing<opening){
            bracket(n,ans,curr+')',opening,closing+1);
        }
    
        return;

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        bracket(n,ans,"",0,0);
        return ans;

    }
};
/*
APPROACH:
1. We create a recursive function bracket with arguments:
   int n, vector<string>& ans, string curr,
   int opening, and int closing.
2. The variable curr stores the current parenthesis string being formed.
3. opening stores the number of '(' used so far.
4. closing stores the number of ')' used so far.
5. If the length of curr becomes 2*n, a valid parenthesis
   combination has been formed.
   Push curr into ans and return.
6. If opening < n, we can still place an opening bracket.
   So, add '(' and recursively call the function.
7. If closing < opening, there exists at least one unmatched
   opening bracket.
   So, add ')' and recursively call the function.
8. By following these two conditions, we ensure that:
   - We never use more than n opening brackets.
   - We never place more closing brackets than opening brackets.
   Therefore, only valid parenthesis strings are generated.
9. In generateParenthesis(), create an answer vector ans.
10. Call:
       bracket(n, ans, "", 0, 0);
11. Return ans.
*/
