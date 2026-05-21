/*
Problem Statement
Print a pyramid number pattern with leading spaces.

Example: n=4
   1
  121
 12312
1234123
*/
//Code:
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int i = 1;

    while(i <= n) {

        int spaces = 1;

        while(spaces <= n - i) {
            cout << " ";
            spaces += 1;
        }

        int j = 1;

        while(j <= i) {
            cout << j;
            j += 1;
        }

        int k = 1;

        while(k <= i - 1) {
            cout << k;
            k++;
        }

        cout << endl;
        i += 1;
    }

    return 0;
}
/*
Approach:-

1.Take input n from the user for the number of rows.
2.Initialize row variable i = 1.
3.Run outer while loop until i <= n.
4.Initialize variable spaces = 1.
5.Run first inner loop until spaces <= n - i to print leading spaces.
6.Increment spaces after printing each space.
7.Initialize variable j = 1.
8.Run second inner loop until j <= i.
9.Print value of j.
10.Increment j after printing each number.
11.Initialize variable k = 1.
12.Run third inner loop until k <= i - 1.
13.Print value of k.
14.Increment k after printing each number.
15.After all loops end move to next line using cout << endl.
16.Increment i to move to next row.
17.Repeat the process until all rows are printed.
*/

//Time Complexity:-O(N²)
//Space Complexity:-O(1)
