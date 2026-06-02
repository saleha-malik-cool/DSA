/*
QUESTION:-
You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element.
You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).

Example:

Input: stack = [4, 1, 3, 2]
Output: [4, 3, 2, 1]
Explanation: After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.
*/

//USING STACK CODE:

/*
APPROACH:
1. We create a new stack : ns.
2. While st is empty, we pop each element, and push it in the new stack based on ascending order.
3. That is : If ns is empty or the top element is larger than i, we push i in ns. If not, we pop the elements from ns and push them in st till ns is empty or top element is greater than ns. Then we push i in ns.
4. This loop will arrange ns in ascending order.
5. So, while ns != empty, we pop all elements and push them back in st. Now, all elements in st are in descending order i.e. as required.
*/

class Solution {
public:
    void sortStack(stack<int> &st) {
        stack<int> ns;
        while(!st.empty()) {
            int i = st.top();
            st.pop();
            if(ns.empty() || i < ns.top()) {
                ns.push(i);
            }
            else {
                while(!ns.empty() && i > ns.top()) {
                    st.push(ns.top());
                    ns.pop();
                }
                ns.push(i);
            }
        }
        while(!ns.empty()) {
            st.push(ns.top());
            ns.pop();
        }
    }
};

//Time Complexity : O(N^2) {if for each element, all elements have to move to fit that}
//Space Complexity : O(N) {stack}

//RECURSIVE CODE:

/*
APPROACH:
1. We create a new function insert, with arguments stack st, and i, which will insert i in order in the stack st.
2. The base case of the recursive function will be if st is empty or the top element is lesser than i. Then, we push i in st and return.
3. We create a variable temp to store top element of st, and then we pop it.
4. Now, we call the function recursively to insert i again in the now updated stack.
5. Now, we push back the temp in the stack.
6. These all steps recursively insert i in an already sorted stack.
7. Now, in our main function, we create the base case as if st gets empty, then return.
8. Now, we pop the first element, and save it in a variable 'i'. Then, we recursively call the function, to sort the now updated stack.
9. Now, we insert i back into the stack, while the recursive stack gets backtracked.
10. This first empties the stack, then goes on inserting every element in the stack in order.
*/

class Solution {
public:
    void insert(stack<int> &st, int i) {
        if(st.empty() || st.top() < i) {
            st.push(i);
            return;
        }
        int temp = st.top();
        st.pop();

        insert(st, i);

        st.push(temp);
    }

    void sortStack(stack<int> &st) {
        if(st.empty()) return;

        int i = st.top();
        st.pop();
        
        sortStack(st);
        insert(st, i);
    }
};

//Time Complexity : O(N^2) {due to the insert function : if it will insert to the bottom-most in every step}
//Space Complexity : O(N) {recursion stack}
