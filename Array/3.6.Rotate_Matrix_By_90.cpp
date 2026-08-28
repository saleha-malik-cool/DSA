/*
QUESTION:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

/*
Approach:

1. Humein matrix ko 90° clockwise rotate karna hai.

2. Iske liye 2 steps karenge:
   Step 1 → Matrix ka transpose
   Step 2 → Har row ko reverse

--------------------------------------------------

Step 1: Transpose

3. Transpose mein matrix ki rows columns ban jaati hain.

   Example:

   1 2 3
   4 5 6
   7 8 9

   Transpose:

   1 4 7
   2 5 8
   3 6 9

4. Transpose karne ke liye:
   
   `matrix[i][j]` ko `matrix[j][i]` se swap karenge.

5. Lekin `j = i + 1` se start karenge.

   Example:
   i = 0 → j = 1, 2
   i = 1 → j = 2
   i = 2 → koi element nahi

6. `j = i + 1` isliye lete hain kyunki diagonal ke elements ko
   swap nahi karna hota.

   `matrix[0][0]`, `matrix[1][1]`, `matrix[2][2]`
   same position par rahenge.

7. Saath hi same pair ko dobara swap hone se bhi bachate hain.

   Example:
   `matrix[0][1]` ko `matrix[1][0]` se swap kiya.

   Agar dobara swap karenge toh woh wapas original position par aa jayega.

--------------------------------------------------

Step 2: Har Row Reverse

8. Transpose ke baad:

   1 4 7
   2 5 8
   3 6 9

9. 90° clockwise rotation ke liye har row ko reverse karenge:

   1 4 7 → 7 4 1
   2 5 8 → 8 5 2
   3 6 9 → 9 6 3

10. Final matrix:

    7 4 1
    8 5 2
    9 6 3

11. Isliye 90° clockwise rotation ka formula:

    Transpose + Reverse every row

--------------------------------------------------

Code:

for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}

for(int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
}

j = i + 1
→ diagonal ko avoid karne ke liye
→ same pair ko dobara swap hone se bachane ke liye

Row reverse
→ transpose ke baad elements ko clockwise 90° ki correct position mein laane ke liye

TC: O(n²)

SC: O(1)

*/

//CODE:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j = i+1; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i =0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }}
    
};
