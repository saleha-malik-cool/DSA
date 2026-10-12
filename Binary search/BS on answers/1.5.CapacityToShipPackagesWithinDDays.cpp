/*
Question->
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

*/
/*
Examples:-
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

*/

  
//Code:-
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int n = weights.size();
       int sum=0;
       int result =0;
       for(int i =0; i<n; i++){
        sum+=weights[i];
       } 
       int start = *max_element(weights.begin(), weights.end());;
       int end = sum;
       while(start<=end){
        int mid = start+(end - start)/2;
        int ans =0;
        int k =1;
        for(int i =0; i<n; i++){
            if(ans+weights[i]>mid){
                ans = weights[i];
                k++;
            }
            else{
                ans+=weights[i];
            }
            
        }
        if(k<= days){
            result = mid;
            end = mid -1;
        }
        else{
            start = mid+1;
        }
       }
       return result;
    }
};


