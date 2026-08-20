/*
QUESTION:
You are given a 1-indexed array of distinct integers nums of length n.
You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. 
In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:
If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].
Return the array result.

Example 1:
Input: nums = [2,1,3]
Output: [2,3,1]
Explanation: After the first 2 operations, arr1 = [2] and arr2 = [1].
In the 3rd operation, as the last element of arr1 is greater than the last element of arr2 (2 > 1), append nums[3] to arr1.
After 3 operations, arr1 = [2,3] and arr2 = [1].
Hence, the array result formed by concatenation is [2,3,1].
*/

/*
APPROACH:
1. Do empty vectors arr1 aur arr2 banayenge.
2. nums[0] ko arr1 mein aur nums[1] ko arr2 mein add karenge.
3. Ab index 2 se nums ko traverse karenge.
4. Har element ke liye arr1 aur arr2 ke last elements compare karenge.
5. Agar arr1 ka last element arr2 ke last element se greater hai, toh current element ko arr1 mein add karenge.
6. Otherwise current element ko arr2 mein add karenge.
7. Traversal complete hone ke baad pehle arr1 ke saare elements aur phir arr2 ke saare elements ans mein add karenge.
8. Finally ans return karenge.
9. Time Complexity: O(n)
10. Space Complexity: O(n)
*/

//CODE:
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int n = nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        for(int i = 2; i<n; i++){
            int k= arr1.size();
            int j = arr2.size();
            if(arr1[k-1]>arr2[j-1]){
                arr1.push_back(nums[i]);
            }
            else{
               arr2.push_back(nums[i]);
            }

        }
        vector <int> ans ;
        
        for(int i =0; i<arr1.size(); i++){
            ans.push_back(arr1[i]);

        }
        for(int i = 0 ; i < arr2.size(); i++){
            ans.push_back(arr2[i]);
        }
        return ans;

        

        
    }
};
