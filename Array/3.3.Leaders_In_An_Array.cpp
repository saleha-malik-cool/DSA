/*
QUESTION:
You are given an array arr of positive integers. Your task is to find all the leaders in the array. 
An element is considered a leader if it is greater than or equal to all elements to its right.
The rightmost element is always a leader.

Examples:
Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
*/

/*
APPROACH:

1. Leader woh element hai jo apne right side ke saare elements se greater ya equal hota hai.
2. Array ko right se left traverse karenge, kyunki kisi element ka leader hona uske right elements par
depend karta hai.
3. Last element hamesha leader hota hai, isliye use `ans` mein add karenge.
4. `largest` variable mein right side ka maximum element store karenge.
5. Har element ke liye:
   - Agar `arr[i] >= largest` hai, toh current element leader hai.
   - `largest` ko update karenge.
   - Current element ko `ans` mein add karenge.
6. Right se left traverse karne ki wajah se `ans` reverse order mein milega.
7. Isliye end mein `ans` ko reverse kar denge.

TC: O(n)

SC: O(n)
Output array `ans` mein leaders store karne ke liye O(n) space lag sakti hai.
*/

//CODE:
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector <int> ans;
        int i = n-2;
        int largest =arr[n-1];
        ans.push_back(arr[n-1]);
        while(i>=0){
            if(arr[i] >= largest){
                largest = arr[i];
                ans.push_back(largest);
                i--;
            }
            else{
                i--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
