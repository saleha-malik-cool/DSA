/*
Question:-
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
*/
/*
Example:-
Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

*/
/*
Approach:-
1.First make start variable as 0th element
2.Make end variable assigning to last element
3.While start<end loop and then swap the start and end and start++ and end--.
*/
//code:-
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start =0; 
        int n = s.size();
        int end = n-1;
        while(start<end){
            swap(s[start++],s[end--]);
        }
        
    }
};
//Time Complexity:-O(N)
//Space Complexity:-O(1)
