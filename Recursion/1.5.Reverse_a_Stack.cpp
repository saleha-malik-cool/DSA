/*
You are given a stack of integers. Your task is to reverse the stack using recursion.
You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop 
constructs or additional data structures like arrays or queues.
Example 
Input: stack = [4, 1, 3, 2]
Output: [2, 3, 1, 4]
*/
//Using a new stack
/*
ALGORITHM: Reverse a Stack Using an Extra Stack

1. Create an empty stack `temp`.
2. While the original stack is not empty:
   a. Read the top element.
   b. Pop the element from the original stack.
   c. Push the element into `temp`.
3. After all elements are transferred, assign `temp` to the original stack.
4. The stack is now reversed.
*/
//Code:
 void reverseStack(stack<int>& st) {
    stack<int> temp;

    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    st = temp;
}
//Time Complexity:-O(N)
//Space Complexity:-O(N)

//Recursion approach:

//Code:
class Solution {
public:
void insert(stack<int>&st, int i){
    if(st.empty()){
        st.push(i);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st,i);
    st.push(temp);
}
    void reverseStack(stack<int> &st) {
       if(st.empty()){
        return;
       }
       int i = st.top();
       st.pop();
       reverseStack(st);
       insert(st,i);
    }
};
/*
Approach:-
1. Stack ke top element ko store karke pop kar do.
2. Remaining stack ko recursively reverse karo.
3. Jab stack completely empty ho jaye, recursion return hona start hogi.
4. Return hote time stored element ko stack ke bottom mein insert karo.
5. Bottom mein insert karne ke liye:
Agar stack empty hai, element push kar do.
Warna top element ko temporary remove karo.
New element ko bottom mein insert karo.
Temporary element ko wapas push kar do.
6. Har recursive call return hote time apna element bottom mein insert karti hai.
7. Is process se stack ka order ulta ho jata hai aur stack reverse ho jati hai.
*/

//Time Complexity : O(N^2) {inserting every element at bottom}
//Space Complexity : O(N) {recursion stack}

/*
Time Complexity: O(n²)
reverseStack() function n times call hota hai aur har element ko bottom mein insert karne ke liye insert() function stack ke remaining elements traverse karta hai.
Total operations 1 + 2 + 3 + ... + n hoti hain, jo O(n²) ke equal hoti hain.
*/
