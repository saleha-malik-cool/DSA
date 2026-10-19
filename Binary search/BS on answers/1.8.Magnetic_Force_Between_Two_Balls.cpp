/*
QUESTION:

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they 
are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has 
m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any 
two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

Example 1:

Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
*/

//CODE:

 class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        int ans =0;
        sort(position.begin(), position.end());
        int start = 1;
        int end = position[n-1]- position[0];
        while(start<=end){
            int mid = start+(end - start)/2;
            if(canplace(position,m,mid)){
                ans = mid;
                start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        return ans ;
    }
    bool canplace(vector<int>& position, int m, int mid){
        int ball = 1;
        int n = position.size();
        int place = position[0];
        for(int i =1; i<n; i++){
            if(position[i] - place >= mid){
                place = position[i];
                ball++;
            }
        }
        if(ball>=m){
            return true;
        }
        return false;
    }
};
