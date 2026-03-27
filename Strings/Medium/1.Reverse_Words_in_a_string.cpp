/*
Question:-
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only
have a single space separating the words. Do not include any extra spaces.
*/
/*
Example:-
Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
*/
/*
Approach:-

1. Initiate a empty string as ans and reverse the whole string.
2.for loop from i =0 to length -1 ans initiate empty string as word;
3.inside for loop a while loop first condition i<n (prevent out of bound error)&& s[i]!=' ';
4.now add each char to wprd unit " ";
5. after for loop ended check condition if (word.length( )>0) and then  ans.length>0 and fir usme ans+=" " krna now
close ans.length  wala ab ans+=word krna yeh dhyan se dekhna to prevent extra space and space ata starting and ending.
6. return ans.
  */
//CODE:-
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        string ans ="";
        for(int i =0; i<n; i++){
            string word="";
            while(i< n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            
            if(word.length()>0){
                if (ans.length()>0){
                ans+=" ";
            }
            ans+=word;}
        }
        return ans;
    }
};
 
