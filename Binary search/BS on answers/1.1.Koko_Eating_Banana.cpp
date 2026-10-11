/*
QUESTION:

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone 
and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k 
bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more 
bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
*/

//CODE:
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int large= INT_MIN;
        int fin=0;
       for(int i =0; i<n; i++){
        if(piles[i]>large){
            large= piles[i];
        }
       }
       int start=1;
       int end= large;
       while(start<=end){
        int mid = start+(end - start)/2;
        long long ans =0;
        for(int i =0; i<n; i++){
        ans += (piles[i]+ mid - 1)/mid;
       }
       if(ans> h){
        start = mid+1;
       }
       else{
        fin = mid;
        end = mid-1;
       }
       }
       return fin;
    }
};
