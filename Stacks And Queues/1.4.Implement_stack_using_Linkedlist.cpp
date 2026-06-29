/*
QUESTION:-
Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The implemented stack should support 
the following operations: push, pop, top, and isEmpty.
Example:
Input : ["mystack", "push", "push", "pop", "top", "isEmpty"]
        [[], [3], [7], [], [], []]
Output: [null, null, null, null, 3, false]
Explanation:
mystack stack = new mystack();
stack.push(3);
stack.push(7);
stack.pop();
stack.top(); // returns 3
stack.isEmpty(); // returns false
*/
/*
APPROACH:
1. We first create a Node class to define the structure of each node containing data and a pointer to the next node.
2. We create a head pointer for the stack and initialize it to NULL. The head always represents the top of the stack.
3. To push an element, we create a new node with the given value, make its next pointer point to the current head, 
and update head to the new node.
4. To pop an element, if the stack is empty (head == NULL), we return -1. Otherwise, we store the head node's data,
move head to the next node, delete the old head node, and return the stored value.
5. To get the top element, if the stack is empty, we return -1. Otherwise, we return the data stored in the head node.
6. To check whether the stack is empty, we simply check if head is NULL. If it is, we return true; otherwise,
we return false.
*/
//Code:
class Node{
public:
int data;
Node* next;
Node(int x){
    data =x;
    next = NULL;
}
};
class LinkedListStack {
    Node* head;
public:
    LinkedListStack() {
        head = NULL;
    }
    
    void push(int x) {
        Node* temp =new Node(x);
        temp-> next= head;
        head=temp;
    }
    
    int pop() {
        if(head==NULL){
            return -1;
        }
        else{
            int ans= head->data;
           Node* temp = head;
           head= head->next;
           delete temp;
           return ans;
        }
        

    }
    
    int top() {
        if(head==NULL){
            return -1;
        }
        else{
            return head->data;
        }
    }
    
    bool isEmpty() {
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
//Time Complexity : O(1) {for all}
//Space Complexity : O(N)
