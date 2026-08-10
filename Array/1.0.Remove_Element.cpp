/*
QUESTION:
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the
elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the
following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:
The judge will test your solution with the following code:
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.
int k = removeElement(nums, val); // Calls your implementation
assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

/*
APPROACH — TWO POINTER
1. We need to remove all elements equal to val from the array.
2. We should modify the array in-place, so we do not use an extra array.
3. Use two pointers:
   - i → traverses through the entire array.
   - j → points to the position where the next valid element should be placed.
4. Initially:
   j = 0
5. Traverse the array using i.
6. For every element, check:
   if(nums[i] != val)
7. If nums[i] is not equal to val, it is a valid element.
   Place it at index j:
   nums[j] = nums[i];
   Then increment j:
   j++;
8. If nums[i] == val, simply skip that element.
   In this case, j does not increase.
9. After the loop, j represents the new length of the array.

Example:
nums = [0,1,2,2,3,0,4,2]
val = 2
i = 0 → 0 is valid → nums[0] = 0 → j = 1
i = 1 → 1 is valid → nums[1] = 1 → j = 2
i = 2 → 2 == val → skip
i = 3 → 2 == val → skip
i = 4 → 3 is valid → nums[2] = 3 → j = 3
i = 5 → 0 is valid → nums[3] = 0 → j = 4
i = 6 → 4 is valid → nums[4] = 4 → j = 5
i = 7 → 2 == val → skip
Final valid part:
[0,1,3,0,4]
New length = 5
KEY IDEA:

i → READ / CHECK
j → WRITE / PLACE

i checks every element,
while j places only the valid elements at the beginning of the array.
*/

//CODE:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j =0;
        for(int i =0; i<n; i++){
            if(nums[i]!= val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
