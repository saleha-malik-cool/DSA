/*
Question:
Print a triangle pattern where numbers are printed continuously in increasing order.
Example:(N=4)
1
23
456
78910
*/

//Code:
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int i = 1;
    int count = 1;

    while(i <= n) {

        int j = 1;

        while(j <= i) {
            cout << count;
            count += 1;
            j = j + 1;
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
3.Initialize variable count = 1 to store the current number.
4.Run outer while loop until i <= n.
5.Initialize column variable j = 1.
6.Run inner while loop until j <= i.
7.Print value of count.
8.Increment count after printing each number.
9.Increment j to move to next column.
10.After inner loop ends move to next line using cout << endl.
11.Increment i to move to next row.
12.Repeat the process until all rows are printed.
*/

//Time Complexity:O(N²)
//Space Complexity:O(1)
