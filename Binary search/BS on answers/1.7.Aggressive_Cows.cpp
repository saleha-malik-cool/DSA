/*
QUESTION:
Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct.
There are k aggressive cows.
Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

Examples:

Input: arr[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3].
The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible 
among all valid arrangements.
*/

/*
APPROACH:

1. Sort the array in ascending order.
2. Initialize `start = 1`, `end = arr[n-1] - arr[0]` and `ans = 0`.
3. Apply Binary Search to find the maximum minimum distance.
4. Calculate `mid = start + (end - start) / 2`.
5. Check whether `k` cows can be placed with at least `mid` distance using the `canplace()` function.
6. If placement is possible, update `ans = mid` and search for a larger distance by setting `start = mid + 1`.
7. Otherwise, reduce the search space by setting `end = mid - 1`.
8. In the `canplace()` function, place the first cow in the first stall and place the remaining cows whenever the distance from the last occupied stall is at least `mid`.
9. If all `k` cows can be placed, return `true`; otherwise, return `false`.
10. Finally, return `ans`.

Time Complexity:** O(n log D), where D is the difference between the maximum and minimum stall positions.

Space Complexity:** O(1) auxiliary space, excluding sorting.
*/

//CODE:
class Solution {
	public:
	int aggressiveCows(vector<int> &arr, int k) {
		// code here
		sort(arr.begin(), arr.end());
		int ans = 0;
		int n = arr.size();
		int start = 1;
		int end = arr[n - 1]- arr[0];
		while (start <= end) {
			int mid = start + (end - start)/2;
			if (canplace(arr, k, mid)) {
				ans = mid;
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		return ans ;
	}
	bool canplace(vector<int>&arr, int k, int mid) {
		int n = arr.size();
		int b = 1;
		int laststall = arr[0];
		for (int i = 1; i<n; i++) {
			if (arr[i] - laststall >= mid) {
				laststall = arr[i];
				b++;
			}}
			if (b >= k) {
				return true;
			}
			return false;
			
		}};
