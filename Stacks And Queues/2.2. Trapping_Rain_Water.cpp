/*
QUESTION:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

*/

/*
#BRUTE APPROACH:
1. Initialize a variable water = 0.
2. Traverse the array from index 1 to n-2 (first and last bars cannot trap water).
3. For each index i:
   - Find the maximum height on the left of i (including i).
   - Find the maximum height on the right of i (including i).
   - The water trapped at index i is:
       min(leftMax, rightMax) - height[i]
   - Add this value to water.
4. Return the total water trapped.
*/

//BRUTE CODE:
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        for (int i = 1; i < n - 1; i++) {

            int leftMax = height[i];
            for (int j = i - 1; j >= 0; j--) {
                leftMax = max(leftMax, height[j]);
            }

            int rightMax = height[i];
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }

            water += min(leftMax, rightMax) - height[i];
        }

        return water;
    }
};
/*Time Complexity:Finding leftMax takes O(n).
Finding rightMax takes O(n).
This is done for every index.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

/*
BETTER Approach:
1. Create two arrays:
   - Left[i] stores the maximum height from index 0 to i.
   - Right[i] stores the maximum height from index i to n-1.
2. Build the Left array:
   - Initialize leftMax = height[0].
   - Traverse from left to right.
   - Update leftMax = max(leftMax, height[i]).
   - Store leftMax in Left[i].
3. Build the Right array:
   - Initialize rightMax = height[n-1].
   - Traverse from right to left.
   - Update rightMax = max(rightMax, height[i]).
   - Store rightMax in Right[i].
4. Traverse the array again.
   - For each index i, the water trapped is:
     min(Left[i], Right[i]) - height[i]
   - Add this value to the total water.
5. Return the total trapped water.
*/

//BETTER CODE:
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> Left(n);
        vector<int> right(n);
        int water=0;
         int leftmax= height[0];
        for(int i = 0; i< n; i++){
           
            if(height[i]> leftmax){
                leftmax= height[i];
            }
            Left[i]= leftmax;
        }
        int rightmax= height[n-1];
        for(int i = n-1; i>=0; i--){
            if(height[i]> rightmax){
                rightmax= height[i];
            }
            right[i] = rightmax;
            water+= min(Left[i],right[i]) - height[i];
        }
        
        return water;
    }
};
/*
Time Complexity
O(n)
- O(n) to build the Left array.
- O(n) to build the Right array.
- O(n) to calculate the trapped water.

Space Complexity
O(n)
- O(n) for the Left array.
- O(n) for the Right array.
*/



/*
Approach (Two Pointer):
1. Initialize two pointers:
   - left = 0
   - right = n - 1
2. Maintain two variables:
   - leftMax = maximum height seen so far from the left.
   - rightMax = maximum height seen so far from the right.
3. While left < right:
   - Update leftMax and rightMax.
   - If leftMax < rightMax:
       - The water trapped at the left index depends only on leftMax,
         because there is already a taller bar on the right.
       - Water trapped = leftMax - height[left].
       - Add it to the answer.
       - Move left pointer one step to the right.
   - Otherwise:
       - The water trapped at the right index depends only on rightMax,
         because there is already a taller bar on the left.
       - Water trapped = rightMax - height[right].
       - Add it to the answer.
       - Move right pointer one step to the left.
4. Continue until both pointers meet.
5. Return the total trapped water.
Why does this work?
Water at any index is:
Water = min(leftMax, rightMax) - height[i]
If leftMax < rightMax, then leftMax is the limiting boundary, so we can safely calculate the water at the left pointer without knowing the exact future right boundary.
Similarly, if rightMax <= leftMax, then rightMax is the limiting boundary, so we calculate the water at the right pointer.
*/

//CODE:
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r= n-1;
        int ans=0;
        int lmax=0;
        int rmax=0;
        while(l<r){
             lmax= max(height[l],lmax);
             rmax= max(height[r],rmax);
            if(lmax<rmax){
                ans+=lmax - height[l];
                l++;
            }
            else{
                ans+= rmax - height[r];
                r--;
            }
        }
        return ans;

    }
};

/*
Time Complexity: O(n)
- Each pointer moves at most n times.

Space Complexity: O(1)
- Only a few variables are used; no extra arrays are required.
*/

/*
Approach (Monotonic Stack):
1. Create an empty stack to store the indices of bars.
   - The stack maintains the indices of bars in decreasing order of height.
2. Traverse the height array from left to right.
3. For each bar:
   - While the stack is not empty and the current bar is taller than the bar at the top of the stack:
       a. Pop the top element. This is the bottom (middle) of a water container.
       b. If the stack becomes empty, no left boundary exists, so stop.
       c. The new top of the stack becomes the left boundary.
       d. The current bar acts as the right boundary.
       e. Calculate the width:
            width = currentIndex - leftBoundary - 1
       f. Calculate the height of trapped water:
            height = min(leftBoundaryHeight, rightBoundaryHeight) - middleHeight
       g. Water trapped = width × height.
       h. Add it to the answer.
4. Push the current index onto the stack.
5. After the traversal, return the total trapped water.
*/
//CODE:
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        stack<int> st;

        int i = 0;
        int water = 0; 

        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int middle = st.top();
                st.pop();

                if(st.empty()) break;

                int left = st.top();
                int width = i - left - 1;

                int h = min(height[i], height[left]) - height[middle];
                water += h * width;
            }
            st.push(i);
        }
        return water;
    }
};
//Time Complexity : O(N)
//Space Complexity : O(N)
