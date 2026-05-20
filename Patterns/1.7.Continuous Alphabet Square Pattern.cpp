/*
Problem Statement
Print a square pattern where alphabets are printed continuously in increasing order.

Example:
n=3
ABC
DEF
GHI

*/
//Code:
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int i = 1;
    char ch = 'A';

    while(i <= n) {

        int j = 1;

        while(j <= n) {

            cout << ch;
            j = j + 1;
            ch += 1;
        }

        cout << endl;
        i = i + 1;
    }

    return 0;
}

/*
Approach:-

1.Take input n from the user for the size of square pattern.
2.Initialize row variable i = 1.
3.Initialize character variable ch = 'A'.
4.Run outer while loop until i <= n.
5.Initialize column variable j = 1.
6.Run inner while loop until j <= n.
7.Print value of character ch.
8.Increment ch to move to next alphabet.
9.Increment j to move to next column.
10.After inner loop ends move to next line using cout << endl.
11.Increment i to move to next row.
12.Repeat the process until all rows are printed.
*/

//Time Complexity:-O(N²)
//Space Complexity:-O(1)
