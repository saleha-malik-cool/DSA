/*
QUESTION:
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks,
return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater
than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 i
*/

/*
APPROACH:
### Approach: Binary Search (Peak Element)

1. Initialize `start = 0` and `end = n - 1`, where `n` is the size of the array.
2. Find the middle index using `mid = start + (end - start) / 2`.
3. Compare `nums[mid]` with `nums[mid + 1]`:
   - If `nums[mid] < nums[mid + 1]`, move to the right half by setting `start = mid + 1`.
   - Otherwise, move to the left half, including `mid`, by setting `end = mid`.
4. Repeat until `start == end`.
5. Return `start`, which is the index of a peak element.

Time Complexity:** O(log n)

Space Complexity:** O(1)

*/

//CODE:
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start =0; 
        int end = n-1;
        int ans =-1;
         while(start< end){
            int mid = start+(end - start)/2;
            
                if(nums[mid+1]>nums[mid]){
                    start = mid +1 ;
                }
            
                else{
                    end = mid;
                }
         } 
         return start;
    }
};
