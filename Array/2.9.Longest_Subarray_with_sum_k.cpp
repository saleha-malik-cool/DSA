/*
QUESTION:
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray
where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:
Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the 
longest subarray with a sum of 15 is 6.
*/

/*
APPROACH:

1. Prefix sum maintain karo while traversing the array.
2. Unordered map mein prefix sum ka FIRST occurrence store karo:
   mp[prefixsum] = index
3. Har index par check karo:
   prefixsum == k
   Agar true hai, toh index 0 se current index tak ka subarray ka sum k hai.
4. Ab required prefix sum calculate karo:
   prefixsum - k
5. Agar prefixsum - k map mein already present hai, toh us previous index ke baad se current index tak ka subarray 
ka sum k hoga.
6. Subarray ki length:
   i - previousIndex
7. Longest subarray ke liye:
   len = max(len, i - previousIndex)
8. Same prefix sum dobara aaye toh update mat karo.
   First occurrence hi rakho, kyunki earliest index se maximum length mil sakti hai.

TC = O(n) average
SC = O(n)
*/

//CODE:
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int prefixsum =0;
        int len =0;
        for(int i =0; i<n; i++){
            prefixsum+=arr[i];
            if(prefixsum==k){
                len = max(len,i+1);
            }
            else if(mp.find(prefixsum - k) != mp.end()){
                int index = i - mp[prefixsum - k];
                len = max(len , index);
                
            }
            
            if(mp.find(prefixsum)== mp.end()){
                mp[prefixsum] = i;
            }
            
        }
        return len;
    }
};
