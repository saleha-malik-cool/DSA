/*
QUESTION:-
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
Example:
Input: s = "([])"
Output: true
Input: s = "([)]"
Output: false
*/

/*
APPROACH:
1. Create an empty stack to store the opening brackets.
2. Traverse the given string character by character.
3. If the current character is an opening bracket ('(', '{', '['), push it onto the stack.
4. If the current character is a closing bracket (')', '}', ']'):
   - If the stack is empty, return false because there is no matching opening bracket.
   - Otherwise, compare the current closing bracket with the top element of the stack.
   - If they form a matching pair, pop the top element from the stack.
   - Otherwise, return false because the brackets are not balanced.
5. After traversing the entire string, check whether the stack is empty.
   - If the stack is empty, all brackets have been matched, so return true.
   - Otherwise, return false because some opening brackets remain unmatched.
*/
//CODE:
class Solution {
    stack <char> st;
public:
    bool isValid(string s) {
        int n = s.length();
        for(int i = 0; i<n; i++){
            if(s[i]== '(' || s[i]== '{' ||s[i]== '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(s[i]==')' && st.top()=='('){
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{'){
                st.pop();
                }
                else if(s[i]==']' && st.top()=='['){
                    st.pop();
                }
                else{
                return false;}
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
        }};

//Time Complexity: O(n), where n is the length of the string. Each character is pushed and popped at most once.
//Space Complexity: O(n) in the worst case, when all characters are opening brackets and are stored in the stack

