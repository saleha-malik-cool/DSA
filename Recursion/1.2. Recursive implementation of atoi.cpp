/*
Question:
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

Example:
Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)

*/
//Code:
class Solution {
public:
    int check(string& s, int i, int sign, long long ans, bool started) {

        if(i == s.length())
            return sign * ans;

        if(!started && s[i] == ' ')
            return check(s, i + 1, sign, ans, false);

        if(!started && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-')
                return check(s, i + 1, -1, ans, true);
            else
                return check(s, i + 1, 1, ans, true);
        }

        if(!isdigit(s[i]))
            return sign * ans;

        int digit = s[i] - '0';

        if(sign == 1 && ans > (INT_MAX - digit) / 10)
            return INT_MAX;

        if(sign == -1 &&
           ans > ((long long)INT_MAX + 1 - digit) / 10)
            return INT_MIN;

        ans = ans * 10 + digit;

        return check(s, i + 1, sign, ans, true);
    }

    int myAtoi(string s) {
        return check(s, 0, 1, 0, false);
    }
};
/*
APPROACH:

1. Hum is problem ko recursion ki help se solve kar rahe hain.
2. Hum ek helper function check() banate hain jisme:
   - s -> input string
   - i -> current index
   - sign -> number positive hai ya negative (1 ya -1)
   - ans -> ab tak bana hua number store karta hai
   - started -> batata hai ki parsing start hui hai ya nahi
3. Agar i string ki length tak pahunch jaye, to hum sign * ans return kar dete hain kyunki poori string process 
ho chuki hai.
4. Agar parsing abhi start nahi hui hai aur current character space (' ') hai, to hum us space ko skip kar
dete hain aur i + 1 ke saath recursive call kar dete hain.
5. Agar parsing abhi start nahi hui hai aur current character '+' ya '-' hai:
   - Agar '-' hai to sign = -1 set kar dete hain.
   - Agar '+' hai to sign = 1 set kar dete hain.
   Fir next index ke liye recursive call kar dete hain.
6. Spaces aur sign handle karne ke baad agar current character digit nahi hai, to iska matlab valid number yahin 
tak tha, isliye hum sign * ans return kar dete hain.
7. Agar current character digit hai, to hum us digit ki numeric value nikalte hain:
   digit = s[i] - '0'
8. Digit ko answer me add karne se pehle overflow check karte hain:
   - Agar positive number INT_MAX se bada hone wala hai to INT_MAX return kar dete hain.
   - Agar negative number INT_MIN se chhota hone wala hai to INT_MIN return kar dete hain.
9. Overflow check ke baad current digit ko answer me add karte hain:
   ans = ans * 10 + digit
10. Ab next character process karne ke liye recursive call karte hain:
    check(s, i + 1, sign, ans, true)
    Yahan started = true kar dete hain kyunki number banana start ho gaya hai.
11. Main function myAtoi() me recursion ko initial values ke saath start karte hain:
    check(s, 0, 1, 0, false)
    Yahan:
    - i = 0 hai kyunki string ke start se process karna hai.
    - sign = 1 hai kyunki default number positive maana jata hai.
    - ans = 0 hai kyunki abhi koi digit process nahi hui hai.
    - started = false hai kyunki parsing abhi start nahi hui hai.
12. Is tarah recursion string ko character by character process karti hai aur final integer answer return kar 
deti hai.*/


//Time Complexity:O(N) {Traversing through the string only once}
//Space Complexity:O(N) {Recursion stack}

//Code 2:
class Solution {
public:
    int myAtoi(string s) {
        int i =0;
        bool started = false;
        int sign=1;
        long long ans=0;
        while(i< s.length()){
        if (!started && s[i]==' '){
            i++;
            continue;
        }
        if(!started &&( s[i]=='+'|| s[i]=='-')){
            if(s[i]=='+'){
                sign =1;
                
            }
            else{
                sign=-1;
               
            }

            i++;
            started=true;
            continue;

            
        }
         if(!isdigit(s[i])){
            return sign*ans;
        }int digit= s[i] -'0';
        if(sign == 1 && ans > (INT_MAX - digit)/10){
            return INT_MAX;
}
        if(sign == -1 && ans > ((long long)INT_MAX + 1 - digit)/10){
            return INT_MIN;
          
        }
       
        
        else{
            started = true;
            ans = ans*10+digit;
            i++;
        }
    }
    return sign*ans;
}};
