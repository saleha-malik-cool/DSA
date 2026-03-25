/*
QUESTION:-
Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

Example:

Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]
Output: 3
Explanation:
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.
In no manner can we increase the minimum distance beyond 3.
*/

/*
1. First, we make a function to check, when is it that we can call "mid" is a possible solution to place cows.
2. We place one cow at 0th index position, and save that at the [lastpos].
3. Traversing through the array, we check if [nums[i] - lastpos] {i.e. the distance between the last cow and the new cow} is greater than or equal to mid.
4. If yes, we save that position as [lastpos] and do cows++. Else, we continue.
5. If cows reach k before the loop breaking, we return true {i.e. mid is a possible solution}.
6. Else, we return false.
7. In our main function, using binary search from 1 {since that's the min distance between two cows} to the difference between the first and last stall {i.e. the max distance}.
8. We check if mid is a possible solution. If yes, we save it in ans, and move to the higher mids because we need the maximum possible ans.
9. Else, we check the left side of the array.
10. Return ans.
*/

//CODE:
class Solution {
public:

    bool isPossible(vector<int> &nums, int k, int mid) {
        int lastpos = nums[0];
        int cows = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - lastpos >= mid) {
                lastpos = nums[i];
                cows++;
            }
            if(cows == k) {
                return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 1;
        int end = nums[nums.size() - 1] - nums[0];
        int ans = -1;

        while(start <= end) {
            int mid = start  + (end - start)/2;

            if(isPossible(nums, k, mid)) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

//Time Complexity : O(NlogN + Nlog(maxdistance))
//Space Complexity : O(1)
