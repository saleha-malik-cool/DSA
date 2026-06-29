/*
Question:
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

Exmaple:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]
Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
*/

/*
Approach:(Using Two Queues:1)
We use two queues (q1 and q2) to implement the stack. Since a queue follows FIFO (First In First Out) but a stack
follows LIFO (Last In First Out), we simulate the stack operations by transferring elements between the two queues.
1.Push: Insert the new element into the queue that currently contains all the elements. If both queues are empty,
insert into q1. This operation takes O(1) time.
2.Pop: To remove the top element of the stack, transfer the first n-1 elements from the active queue to the other 
queue. The last remaining element is the most recently inserted element (the stack's top). Remove and return it.
3.Top: Similar to pop(), transfer the first n-1 elements to the other queue. Store the last element, remove it 
from the current queue, push it into the other queue to preserve the stack, and return its value.
4.Empty: The stack is empty only when both queues are empty
*/

//Code:
class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
    }

    void push(int x) {
        if (q1.empty() && q2.empty())
            q1.push(x);
        else if (!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop() {
        if (empty())
            return -1;

        if (q1.empty()) {
            while (q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }

            int k = q2.front();
            q2.pop();
            return k;
        }

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int k = q1.front();
        q1.pop();
        return k;
    }

    int top() {
        if (empty())
            return -1;

        if (q1.empty()) {
            while (q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }

            int k = q2.front();
            q2.pop();
            q1.push(k);   
            return k;
        }

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int k = q1.front();
        q1.pop();
        q2.push(k);       
        return k;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/*
Time Complexity
Push: O(1)
Pop: O(n)
Top: O(n)
Empty: O(1)

Space Complexity
O(n), where n is the number of elements in the stack, as all elements are stored in the two queues.
*/

/*
[Approach 2 (Costly Push)]


We use two queues (q1 and q2) to implement the stack. The idea is to maintain the top element at the front of 
the active queue so that pop() and top() can be performed in O(1) time.
1.Push: Insert the new element into the empty queue (q2). Then, move all elements from q1 to q2. Finally,
swap the two queues. After this process, the newly inserted element becomes the front of q1, which represents
the top of the stack.
2.Pop: Remove and return the front element of q1 since it always stores the current top of the stack.
3.Top: Return the front element of q1 without removing it.
4.Empty: The stack is empty if q1 is empty.
*/
lass MyStack {
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
#Time Complexity
1.Push: O(n)
2.Pop: O(1)
3.Top: O(1)
4.Empty: O(1)
#Space Complexity
O(n), where n is the number of elements stored in the stack.
*/

/*
Approach (One Queue)
1. In this approach, we use one queue to implement a stack. We use the idea that everytime we push, we pop the elements before it and push them back in the queue.
2. To push, we first save the current size of the queue in a variable n, and then push the element. Then, we run a loop from 0 to n-1, and pop all elements and push them back in the stack. By the end, x will be at the front of the queue.
3. To pop, we pop the front element from the queue.
4. To check the top, we return the front element of the queue.
5. To check if stack is empty, if queue is empty, return true. Else, return false.
In this, push takes O(N) time while popping and top function are convenient and faster. It also uses just one queue to implement the stack.

*/

//CODE:
class MyStack {
public:
    queue<int> q;

    MyStack() {
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);

        for(int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int k = q.front();
        q.pop();
        return k;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

//Time Complexity : Push - O(N), Pop - O(1), Top - O(1), Empty - O(1)
//Space Complexity : O(N)
