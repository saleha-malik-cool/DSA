/*
Queestion:
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

*/
/*
Approach:
1. Initialize two queues, q1 and q2.
2. At any time, only one queue contains all the stack elements, while the other queue remains empty.
3. For the push(x) operation:
   - Insert the new element into the empty queue.
   - Transfer all the existing elements from the active queue to the other queue.
   - After the transfer, the newly inserted element remains at the front of the active queue, making it the 
   top of the stack.
4. For the pop() operation:
   - Remove and return the front element of the active queue.
5. For the top() operation:
   - Return the front element of the active queue without removing it.
6. For the empty() operation:
   - Return true if both queues are empty; otherwise, return false.

*/
//Code:
class MyStack {
public:
queue <int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q2.empty()){
            q2.push(x);
            while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }}
        else{
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        }
    
    
    int pop() {
        if (q1.empty() && q2.empty()){
                return -1;
        }
        else if(q1.empty()){
            int k = q2.front();
            q2.pop();
            return k;
        }
        int k = q1.front();
        q1.pop();
        return k;
    }
    
    int top() {
       if (q1.empty() && q2.empty()){
                return -1;
        }
        else if(q1.empty()){
            return q2.front();
        }
        return q1.front();
    }
    
    bool empty() {
        if (q1.empty() && q2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
/*
Time Complexity:
- Push: O(n)
- Pop: O(1)
- Top: O(1)
- Empty: O(1)

Space Complexity:
- O(n)
*/

/*
/*
APPROACH 2:
1. We use the idea that we always push in one stack, and whenever we have to pop, we use the other stack.
2. To push, we push the element in s1.
3. To pop, if s2 is empty, we pop all elements out of s1 and push them in s2.
4. Then, we pop the element out of s2. {This way, the last element comes to the top, hence acting like a queue.}
5. To peek, if s2 is empty, we pop all elements out of s1 and push them in s2. Then, we return the top element of s2.
6. To check if queue is empty, if both stacks are empty, return true. Else, return false.
*/
//CODE:
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
            }
        }
        int k = s2.top();
        s2.pop();
        return k;
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

//Time Complexity : Push - O(1), Pop - O(N), Top - O(N), Empty - O(1) {because transfer may occur}
//Amortized Complexity {average cost per operation} : O(1) {for all}
//Space Complexity : O(N)
