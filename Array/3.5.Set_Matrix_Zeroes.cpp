/*
QUESTION:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

/*
BRUTE APPROACH:

1. Matrix ko traverse karo.
2. Jahan bhi `matrix[i][j] == 0` mile:
   - Uski row ko `row` vector mein store karo.
   - Uski column ko `col` vector mein store karo.
3. Matrix traverse hone ke baad:
   - `row` vector mein stored har row ko completely `0` karo.
   - `col` vector mein stored har column ko completely `0` karo.
4. Pehle zero positions store karte hain aur baad mein zero karte hain,
   taaki naye zeros ki wajah se traversal affect na ho.

TC: O(n × m)

SC: O(n + m)
*/

//CODE:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row;
        vector<int> col;

        // Find zero positions
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        // Set rows to zero
        for(int r : row) {
            for(int j = 0; j < m; j++) {
                matrix[r][j] = 0;
            }
        }

        // Set columns to zero
        for(int c : col) {
            for(int j = 0; j < n; j++) {
                matrix[j][c] = 0;
            }
        }
    }
};

/*
OPTIMAL APPROACH:

1. First row aur first column ko markers ki tarah use karenge, taaki extra row/column array na banana pade.
2. Sabse pehle check karenge ki original first row mein koi `0` hai ya nahi.
   Agar hai, toh `firstrow = true` kar denge.
3. Similarly, check karenge ki original first column mein koi `0` hai ya nahi.
   Agar hai, toh `firstcol = true` kar denge.
4. Ab first row aur first column ko chhodkar baaki matrix traverse karenge.
5. Agar `matrix[i][j] == 0` mile:
   - `matrix[i][0] = 0` karke poori row ko mark karenge.
   - `matrix[0][j] = 0` karke poore column ko mark karenge.
6. Ab marked rows ko zero karenge.
   Agar `matrix[i][0] == 0` hai, toh poori row ko zero kar denge.
7. Marked columns ko zero karenge.
   Agar `matrix[0][j] == 0` hai, toh poora column zero kar denge.
8. Finally, agar `firstrow == true` hai, toh poori first row ko zero karenge.
9. Agar `firstcol == true` hai, toh poora first column zero karenge.
10. First row aur first column ko end mein zero karna zaroori hai kyunki unhe pehle markers ke liye use kiya tha.

TC: O(n × m)

SC: O(1)
Koi extra row/column array ya data structure use nahi kiya.
*/

//CODE:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstrow = false;
        bool firstcol = false;

        // Check first column
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) {
                firstcol = true;
            }
        }

        // Check first row
        for(int j = 0; j < m; j++) {
            if(matrix[0][j] == 0) {
                firstrow = true;
            }
        }

        // Mark rows and columns
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set marked rows to zero
        for(int i = 1; i < n; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set marked columns to zero
        for(int j = 1; j < m; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set first row
        if(firstrow) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Set first column
        if(firstcol) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
