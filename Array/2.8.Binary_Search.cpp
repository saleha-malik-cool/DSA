/*
QUESTION;
Given an array arr[], sorted in ascending order and an integer k. Return true if k is present in the array,
otherwise, false.

Examples:
Input: arr[] = [1, 2, 3, 4, 6], k = 6
Output: true
Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is true.
*/

//CODE:
class Solution {
  public:
    bool binarySearch(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int start = 0;
        int end = n-1;
        for(int i =0; i<n; i++){
            int mid= start + (end - start)/2;
            if(arr[mid] == k){
                return true;
            }
            else if(arr[mid] < k){
                start = mid+1;
                
            }
            else{
                end = mid-1;
            }
            
        }
        return false;
    }
};
