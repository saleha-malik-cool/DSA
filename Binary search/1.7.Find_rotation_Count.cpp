/*
QUESTION:
Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. 
Find the value of k.

Examples:

Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see 
that the array was rotated 1 times to the right.
*/

/*
APPROACH:

1. Initialize `start = 0` and `end = n - 1`.
2. Run a loop while `start < end` and calculate the middle index `mid`.
3. Compare `arr[mid]` with `arr[end]`.
4. If `arr[mid] < arr[end]`, the minimum element lies at `mid` or in the left half. Update `end = mid`.
5. Otherwise, the minimum element lies in the right half. Update `start = mid + 1`.
6. Repeat until `start == end`.
7. Return `end`, which represents the index of the minimum element and hence the number of rotations.

Time Complexity:** O(log n)

Space Complexity:** O(1)
*/

//CODE:
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int start =0;
        int end = n-1;
        while(start<end){
            int mid = start +(end - start)/2;
            if(arr[mid]< arr[end]){
                end = mid;
            }
            else{
                start= mid+1;
            }
        }
        return end;
    }
};
