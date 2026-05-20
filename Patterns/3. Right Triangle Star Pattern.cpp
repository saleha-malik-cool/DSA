/*
Problem Statement
Print a right triangle star pattern where the number of stars in each row is equal to the row number.

Example: (n=4)
*
**
***
****

*/
//Code:
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int i = 1;

    while(i <= n) {

        int j = i;

        while(j >= 1) {
            cout << "*";
            j = j - 1;
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
4.Initialize column variable j = i.
5.Run inner while loop until j >= 1.
6.Print "*" inside inner loop.
7.Decrement j after printing each star.
8.After inner loop ends move to next line using cout << endl.
9.Increment i to move to next row.
10.Repeat the process until all rows are printed.
*/
//Time Complexity:-O(N²)
//Space Complexity:-O(1)
