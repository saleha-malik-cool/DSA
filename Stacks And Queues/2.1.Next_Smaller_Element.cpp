/*
QUESTION:-
Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.
The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
If there is no smaller element to the right, then the NSE is -1.

Example:

Input: arr = [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
Explanation:
- For 4, the next smaller element is 2.
- For 8, the next smaller element is 5.
- For 5, the next smaller element is 2.
- For 2, there is no smaller element to its right → -1.
- For 25, no smaller element exists → -1.
*/

/*
Approach:
1. Create an answer array of size n and initialize all values with -1.
2. Use a stack to store the indices of elements whose next smaller element has not been found yet.
3. Traverse the array from left to right.
4. For each current element:
   - While the stack is not empty and the current element is smaller than the element at the index on the top of the stack:
     - The current element is the next smaller element for that index.
     - Store it in the answer array.
     - Pop the index from the stack.
5. Push the current index into the stack.
6. After the traversal, the indices left in the stack do not have any smaller element on their right, so their answer remains -1.
7. Return the answer array.
*/
//CODE:
class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        // Your code goes here
        vector<int> ans(n , -1);
        stack <int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[i]<arr[s.top()]){
               ans[s.top()] = arr[i];
               s.pop();            }

            
            s.push(i);
        }
        while(!s.empty()){
            ans[s.top()]=-1;
            s.pop();
        }
        
       return ans;
    }
};
/*
Time Complexity: O(n)
- Each index is pushed and popped from the stack at most once.

Space Complexity: O(n)
- O(n) for the stack and O(n) for the answer array.
*/
