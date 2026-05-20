/*
Question:- Print a square pattern of size n × n where numbers are printed continuously in increasing order.
Example:(n=4)
1234
5678
9101112
13141516
*/
//Code:-
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int i = 1;
    int count = 1;

    while(i <= n) {

        int j = 1;

        while(j <= n) {
            cout << count;
            count = count + 1;
            j = j + 1;
        }

        cout << endl;
        i = i + 1;
    }

    return 0;
}
/*
Approach:
1.Take input n from the user for the size of pattern.
2.Initialize row variable i = 1.
3.Initialize variable count = 1 to store the current number.
4.Run outer while loop until i <= n for rows.
5.Inside outer loop initialize column variable j = 1.
6.Run inner while loop until j <= n.
7.Print value of count.
8.Increment count after printing each number.
9.Increment j to move to next column.
10.After inner loop ends move to next line using cout << endl.
11.Increment i to move to next row.
12.Repeat the process until all rows are printed.
*/
//Time Complexity: O(N²)
//Space Complexity: O(1)
