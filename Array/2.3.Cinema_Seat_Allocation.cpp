/*
QUESTION:
A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.
You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.
A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:
seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.
Return an integer denoting the maximum number of four-person groups that can be assigned.

Example 1:
Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.

*/

/*
Approach:
1. unordered_map<int, vector<int>> use karenge jisme row number ko key aur us row ki reserved seats ko vector mein store karenge.
2. Har reserved seat ke liye row aur seat nikal kar mp[row].push_back(seat) karenge.
3. Ab sirf un rows ko traverse karenge jisme reservation hai.
4. Har row ke liye 3 possible family groups maanenge:
   - Left: seats 2,3,4,5
   - Middle: seats 4,5,6,7
   - Right: seats 6,7,8,9
5. Initially left, middle aur right ko true rakhenge.
6. Row ki har reserved seat check karenge:
   - Agar seat 2 se 5 ke beech hai, left = false.
   - Agar seat 4 se 7 ke beech hai, middle = false.
   - Agar seat 6 se 9 ke beech hai, right = false.
7. Agar left aur right dono available hain, toh 2 families add karenge.
8. Otherwise agar left, middle ya right mein se koi ek available hai, toh 1 family add karenge.
9. Jin rows mein koi reservation nahi hai, unmein directly 2 families baith sakti hain.
10. mp.size() reservation wali unique rows batata hai.
11. n - mp.size() completely empty rows hain, toh unke liye (n - mp.size()) * 2 answer mein add karenge.
12. Time Complexity: O(k) average, jahan k = reservedSeats.size().
13. Space Complexity: O(k).
*/

//CODE:
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans =0;
        unordered_map <int, vector<int>> mp;
        int k = reservedSeats.size();
        for(int i =0 ; i<k; i++){
            int row = reservedSeats[i][0];
            int seats = reservedSeats[i][1];
            mp[row].push_back(seats);
        }
        for (auto it : mp){
            int row = it.first;
            vector <int> seats = it.second;
            bool left = true;
            bool middle = true;
            bool right = true;
        for(int seat : seats){
            if(seat >=2 && seat<= 5){
                left = false;
            }
            if(seat >=4 && seat <= 7){
                middle = false;
            }
            if(seat >=6 && seat <=9){
                right = false;
            }

        }
        if(left == true && right == true){
                ans+= 2;
            }
        else if(left || right || middle){
            ans+=1;
        }
    
        }
        int j = mp.size();
        int l = n-j;
        ans+= l*2;
         return ans ;
    }
   
};
