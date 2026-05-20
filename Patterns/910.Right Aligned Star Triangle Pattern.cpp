/*
Problem Statement
Print a right aligned triangle pattern using stars (*).

Example: n=4
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

        int space = n - i;

        while(space >= 1) {
            cout << " ";
            space -= 1;
        }

        int j = 1;

        while(j <= i) {
            cout << "*";
            j += 1;
        }

        cout << endl;
        i += 1;
    }

    return 0;
}
/*
1.Take input n from the user for the number of rows.
2.Initialize row variable i = 1.
3.Run outer while loop until i <= n.
4.Calculate number of spaces using space = n - i.
5.Run first inner loop to print spaces.
6.Decrement space after printing each space.
7.Initialize star variable j = 1.
8.Run second inner loop until j <= i.
9.Print "*" in each iteration.
10.Increment j after printing each star.
11.After printing stars move to next line using cout << endl.
12.Increment i to move to next row.
13.Repeat the process until all rows are printed.
*/
//Time Complexity:-O(N²)
//Space Complexity:-O(1)
