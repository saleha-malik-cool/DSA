/*
QUESTION:-
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

/*
APPROACH:
1. We initialise a string variable, which stores the first element string.
2. Traversing through the first string, we compare it's ith elements with each string's ith element.
3. We intialise a boolean variable as true.
4. While comparing, if we come across an i which is greater than any of the string's length or, if any string's ith element is not equal to the ith element of 'start', we change check into false and break the loop.
5. Now, if check is true, we add the element to ans. If not, we break the loop.
6. Return ans.
*/
//Code:-
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0; i<strs[0].length();i++){
            char ch = strs[0][i];
            bool match = true;
            for(int j =1; j<strs.size(); j++){
                if(strs[j].size()<i || ch!= strs[j][i]){
                    match = false;
                    break;
                }
            }
            if (match==false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
//Time Complexity : O(n * m) {n = number of strings} {m = length of smallest string}
//Space Complexity : O(m)
