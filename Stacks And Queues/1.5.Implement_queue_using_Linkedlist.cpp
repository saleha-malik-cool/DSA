/*
QUESTION:-
Implement a First-In-First-Out (FIFO) queue using a singly linked list. The implemented queue should support
the following operations: push, pop, peek, and isEmpty.
Example:
Input : ["myqueue", "push", "push", "peek", "pop", "isEmpty"]
        [[], [3], [7], [], [], []]
Output : [null, null, null, 3, 3, false]
Explanation:
myqueue queue = new myqueue();
queue.push(3);
queue.push(7);
queue.peek(); // returns 3
queue.pop(); // returns 3
queue.isEmpty(); // returns false
*/
/*
APPROACH:
1. We first create a Node class to define the structure of each node containing data and a pointer to the next node.
2. We maintain two pointers, front and rear, and initialize both to NULL. The front pointer represents the first element
of the queue, while the rear pointer represents the last element.
3. To enqueue (push) an element, if the queue is empty, we create a new node and make both front and rear point to it.
Otherwise, we create a new node, attach it to the end of the queue using rear->next, and update rear to the new node.
4. To dequeue (pop) an element, if the queue is empty (front == NULL), we return -1. Otherwise, we store the data of
the front node, move front to the next node, delete the old front node, and return the stored value.
If the queue becomes empty after deletion, we also set rear to NULL.
5. To peek at the front element, if the queue is empty, we return -1. Otherwise, we return the data stored in 
the front node.
6. To check whether the queue is empty, we simply check if front is NULL. If it is, we return true; otherwise,
we return false.

*/

//Code:
class Node{
public:
int data;
Node* next;
Node(int x){
    data =x;
    next=NULL;
    
}
};


class LinkedListQueue {
    Node* front;
    Node* rear;
public:
    LinkedListQueue() {
        front=NULL;
        rear=NULL;
    }
    
    void push(int x) {
      if(front==NULL){
        front= rear= new Node(x);
        return;
      }
      rear->next= new Node(x);
      rear= rear->next;
    }
    
    int pop() {
        if( front==NULL){
            return -1;
        }
        else{
            Node* temp = front;
            int x = temp->data;
            front = front->next;
            if(front==NULL) rear=NULL;
            delete temp;
            return x;
        }

  
    }
    
    int peek() {
        if (front == NULL){
            return -1;
        }
        else{
            return front->data;
            
        }
    }
    
    bool isEmpty() {
        if(rear == NULL){
            return true;
        }
        return false;
    }
};

/*
#Time Complexity (TC)
1.push() → O(1) (Insertion is done at the rear of the queue.)
2.pop() → O(1) (Deletion is done from the front of the queue.)
3.peek() → O(1) (Returns the front element directly.)
4.isEmpty() → O(1) (Checks whether front is NULL.)
#Space Complexity (SC)
O(n), where n is the number of elements in the queue, since each element is stored as a node in the linked list.
*/
