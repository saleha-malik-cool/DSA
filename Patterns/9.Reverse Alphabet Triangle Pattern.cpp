/*
Problem Statement
Print a triangle pattern where each row starts from decreasing alphabets and characters increase in each row
Example: n=4
D
CD
BCD
ABCD
*/

//Code:
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int i = 1;

    while(i <= n) {

        int j = 1;
        char ch = 'A' + n - i;

        while(j <= i) {

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

1.Take input n from the user for the number of rows.
2.Initialize row variable i = 1.
3.Run outer while loop until i <= n.
4.Initialize column variable j = 1.
5.Initialize character variable ch = 'A' + n - i.
6.Run inner while loop until j <= i.
7.Print value of character ch.
8.Increment ch to move to next alphabet.
9.Increment j to move to next column.
10.After inner loop ends move to next line using cout << endl.
11.Increment i to move to next row.
12.Repeat the process until all rows are printed.

*/
//Time Complexity:-O(N²)
//Space Complexity:-O(1)
