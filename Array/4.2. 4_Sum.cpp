/*
QUESTION:

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], 
nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

/*
APPROACH:

1. First, sort the given array in ascending order.
2. Run the first loop for index i from 0 to n-4.
   Fix nums[i] as the first element.
3. Skip duplicate values of i:
   If i > 0 and nums[i] == nums[i-1],
   continue.
4. Run the second loop for index j from i+1 to n-3.
   Fix nums[j] as the second element.
5. Skip duplicate values of j:
   If j > i+1 and nums[j] == nums[j-1],
   continue.
6. Initialize two pointers:
      left = j + 1
      right = n - 1
7. While left < right:
   Calculate:
      sum = nums[i] + nums[j] + nums[left] + nums[right]
   Condition 1:
      If sum == target:
         Store the quadruplet.
         Skip duplicate values of left.
         Skip duplicate values of right.
         Then:
            left++
            right--
   Condition 2:
      If sum < target:
         Increase left:
            left++
   Condition 3:
      If sum > target:
         Decrease right:
            right--
8. Repeat the process for all possible i and j.
9. Return the answer.

Time Complexity: O(n³)
Space Complexity: O(1) extra space (answer ko exclude karke).
*/

//CODE:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i =0;i<n; i++){
            if( i>0 && nums[i-1]==nums[i]){
                continue;
            }
            for(int j = i+1; j<n; j++){
                int k = j+1;
                int l= n-1;
                while(k<l){
                if(nums[i]+ nums[j]+ nums[k]+ nums[l] < target){
                    k++;
                }
                else if(nums[i]+ nums[j]+ nums[k]+ nums[l] > target){
                    l--;
                }
                else{
                    ans.push_back({nums[i] , nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1]){
                        k++;
                    }
                }
               
                
                }
                while(j>0 && nums[j] == nums[j-1]){
                    continue;
                }

            }
        }
        return ans;
        

        
    }
};
