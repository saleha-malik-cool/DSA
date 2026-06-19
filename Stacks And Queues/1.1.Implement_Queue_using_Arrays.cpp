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
