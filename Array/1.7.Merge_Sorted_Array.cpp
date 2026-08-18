/*
QUESTION:
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be
merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/

/*
APPROACH:
1. Both nums1 and nums2 are sorted.
2. nums1 already has n extra empty spaces at the end.
3. So merge from right to left to avoid overwriting elements.
4. Take three pointers:
   i = m - 1  → last valid element of nums1
   j = n - 1  → last element of nums2
   k = m + n - 1  → last position of nums1
5. Compare nums1[i] and nums2[j].
6. Put the larger element at nums1[k].
7. Decrease the pointer of the array from which the element was taken.
8. Decrease k after every insertion.
9. Continue until j < 0.
10. Remaining elements of nums1 are already in their correct positions.

Example:
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]

3 vs 6 → 6
3 vs 5 → 5
3 vs 2 → 3
2 vs 2 → 2
2 vs 2 → 2
1 remains

Final = [1,2,2,3,5,6]

TC = O(m+n)
SC = O(1)

Main trick:
Merge from the BACK and place the LARGEST element first.
*/

//CODE:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {

            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
    }
};
