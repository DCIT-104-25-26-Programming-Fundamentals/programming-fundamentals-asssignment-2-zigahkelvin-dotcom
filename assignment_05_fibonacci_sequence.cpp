// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacciTerms(int n) {
    long long previous = 0, current = 1;

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << previous;
        if (i < n - 1) {
            cout << " ";
        }
        long long next = previous + current;
        previous = current;
        current = next;
    }
    cout << endl;
}

bool isFibonacciNumber(int target) {
    if (target < 0) {
        return false;
    }

    long long previous = 0, current = 1;

    if (target == 0) {
        return true;
    }

    while (previous <= target) {
        if (previous == target) {
            return true;
        }
        long long next = previous + current;
        previous = current;
        current = next;
    }

    return false;
}

int main() {
    int n;

    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
    } else {
        printFibonacciTerms(n);
    }

    cout << endl;

    int target;
    cout << "Enter a number to check: ";
    cin >> target;

    if (isFibonacciNumber(target)) {
        cout << target << " is a Fibonacci number." << endl;
    } else {
        cout << target << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
