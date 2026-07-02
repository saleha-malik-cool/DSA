/*
QUESTION:-
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
1. MinStack() initializes the stack object.
2. void push(int val) pushes the element val onto the stack.
3. void pop() removes the element on the top of the stack.
4. int top() gets the top element of the stack.
5. int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example:
Input : ["MinStack","push","push","push","getMin","pop","top","getMin"]
        [[],[-2],[0],[-3],[],[],[],[]]
Output : [null,null,null,null,-3,null,0,-2]
Explanation:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

/*
Approach:
APPROACH:
1. We use two stacks to implement the Min Stack:
   - s1 stores all the elements.
   - s2 stores the minimum elements encountered so far.
2. To push an element, first push it into s1. Then, if s2 is empty or the current value is less than or equal to the
top of s2, push it into s2 as well. This ensures that the top of s2 always stores the current minimum element.
3. To pop an element, check if the top of s1 is equal to the top of s2. If they are equal, pop from s2 as well 
since the current minimum is being removed. Finally, pop from s1.
4. To get the top element of the Min Stack, simply return s1.top().
5. To get the minimum element, return s2.top(), as it always stores the current minimum.
*/

//CODE:
class MinStack {
    stack <int> s1;
    stack <int> s2;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if (s2.empty() || s2.top() >= value){
            s2.push(value);
            s1.push(value);
        }
        else{
            s1.push(value);
        }
    }
    
    void pop() {
        if(s1.top()== s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
/*
APPROACH 2:
1. In this approach, we use a single stack along with a variable `mini` to implement the Min Stack. 
The stack stores both normal and encoded values, while `mini` stores the current minimum element.
2. To push an element:
   - If the stack is empty, push the value and set `mini = value`.
   - If the value is greater than or equal to `mini`, push it normally.
   - Otherwise, the value becomes the new minimum. Push the encoded value `(2 * value - mini)` 
   into the stack and update `mini = value`.
3. To pop an element:
   - If the top of the stack is greater than or equal to `mini`, it is a normal value, so simply pop it.
   - Otherwise, the top is an encoded value. Restore the previous minimum using `mini = 2 * mini - s.top()`,
   then pop the encoded value.
4. To get the top element:
   - If the top of the stack is greater than or equal to `mini`, return `s.top()`.
   - Otherwise, return `mini`, since the top is an encoded value.
5. To get the minimum element, simply return `mini`, which always stores the current minimum.
*/
//CODE:
class MinStack {
    stack <long long> s;
   long long min;
public:
    MinStack() {
         min= INT_MIN;
    }
    
    void push(int value) {
        if (s.empty()){
            min= value;
            s.push(value);
        }
        else {
            if(value>= min){
               s.push(value);
            }
           else{
             long long newmin= 2LL*value - min;
                min = value;
                 s.push(newmin);
           }
        }
    }
    
    void pop() {
        if (s.top()< min){
            min= 2LL*min - s.top(); 
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<min){
            return min;
        }
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};
//Time Complexity : O(1) {for all}
//Space Complexity : O(1) {no extra space}

//An alternate solution proposes use of a stack containing pairs as it's elements. Each element contains the value,
//and the minimum uptil there.
