//You are given an integer array bloomDay, an integer m and an integer k.

//You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

//The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

//Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

//Approach
//1.find min and max for start and end 
//2.two loop for mid and for max element if k andar if lagake couynt badao agar day max se chota h to and if bouquet 0 krdo 

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<(long long) m*k){
            return -1;
        }

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end=*max_element(bloomDay.begin(), bloomDay.end());
        while(start<=end){
            int mid = start+(end - start)/2;
            int count = 0;
            int bouquet = 0;
            for(int i =0; i<n; i++){
                if (bloomDay[i]<=mid){
                    count++;
                    if(count==k){
                        bouquet++;
                        count=0;
                    }
                
                    }
                
                else{
                    count=0;
                }}
            if(bouquet>=m){
                end = mid-1;
            }
            else{
                start =mid+1;
            }
        }
        return start;
    }
};
