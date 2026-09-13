/*
QUESTION:
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/

/*
APPROACH:

Use Binary Search because the array is sorted.
1. Initialize start = 0 and end = n-1.
2. Find the middle element.
3. If nums[mid] == target, return mid.
4. If target < nums[mid], search in the left half.
5. If target > nums[mid], search in the right half.
6. If target is not found, start will point to the correct insertion position.
7. Return start.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

//CODE:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n =nums.size();
        int start = 0; 
        int end = n-1;
        int phla=-1;
        int baad = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }

        }
        return start;
    }
};

/*
Bad Version:
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest
version of your product fails the quality check. Since each version is developed based on the previous version,
all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the
following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to
find the first bad version. You should minimize the number of calls to the API.

Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
*/

//CODE:
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start=0;
        int end =n;
        while(start<=end){
            int mid = start+(end - start)/2;
            if(isBadVersion(mid)){
                end=mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return
    }
};
