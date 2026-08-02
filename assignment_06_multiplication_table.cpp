// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   ---------------------------
//   Multiplication Table for 2:
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printSingleTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << number << "  x  " << i << "  =  " << (number * i) << endl;
    }
}

void printTablesUpTo(int n) {
    for (int number = 1; number <= n; number++) {
        printSingleTable(number);
        if (number < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (number <= 0) {
        cout << "Error: Number must be a positive integer." << endl;
        return 0;
    }

    printSingleTable(number);

    cout << endl;

    int n;
    cout << "Enter N to print tables from 1 to N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    cout << endl;
    printTablesUpTo(n);

    return 0;
}
