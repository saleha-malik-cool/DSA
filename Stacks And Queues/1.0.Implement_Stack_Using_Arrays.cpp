/*
Question:
Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following 
operations: push, pop, peek, and isEmpty.
Implement the ArrayStack class:
void push(int x): Pushes element x onto the stack.
int pop(): Removes and returns the top element of the stack.
int top(): Returns the top element of the stack without removing it.
boolean isEmpty(): Returns true if the stack is empty, false otherwise.

Example:
Input: ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]
[[], [5], [10], [], [], []]
Output: [null, null, null, 10, 10, false]
Explanation:
ArrayStack stack = new ArrayStack();
stack.push(5);
stack.push(10);
stack.top(); // returns 10
stack.pop(); // returns 10
stack.isEmpty(); // returns false
*/

//Code:
#include <iostream>
using namespace std;

class ArrayStack {
    int *arr;
    int Top;
    int size;

public:
    ArrayStack(int n) {
        size = n;
        Top = -1;
        arr = new int[size];
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(int x) {
        if (Top + 1 == size) {
            cout << "Stack Overflow" << endl;
            return;
        }

        arr[++Top] = x;
    }

    int pop() {
        if (Top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return arr[Top--];
    }

    int peek() {
        if (Top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return arr[Top];
    }

    bool isEmpty() {
        return Top == -1;
    }
};
/*
Approach:

We will implement a Stack using an Array. A stack follows the LIFO (Last In First Out) principle,
which means the element inserted last will be removed first.
We maintain:
1. An array `arr` to store the stack elements.
2. An integer `Top` to keep track of the index of the top element.
3. An integer `size` to store the maximum capacity of the stack.
Push Operation:
* First, check whether the stack is full by verifying if `Top + 1 == size`.
* If the stack is full, it is a Stack Overflow condition.
* Otherwise, increment `Top` and insert the element at `arr[Top]`.
Pop Operation:
* First, check whether the stack is empty by verifying if `Top == -1`.
* If the stack is empty, it is a Stack Underflow condition.
* Otherwise, store the top element, decrement `Top`, and return the stored element.
Peek Operation:
* Check whether the stack is empty.
* If the stack is not empty, return the element present at `arr[Top]` without removing it.
isEmpty Operation:
* If `Top == -1`, return true as the stack is empty.
* Otherwise, return false.
Time Complexity:
* Push: O(1)
* Pop: O(1)
* Peek: O(1)
* isEmpty: O(1)
Space Complexity:
* O(n), where n is the maximum size of the stack.

Destructor: A special member function that is automatically called when an object is destroyed.
It is used to release dynamically allocated memory and prevent memory leaks.
~ArrayStack() {
    delete[] arr;
}
Here, delete[] arr frees the memory allocated using new int[size].
*/
