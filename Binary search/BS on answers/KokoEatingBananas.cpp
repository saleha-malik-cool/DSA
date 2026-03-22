// use ceiling function by applying binary search on max element 

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end =0;
        for(auto i:piles){
             end=max(i,end);
        }
        while(start<=end){
            int mid = start+(end-start)/2;
            long long count=0;
            for(auto i : piles){
                count+=(i+mid-1)/mid;
            }
            if(count<=h){
                end = mid-1;
            }
           
            else{
                start = mid+1;
            }
        }
        return start;
    }
};
