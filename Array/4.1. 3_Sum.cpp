/*
QUESTION:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and
j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

/*
APPROACH:

1. First, sort the given array in ascending order.
2. Run a loop for index i from 0 to n-3.
   Fix nums[i] as the first element of the triplet.
3. If i > 0 and nums[i] == nums[i-1],
   skip this iteration because it will create a duplicate triplet.
4. Initialize two pointers:
      left = i + 1
      right = n - 1
5. While left < right:
   Calculate:
      sum = nums[i] + nums[left] + nums[right]
   Condition 1:
      If sum == 0:
         Store {nums[i], nums[left], nums[right]} in the answer.
         Skip duplicate values of left.
         Skip duplicate values of right.
         Then move both pointers:
            left++
            right++
   Condition 2:
      If sum < 0:
         Increase left because the array is sorted.
         left++
   Condition 3:
      If sum > 0:
         Decrease right because the array is sorted.
         right--
6. Repeat the process for every i.
7. Return the answer.


Time Complexity: O(n²)
Space Complexity: O(1) extra space.
*/

//CODE:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // duplicate j skip
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // duplicate k skip
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }

                else if (sum < 0) {
                    j++;
                }

                else {
                    k--;
                }
            }
        }

        return ans;
    }
};
