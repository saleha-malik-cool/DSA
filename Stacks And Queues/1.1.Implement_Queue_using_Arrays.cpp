/*
Question:
Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following
operations: push, peek, pop, and isEmpty.
Implement the ArrayQueue class:
void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise.

Example:
Input:
["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]
[[], [5], [10], [], [], []]
Output: [null, null, null, 5, 5, false]
Explanation:
ArrayQueue queue = new ArrayQueue();
queue.push(5);
queue.push(10);
queue.peek(); // returns 5
queue.pop(); // returns 5
queue.isEmpty(); // returns false
*/

/*
Approach:
A queue follows the FIFO (First In First Out) principle, meaning the element inserted first is removed first.
We use an array to store the queue elements and two pointers:
1. front -> points to the first element of the queue.
2. rear -> points to the last element of the queue.
Initially:
front = 0
rear = -1
Push Operation:
- First check if the queue is full (rear == size - 1).
- Increment rear.
- Insert the new element at arr[rear].
Pop Operation:
- Check if the queue is empty (front > rear).
- Return the element at the front.
- Increment front to move to the next element.
Peek Operation:
- Check if the queue is empty.
- Return the element at the front without removing it.
isEmpty Operation:
- The queue is empty when front > rear.

*/

//Code:
class ArrayQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    ArrayQueue(int n) {
        size = n;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    void push(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }

        arr[++rear] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        return arr[front++];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }

    ~ArrayQueue() {
        delete[] arr;
    }
};
/*
Time Complexity:
Push  : O(1)
Pop   : O(1)
Peek  : O(1)
isEmpty : O(1)
Space Complexity:
O(size)
Limitation:
In a simple array queue, the positions freed after pop operations are not reused.
Therefore, overflow may occur even when some spaces at the beginning of the array are empty. 
This limitation can be overcome using a Circular Queue.
*/

/*
Approach:
A Circular Queue is an improved version of a normal queue that overcomes the limitation of unused spaces after 
deletion. It follows the FIFO (First In First Out) principle, where the element inserted first is removed first.
We use an array to store the queue elements and maintain four variables:
1. front -> points to the front element of the queue.
2. rear  -> points to the next insertion position.
3. count -> stores the current number of elements in the queue.
4. size  -> maximum capacity of the queue.
Initially:
front = 0
rear = 0
count = 0
Push Operation:
- First check if the queue is full (count == size).
- Insert the element at arr[rear].
- Move rear circularly using:
    rear = (rear + 1) % size
- Increment count.
Pop Operation:
- Check if the queue is empty (count == 0).
- Store the front element.
- Move front circularly using:
    front = (front + 1) % size
- Decrement count.
- Return the removed element.
Peek Operation:
- Check if the queue is empty.
- Return the element at arr[front] without removing it.
isEmpty Operation:
- The queue is empty when:
    count == 0
Key Idea:
The modulo (%) operator makes the queue circular. When front or rear reaches the last index of the array, 
it automatically wraps around to index 0. This allows reuse of previously freed positions and prevents memory wastage.

*/

*/



//Circular Queuee Code:
//code:
#include <iostream>
using namespace std;

class MyQueue {
    int front;
    int rear;
    int size;
    int count;
    int* arr;

public:
    MyQueue(int n) {
        size = n;
        arr = new int[size];

        front = 0;
        rear = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        arr[rear] = x;
        rear = (rear + 1) % size;
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << arr[front] << " popped" << endl;
        front = (front + 1) % size;
        count--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        int i = front;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};
/*
Time Complexity:
Push      : O(1)
Pop       : O(1)
Peek      : O(1)
isEmpty   : O(1)
Space Complexity:
O(size)
Advantage:
Unlike a simple array queue, the freed positions created after pop operations are reused efficiently,
allowing optimal utilization of the array.
*/
