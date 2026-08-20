/*
QUESTION:
You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks 
of the same difficulty level.
Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

Example 1:
Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
*/

/*
APPROACH:

1. Sabse pehle unordered_map use karke har task ki frequency count karenge.
2. Har unique task ke liye uski frequency check karenge.
3. Agar kisi task ki frequency 1 hai, toh us task ko 2 ya 3 ke group mein complete nahi kar sakte, isliye -1 return karenge.
4. Ab frequency ko 3 se divide karke cases handle karenge:
   - Agar freq % 3 == 0 hai, toh saare tasks ke groups of 3 bana denge.
   - Agar freq % 3 == 2 hai, toh freq/3 groups of 3 aur 1 group of 2 bana denge.
   - Agar freq % 3 == 1 hai, toh ek group of 3 ko todkar 2 groups of 2 banayenge.
5. `freq % 3 == 1` ke case mein:
   - `(freq / 3) - 1` groups of 3 banenge.
   - `2` groups of 2 banenge.
6. Har task ke liye required rounds ko `count` mein add karenge.
7. Finally `count` return karenge.
8. Time Complexity: O(n) average.
9. Space Complexity: O(n).
*/

//CODE:
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        int count=0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            int freq = it.second;
            if(freq<2){
                return -1;
            }
            int num = freq %3;
            if(num== 0){
                count+= freq/3;
            }
            else if(num== 2){
                count+= freq/3;
                count+= 1;
            }
            else{
                count+= freq/3 - 1;
                count+=2;
            }
            
        }
        return count;
        
    }
};
