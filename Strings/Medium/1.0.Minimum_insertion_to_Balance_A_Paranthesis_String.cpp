/*
QUESTION:
Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.

Example 1:

Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more
')' at the end of the string to be "(())))" which is balanced.
*/

/*
Approach (Greedy)

1. Initialize `open = 0` to count unmatched opening brackets `(` and `ans = 0` to count insertions.
2. Traverse the string character by character.
3. If the current character is `(`, increment `open`.
4. If the current character is `)` and the next character is also `)`, we have a closing pair `))`.

   * If `open > 0`, match the pair with an opening bracket and decrement `open`.
   * Otherwise, insert one `(` and increment `ans`.
   * Skip the next `)` because it is already processed as part of the pair.
5. If the current character is `)` but the next character is not `)`, insert one `)` to complete the pair.

   * If `open > 0`, decrement `open`.
   * Otherwise, insert one `(` and one additional `)` to balance the string.
6. After traversing the string, each remaining opening bracket requires two closing brackets. Add `2 * open` to `ans`.
7. Return `ans` as the minimum number of insertions.

Time Complexity:** O(n)

Space Complexity:** O(1)

*/

//CODE:
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            }
            else if (i + 1 < n && s[i + 1] == ')') {
                if (open > 0) {
                    open--;
                } else {
                    ans++;
                }
                i++;
            }
            else {
                if (open > 0) {
                    ans++;
                    open--;
                } else {
                    ans += 2;
                }
            }
        }

        ans += open * 2;
        return ans;
    }
};
