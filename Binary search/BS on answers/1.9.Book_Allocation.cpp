/*
QUESTION:

Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book.
You also have an integer k representing the number of students. The task is to allocate books to each student 
such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
All books must be allocated.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum. If it is not possible to allocate books to all students, return -1;

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
*/

/*
Approach:

If k > n, return -1 because every student must get at least one book.
Initialize start as the maximum element of the array and end as the sum of all elements.
Apply binary search on the range [start, end].
Calculate mid and check whether the books can be allocated to at most k students without exceeding mid pages per student.
If allocation is possible, store mid as the answer and search the left half to minimize the maximum pages.
Otherwise, search the right half by increasing start.
Return the minimum possible maximum number of pages.

Time Complexity: O(n log(sum of pages))

Space Complexity: O(1)
*/

//CODE:
class Solution {
	public:
	int findPages(vector<int> &arr, int k) {
		// code here
		int n = arr.size();
		if (k>n) {
			return - 1;
		}
		long long start = 0;
		long long end = 0;
		long long ans = 0;
		for (int i = 0; i<n; i++) {
			start = max(start, (long long)arr[i]);
			end += arr[i];
		}
		while (start <= end) {
			long long mid = start + (end - start)/2;
			if (canplace(arr, k, mid)) {
				ans = mid;
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		return ans;
	}
	
	bool canplace(vector<int> &arr, int k, long long mid) {
		int n = arr.size();
		long long page = 0;
		long long st = 1;
		for (int i = 0; i<n; i++) {
			
			if (page + arr[i]>mid) {
				page = arr[i];
				st++;
			}
			else {
				page += arr[i];
			}
		}
		if (st <= k) {
			return true;
		}
		return false;
	}
};
