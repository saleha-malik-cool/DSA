/*
QUESTION:-
Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.
Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.

Example:

Input: nums = [12, 34, 67, 90], m=2
Output: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.
*/

/*
APPROACH:
1. We first initialise a function, which checks if mid is a possible answer for the book allocation.
2. We initialise a student count and initiate it from 1, because there will be a min. of 1 student. We initialise pagesum to check the sum of pages to be less than mid.
3. Traversing through the array, we check if adding nums[i] to pagesum will be less than or equal to mid. If yes, we add nums[i] to pagesum.
4. Else, we reinitialise pagesum from nums[i] and do student++. If the student count becomes more than m, we return false.
5. If the loop is broken without any return, we return true.
6. In our main function, we check if the number of elements in our array {i.e. the number of total books} is less than the number of students. If so, we return -1.
7. We apply binary search from the max element in the array {because thats the minimum number of pages we need, so that we can assign it to a student} to the sum of all pages in the array.
8. If mid is a possible solution, we save it in ans, and check for a smaller mid.
9. Else, we check for a greater mid {i.e. the right part}.
10. Return ans.
*/

//CODE:
class Solution {
public:
    bool if_possible(vector<int>&arr, int mid, int m){
        int student = 1;
        int sum=0;
        for(int i =0; i<arr.size(); i++){
            
            if(sum + arr[i]<=mid){
                sum+=arr[i];

            }
            else{
                sum = arr[i];
                student++;
                if(student>m){
                    return false;
                }
            }
        }
        return true;

    }
    int findPages(vector<int> &nums, int m)  {
        int ans =-1;
        int start = *max_element(nums.begin(), nums.end());
        int end =0;
        for(auto i: nums){
            end+=i;
        }
        while(start<=end){
            int mid = start+(end -start)/2;
            if (if_possible(nums,mid, m)){
                ans = mid;
                end = mid -1;
            }
            else{
                start=mid+1;
            }
        }

       return ans; 
    }
};
