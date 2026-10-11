/*
QUESTION:

You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

Examples :

Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8
*/

//CODE:
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int start=0;
        int end = m;
        while(start<=end){
            int mid= start +(end -start)/2;
            if(pow(mid,n)==m){
                return mid;
            }
            else if(pow(mid,n)>m){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
};
