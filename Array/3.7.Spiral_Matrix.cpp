/*
QUESTION:
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

/*
APPROACH:

1. Spiral traversal ke liye 4 boundaries maintain karenge:
   - `top` → first row
   - `bottom` → last row
   - `left` → first column
   - `right` → last column

2. Jab tak `top <= bottom` aur `left <= right` hai, traversal continue karenge.

3. Sabse pehle `top` row ko left se right traverse karenge.
   Uske baad `top++` karenge.

4. Phir `right` column ko top se bottom traverse karenge.
   Uske baad `right--` karenge.

5. Phir check karenge `top <= bottom`.
   Agar row bachi hai, toh `bottom` row ko right se left traverse karenge.
   Uske baad `bottom--` karenge.

6. Phir check karenge `left <= right`.
   Agar column bacha hai, toh `left` column ko bottom se top traverse karenge.
   Uske baad `left++` karenge.

7. Ye process tab tak repeat karenge jab tak saari elements traverse na ho jaayein.

8. `if(top <= bottom)` aur `if(left <= right)` important hain,
   kyunki single row ya single column ke case mein elements duplicate ho sakte hain.

Traversal order:

Top row       → Left → Right
Right column  → Top → Bottom
Bottom row    → Right → Left
Left column   → Bottom → Top

Example:

1  2  3
4  5  6
7  8  9

Spiral order:

1 → 2 → 3 → 6 → 9 → 8 → 7 → 4 → 5

TC: O(n × m)

SC: O(n × m)
Output vector `ans` mein saari elements store karni hain.

Auxiliary SC: O(1)
*/

//CODE:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;
        while(left<= right && top<= bottom){
            for(int j =left; j<=right; j++){
                ans.push_back(matrix[top][j]);
            }
            top++;

            for(int i =top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom){
            for(int j = right; j>=left; j--){
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
            }
            if(left<=right){
            for(int i = bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }}
        return ans;
    }
};
