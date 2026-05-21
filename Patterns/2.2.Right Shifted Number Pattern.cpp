/*
Problem Statement
Print a right shifted number pattern where each row starts with spaces and numbers increase 
continuously in the row.

Example: n=4
1234
 234
  34
   4
*/
//Code:
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int i = 1;

    while(i <= n) {

        int spaces = i - 1;

        while(spaces >= 1) {
            cout << " ";
            spaces -= 1;
        }

        int j = n - i + 1;
        int k = i;

        while(j >= 1) {
            cout << k;
            k++;
            j -= 1;
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
4.Calculate spaces using spaces = i - 1.
5.Run first inner loop until spaces >= 1 to print leading spaces.
6.Decrement spaces after printing each space.
7.Initialize variable j = n - i + 1 to control number printing.
8.Initialize variable k = i as starting number for each row.
9.Run second inner loop until j >= 1.
10.Print value of k.
11.Increment k after printing each number.
12.Decrement j after each iteration.
13.After inner loop ends move to next line using cout << endl.
14.Increment i to move to next row.
15.Repeat the process until all rows are printed.
  */
//Time Complexity:-O(N²)
//Space Complexity:-O(1)
