/*
Problem Statement
Print a symmetric pattern where numbers decrease from both sides and stars (*) appear in the middle.
Example:- n=4
12344321
123**321
12****21
1******1
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

        while(j <= n - i + 1) {
            cout << j;
            j++;
        }

        int stars = 1;

        while(stars <= (i - 1) * 2) {
            cout << "*";
            stars += 1;
        }

        int k = n - i + 1;

        while(k >= 1) {
            cout << k;
            k--;
        }

        cout << endl;
        i += 1;
    }
}

/*
Approach:-

1.Take input n from the user for the number of rows.
2.Initialize row variable i = 1.
3.Run outer while loop until i <= n.
4.Initialize variable j = 1.
5.Run first inner loop until j <= n - i + 1.
6.Print value of j.
7.Increment j after printing each number.
8.Initialize variable stars = 1.
9.Run second inner loop until stars <= (i - 1) * 2.
10.Print "*" in each iteration.
11.Increment stars after printing each star.
12.Initialize variable k = n - i + 1.
13.Run third inner loop until k >= 1.
14.Print value of k.
15.Decrement k after printing each number.
16.After all loops end move to next line using cout << endl.
17.Increment i to move to next row.
18.Repeat the process until all rows are printed.
*/
//Time Complexity:-O(N²)
//Space Complexity:-O(1)
