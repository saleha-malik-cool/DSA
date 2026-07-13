/*
QUESTION:
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i]
is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for
which this is possible, keep answer[i] == 0 instead.
Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/

/*
APPROACH:
1. Create an answer array of size n and initialize it with 0.
2. Create a stack to store indices of temperatures.
3. Traverse the temperature array from right to left.
4. For each index i:
   - While the stack is not empty and the temperature at the top index of the stack is less than or equal to the current temperature:
       Pop the stack.
     (These temperatures can never be the next warmer day for the current element.)
5. If the stack is not empty:
   - The top of the stack is the next warmer day.
   - Store the number of days as:
       ans[i] = stack.top() - i
6. Push the current index into the stack.
7. After processing all elements, return the answer array.

*/

//CODE:
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> ans(n,0);
        stack <int> s;
        for(int i =n-1; i>=0; i--){
            while(!s.empty() && temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]= s.top()-i;
            }
            s.push(i);
        }
        return ans ;
    }
};

/*
Time Complexity
O(n) — Every index is pushed once and popped at most once.
Space Complexity
O(n) — Stack stores indices.
*/
