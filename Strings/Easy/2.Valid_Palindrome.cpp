/*
Question:-
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all 
non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
*/
/*
Example:-
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

*/
/*
Approach:-
1.Make a isvalid function in which remove all the unnecessary signs.
2.Make anaother function too convert all the charcaters into lowercase .
3.Now one another function to check if the string is a palindrome or not.
4.Use all the functio in main function. 
*/
//code:-
class Solution {
public:
    bool isValid(char ch){
        if (ch>='A'&& ch<='Z'|| ch>='a' && ch<='z'|| ch>='0' && ch<= '9'){
            return 1;
        }
        else{
            return 0;
        }
    }
    int lowercase(char ch){
        if(ch>='a'&& ch<='z' || ch>='0'&& ch<= '9'){
            return ch;
        }
        else{
            char temp = ch -'A'+'a';
            return temp;
        }
    }
    bool check_palindrome(string s){
        int start =0; 
        int end = s.length()-1;
        while(start<end){
            if (s[start]!= s[end]){
                return 0;
            }
            else{
                start++;
                end--;
            }
        }
       return 1;
    }
    bool isPalindrome(string s) {
        string temp ="";
        for(int i =0; i<s.length(); i++){
        if(isValid(s[i])){
            temp.push_back(s[i]);
        }}
        for(int j=0; j<temp.length(); j++){
           temp[j]=  lowercase(temp[j]);
        }
        return check_palindrome(temp);
        
    }
};
