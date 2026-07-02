/*
QUESTION:-
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
Example:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/

/*
APPROACH:
1. We use a stack and an unordered_map to solve the problem efficiently.
   - The stack stores the elements of nums2 whose Next Greater Element (NGE) has not been found yet.
   - The unordered_map stores the mapping: Element → Next Greater Element.
2. Traverse nums2 from left to right.
   - While the stack is not empty and the current element is greater than the top of the stack, the current element
   is the Next Greater Element of the stack's top.
   - Store this mapping in the unordered_map and pop the top element from the stack.
   - Push the current element onto the stack.
3. After traversing nums2, the elements left in the stack do not have any greater element on their right. Store 
their Next Greater Element as -1 in the unordered_map.
4. Traverse nums1. For each element, retrieve its Next Greater Element from the unordered_map and add it to the
answer vector.
5. Return the answer vector.
*/

//CODE:
class Solution {
    
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> s;
        vector <int> ans;
        unordered_map<int, int> mpp;
        for(int num : nums2){
            while(!s.empty() && num > s.top()){
                mpp[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        while(!s.empty()){
            mpp[s.top()] = -1;
            s.pop();
        }
        for(int num : nums1){
            ans.push_back(mpp[num]);
        }
         return ans;
        
    }
};

/*
#Time Complexity
O(n + m)
n = nums2.size()
m = nums1.size()
#Space Complexity
O(n) for the stack and the unordered map.
*/
