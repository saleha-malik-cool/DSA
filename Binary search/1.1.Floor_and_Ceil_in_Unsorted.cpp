/*
QUESTION:

Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].
Floor of x is the largest element which is smaller than or equal to x. Floor of x doesn’t exist if x is smaller than
smallest element of arr[].
Ceil of x is the smallest element which is greater than or equal to x. Ceil of x doesn’t exist if x is greater than 
greatest element of arr[].
Return an array of integers denoting the [floor, ceil]. Return -1 for floor or ceiling if the floor or ceiling is 
not present.

Examples:
Input: x = 7 , arr[] = [5, 6, 8, 9, 6, 5, 5, 6]
Output: 6, 8
Explanation: Floor of 7 is 6 and ceil of 7 is 8.
*/

/*
APPROACH:

1. First, sort the array.
2. Initialize:
   f = -1  → floor
   c = -1  → ceil
   start = 0
   end = n - 1
3. Apply Binary Search.
4. If arr[mid] == x:
   Floor = x and Ceil = x.
   Break the loop.
5. If arr[mid] < x:
   arr[mid] can be the floor.
   Store it in f.
   Move right using start = mid + 1 to find a larger floor.
6. If arr[mid] > x:
   arr[mid] can be the ceil.
   Store it in c.
   Move left using end = mid - 1 to find a smaller ceil.
7. Return {f, c}.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

//CODE:
class Solution {
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int f = -1;
        int c = -1;

        int start = 0;
        int end = n - 1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(arr[mid] == x) {
                f = x;
                c = x;
                break;
            }

            else if(arr[mid] < x) {
                f = arr[mid];
                start = mid + 1;
            }

            else {
                c = arr[mid];
                end = mid - 1;
            }
        }

        return {f, c};
    }
};
