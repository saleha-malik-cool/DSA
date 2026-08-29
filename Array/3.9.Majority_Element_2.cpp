/*
QUESTION:
Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]
*/

/*
Approach:

We use the Extended Boyer-Moore Voting Algorithm to find all elements that appear more than n/3 times.

1. There can be at most 2 elements whose frequency is greater than n/3, so we maintain two candidates.

2. In the first pass, we find these two possible candidates:
   - If the current number is candidate1, increase count1.
   - Else if it is candidate2, increase count2.
   - Else if count1 is 0, make it candidate1.
   - Else if count2 is 0, make it candidate2.
   - Otherwise, decrease both count1 and count2.

3. The counts in the first pass are voting counts, not the actual frequencies.

4. Therefore, in the second pass, we count the actual frequency of both candidates.

5. Finally, if a candidate occurs more than n/3 times, we add it to the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

//COclass Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();
        int candidate1 =0;
        int count1 = 0;
        int candidate2 =0;
        int count2 =0;
        for(int num : nums){
            if(num == candidate1){
                count1++;
            }
            else if(num == candidate2){
                count2++;
            }
            
            else if(count1 ==0){
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 ==0){
                candidate2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int num : nums){
            if(num == candidate1){
                count1++;
            }
            else if(num == candidate2){
                count2++;
            }
        }
        if(count1 > nums.size()/3){
            ans.push_back(candidate1);
        }
        if(count2 > nums.size()/3){
            ans.push_back(candidate2);
        }
        return ans;
    }
};DE:
