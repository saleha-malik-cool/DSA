/*
QUESTION:
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1
*/

/*
BRUTE APPROACH:
Approach:

1. Create an unordered_map to store the frequency of each number.
2. Traverse the complete array.
3. For every element, increase its frequency using:
   mp[nums[i]]++;
4. Traverse the hashmap using for(auto it : mp).
5. Check the frequency of each element using it.second.
6. If it.second == 1, then that element occurs only once.
7. Store that element (it.first) as the answer.
8. Return the answer.

Example:

nums = [4,1,2,1,2]

Frequency:
4 → 1
1 → 2
2 → 2

Only 4 has frequency 1.
Therefore answer = 4.

Time Complexity = O(n)
Space Complexity = O(n)
*/

//BRUTE CODE:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i =0;i<n; i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second==1){
                ans = it.first;
            }
        }
        return ans;
    }
};


/*
OPTIMAL APPROACH:
1. Initialize ans = 0.
2. Traverse the complete array.
3. XOR every element with ans:
   ans = ans ^ nums[i]
4. XOR has an important property:
   a ^ a = 0
   a ^ 0 = a
5. Since every number appears twice except one number, all duplicate numbers cancel each other.
6. The only number left after XORing all elements is the single number.
7. Return ans.

Example:

nums = [4,1,2,1,2]

ans = 0

0 ^ 4 = 4
4 ^ 1 = 5
5 ^ 2 = 7
7 ^ 1 = 6
6 ^ 2 = 4

Answer = 4

Because:

4 ^ 1 ^ 2 ^ 1 ^ 2
= 4 ^ (1 ^ 1) ^ (2 ^ 2)
= 4 ^ 0 ^ 0
= 4

Time Complexity = O(n)
Space Complexity = O(1)
*/

//OPTIMAL CODE:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =nums.size();
        int ans=0;
        for(int i =0; i<n; i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
