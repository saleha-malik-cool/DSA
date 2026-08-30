/*
QUESTION:
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

/*
APPROACH:

1. Ek vector ans banao jo current row store kare.
2. Pehli row [1] ko ans mein daalo.
3. Is row ko pascal mein store karo.

4. Jab tak numRows nahi ban jaati:
   a. ans ki copy ans2 mein banao.
   b. ans ko clear karo.
   c. New row ka first element 1 daalo.
   d. Previous row ke adjacent elements ko add karo:
        ans2[i] + ans2[i+1]
      aur result ko ans mein daalo.
   e. New row ka last element 1 daalo.
   f. New row ko pascal mein store karo.

5. pascal return karo.
*/

//CODE:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> ans;
        vector<int> ans2;
        vector<vector<int>> pascal;

        ans.push_back(1);
        pascal.push_back(ans);

        int count = 1;

        while(count < numRows) {
            ans2 = ans;
            ans.clear();

            int n = ans2.size();

            ans.push_back(1);

            for(int i = 0; i < n - 1; i++) {
                int sum = ans2[i] + ans2[i + 1];
                ans.push_back(sum);
            }

            ans.push_back(1);
            pascal.push_back(ans);

            count++;
        }

        return pascal;
    }
};

/*
TC = O(numRows²)
SC = O(numRows²)
*/
