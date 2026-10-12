/*
QUESTION:

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

*/

//CODE;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int large= INT_MIN;
        int ans =-1;
        for(int i =0; i<n; i++){
            large = max(bloomDay[i],large);
        }
        int start =0;
        int end = large;
        while(start<=end){
            int count=0;
            int b=0;
            int mid = start + (end - start)/2;
            for(int i =0; i<n; i++){
                if(bloomDay[i]<=mid ){
                    count++;
                    if(count==k){
                        b++;
                        count=0;
                    }
                    
                }
                else{
                       count=0;
                    }
            }
            if(b>=m){
                ans = mid;
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
