/*
QUESTION:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

/*
APPROACH:
1. Store all elements in an unordered_map for O(1) average lookup.
2. Traverse through all unique elements of the map.
3. For every element, check if num-1 exists.
4. If num-1 does not exist, then num is the starting element of a consecutive sequence.
5. Start checking num+1, num+2, num+3... and keep increasing count.
6. Update the maximum answer using ans = max(ans, count).
7. This ensures every consecutive sequence is traversed only from its starting point.
8. Time Complexity: O(n) average.
9. Space Complexity: O(n).
*/

//CODE:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]] = true;
        }
        int ans =0;
        for(auto it: mp){
            int num = it.first;
            if(mp.find(num-1) == mp.end()){
                int curr = num ;
                int count =1;
                while(mp.find(curr + 1) != mp.end()){
                    count++;
                    curr++;
                }
                ans = max(ans,count);

            }

           
        }
         return ans;

    }
};
