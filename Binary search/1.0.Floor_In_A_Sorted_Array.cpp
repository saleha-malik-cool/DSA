/*
QUESTION:
Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] 
that is less than or equal to x. This element is called the floor of x. If such an element does not exist, 
return -1.
Note: In case of multiple occurrences of floor of x, return the index of the last occurrence.

Examples
Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1
Explanation: Largest number less than or equal to 5 is 2, whose index is 1.
*/

/*
APPROACH:

1. Apply Binary Search on the sorted array.
2. If `arr[mid] > x`, then the current element is greater than `x`, so search in the left half.
3. If `arr[mid] <= x`, then it can be a possible floor. Store its index and search in the right half for a larger
valid element.
4. Keep updating the answer when `arr[mid] >= ans`. This also handles duplicate floor values and gives the index 
of the last occurrence.
5. If no element is less than or equal to `x`, return `-1`.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

//CODE:
class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        
        int n = arr.size();
        int ans = INT_MIN;
        int idx = -1;
        int start = 0;
        int end = n - 1;

        while(start <= end) {
            
            int mid = start + (end - start) / 2;
            
            if(arr[mid] > x) {
                end = mid - 1;
            }
            else {
                if(arr[mid] >= ans) {
                    idx = mid;
                }
                
                ans = max(arr[mid], ans);
                start = mid + 1;
            }
        }
        
        return idx;
    }
};
