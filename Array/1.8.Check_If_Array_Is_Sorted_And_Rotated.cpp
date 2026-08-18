/*
QUESTION:
Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.
length] for every valid index i.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
*/

/*
Brute Approach:

1. First, make a copy of the original array.
2. Sort the copied array so that we get the sorted version of nums.
3. Try every possible rotation of the sorted array.
4. For each rotation:
   - Reverse the first part.
   - Reverse the second part.
   - Reverse the complete array.
5. After creating the rotation, compare it with the original nums.
6. If both arrays become equal, return true.
7. If no rotation matches after checking all possibilities, return false.

Example:
nums = [3,4,5,1,2]

Sorted array:
[1,2,3,4,5]

Possible rotations:
[2,3,4,5,1]
[3,4,5,1,2]  ← matches nums

Therefore, return true.

Time Complexity:
- Sorting = O(n log n)
- We try n rotations.
- Each rotation + comparison takes O(n).
- Therefore, total = O(n² + n log n)
- Dominant term = O(n²)

Space Complexity:
- O(n) for the temporary vector.

TC = O(n²)
SC = O(n)
*/

//BRUTE CODE:
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            vector<int> temp = nums;
            sort(temp.begin(), temp.end());
            reverse(temp.begin() + 0,temp.begin() + i+1);
            reverse(temp.begin() + i+1, temp.end());
            reverse(temp.begin(), temp.end());
            if(temp == nums){
                return true;
            }
        }
        return false;
        
    }
};

