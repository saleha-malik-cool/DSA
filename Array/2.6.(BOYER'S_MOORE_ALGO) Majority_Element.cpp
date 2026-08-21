/*
QUESTION:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element 
always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
*/

/*
APPROACH 1:

1. Sabse pehle array ko sort karenge, jisse same elements ek saath aa jayenge.
2. `count` variable se current element ki frequency count karenge.
3. Agar `nums[i+1] == nums[i]` hai, toh `count++` karenge.
4. Agar dono elements different hain, toh `count = 1` se reset karenge.
5. Jab `count > n/2` ho jayega, toh `nums[i]` majority element hai, isliye `ans = nums[i]` karenge.
6. Agar array mein sirf ek element hai, toh wahi majority element hoga, isliye directly `nums[0]` return karenge.
7. Finally `ans` return karenge.

Time Complexity:
O(n log n)
Sorting ki wajah se O(n log n) lagta hai, aur array traversal O(n) hai.

Space Complexity:
O(1) auxiliary space
Humne koi extra data structure use nahi kiya.
*/

//CODE:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans =0;
        int count =1;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i =0; i<n-1; i++){
            if(nums[i+1] == nums[i]){
                count++;
                if(count >n/2){
                    ans = nums[i];
                }
            }
            else{
                count =1;
            }
            
        }
        return ans;
    }
};


/*
APPROACH 2:

1. `unordered_map<int, int>` banayenge jisme har element ki frequency store karenge.
2. Array ko traverse karke `mp[nums[i]]++` se har element ka count increase karenge.
3. Ab map ko traverse karenge aur har element ki frequency check karenge.
4. Agar kisi element ki frequency `n/2` se greater hai, toh wahi majority element hai.
5. Us element ko `ans` mein store karenge.
6. Finally `ans` return karenge.

Time Complexity:
O(n) average
- Array traverse karke frequency count karna → O(n)
- Map traverse karna → O(n) average

Space Complexity:
O(n)
- Worst case mein saare elements different ho sakte hain, isliye unordered_map mein O(n) elements store honge.
*/

//CODE 2:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans =0;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            int freq = it.second;
            if(freq > n/2){
                ans = it.first;
            }
        }
        return ans;
        
    }
};

/*
APPROACH 3:

1. Majority element woh element hai jo array mein n/2 se zyada baar present hota hai.
2. Is problem ko solve karne ke liye Boyer-Moore Voting Algorithm use karenge.
3. Do variables lenge:
   - ans → current candidate majority element
   - freq → candidate ke current votes/count
4. Initially freq = 0 rakhenge.
5. Array ko traverse karenge.
6. Agar freq == 0 hai, toh current element ko naya candidate bana denge:
   ans = nums[i]
7. Agar current element candidate ke equal hai, toh freq++ karenge.
8. Agar current element candidate se different hai, toh freq-- karenge.
9. Different elements majority candidate ko cancel karte hain.
10. Kyunki majority element n/2 se zyada baar aata hai, cancellation ke baad bhi wahi candidate bachta hai.
11. Finally ans return karenge.

Algorithm:
Boyer-Moore Voting Algorithm

Time Complexity: O(n)
Space Complexity: O(1)

*/

//CODE 3:
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
         int freq=0;
        for(int i =0; i<n; i++){
            if(freq==0){
                ans = nums[i] ;
            }
            if(nums[i] == ans){
                freq++;
            }
            else{
                freq--;
            }
            

        }
        return ans;
    }
};
