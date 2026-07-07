/*
QUESTION:
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the 
array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction 
(positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
*/
/*
APPROACH:
Approach (Using Stack)

1. Create an empty stack to store the surviving asteroids.
2. Traverse the asteroids array one by one.
3. For each asteroid, set a boolean variable `destroyed = false`.
4. A collision is possible only when:
   - The top of the stack is moving right (positive).
   - The current asteroid is moving left (negative).
5. While a collision is possible:
   - If abs(stack top) > abs(current asteroid):
     - The current asteroid is destroyed.
     - Set destroyed = true and break.
   - Else if abs(stack top) < abs(current asteroid):
     - The asteroid on the stack is destroyed.
     - Pop it from the stack.
     - Continue checking because the current asteroid may collide with more asteroids.
   - Else (both have the same size):
     - Both asteroids are destroyed.
     - Pop the top asteroid.
     - Set destroyed = true and break.
6. After the while loop, if the current asteroid is not destroyed, push it onto the stack.
7. After processing all asteroids, the stack contains all surviving asteroids.
8. Pop all elements from the stack into a vector, reverse the vector, and return the result.

*/

//CODE:
lass Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> s;
        int n = asteroids.size();
        for(int i =0; i<n; i++){
             bool destroyed= false;
            while(!s.empty() && s.top() >0 && asteroids[i] <0 ){
                
                if(abs(s.top()) > abs(asteroids[i])){
                    destroyed=true;
                    break;
                }
                else if(abs(s.top()) < abs(asteroids[i])){
                    s.pop();
                    
                    
                }
                else{
                    s.pop();
                    destroyed= true;
                    
                }
            }
           
            if(!destroyed){
            s.push(asteroids[i]);}
        }
        vector<int> ans;

        while(!s.empty()){
        ans.push_back(s.top());
        s.pop();}


        reverse(ans.begin(), ans.end());

return ans;
        
    }
};
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
