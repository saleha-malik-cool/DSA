/*
Problem Statement
Print a square pattern where each row contains the same alphabet character.
Example: n=4
AAAA
BBBB
CCCC
DDDD
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
        while(j <=n) {
            char ch = 'A'+i-1;
            cout<<ch;
            j = j+1;
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
3.Run outer while loop until i <= n.
4.Initialize column variable j = 1.
5.Run inner while loop until j <= n.
6.Calculate character using 'A' + i - 1.
7.Print the character ch.
8.Increment j to move to next column.
9.After inner loop ends move to next line using cout << endl.
10.Increment i to move to next row.
11.Repeat the process until all rows are printed.
*/

//Time Complexity:-O(N²)
//Space Complexity:-O(1)

