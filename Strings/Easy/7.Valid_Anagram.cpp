/*
QUESTION:-
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Anagrams are words that contain the same letters, but jumbled.

Example:

Input: s = "anagram", t = "nagaram"
Output: true
*/

/*
APPROACH:
1. If the length of both strings are unequal, return false.
2. Initialise two arrays, each of 26 length {since only lowercase letters are included in both strings} initialised from 0,
since we have to store the number of times each letter has occured in each string.
3. Traversing through the length of the strings, we do +1 for each time a letter occurs, on the index {s[i] - 'a'} 
or {t[i] - 'a'}, so that they fall from 0 to 25 index itself.
4. Now, traversing through those arrays, we check if every ith element in those arrays is same. If no, return false.
5. Else, return true.
*/
//Code:-
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()){
            return false;
        }
        int sf[26]={0};
        int tf[26]={0};
        int n = s.length();
        for(int i =0; i<n;i++){
            sf[s[i]-'a']++;
            tf[t[i]-'a']++;
        }
        for(int j=0; j<26; j++){
            if(sf[j]!=tf[j]){
                return false;
            }
        }
        return true;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
