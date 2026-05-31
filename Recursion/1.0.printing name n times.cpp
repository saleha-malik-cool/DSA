/*
 Question:-
 Printing name n times using recursion (backtacking)/head recursion:
*/
//Code:
#include<iostream>
using namespace std;

void name(int n)
{
    if(n==0)
    {
        return;
    }
    else
    {
        name(n-1);
        cout<<"saleha"<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    name(n);
}
/*
1. Read the value of n from the user.
2. Call the recursive function name(n).
3. If n == 0, stop recursion and return.
4. Otherwise, decrement n by 1 and call name(n-1).
5. Continue recursive calls until n becomes 0.
6. When the base case is reached, start returning from the recursive calls.
7. After each return, print "saleha".
8. Since printing occurs after the recursive call, the output is generated during backtracking.
9. "saleha" is printed exactly n times.

Counting:
- Number of recursive calls = n + 1
- Number of returns = n + 1
- Number of print statements = n
*/
//Time Complexity: O(n)
//Space Complexity:O(n)
