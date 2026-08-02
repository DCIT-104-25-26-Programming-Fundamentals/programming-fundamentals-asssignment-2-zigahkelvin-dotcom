// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_DIM = 10;

void readMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols,
                      int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[MAX_DIM][MAX_DIM], int b[MAX_DIM][MAX_DIM],
                  int rows, int cols, int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_DIM][MAX_DIM], int b[MAX_DIM][MAX_DIM],
                       int m, int n, int p, int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void runTranspose() {
    int matrix[MAX_DIM][MAX_DIM];
    int result[MAX_DIM][MAX_DIM];
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols);
    transposeMatrix(matrix, rows, cols, result);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows);
}

void runAddition() {
    int a[MAX_DIM][MAX_DIM], b[MAX_DIM][MAX_DIM], result[MAX_DIM][MAX_DIM];
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(a, rows, cols);

    cout << "\nEnter Matrix B:" << endl;
    readMatrix(b, rows, cols);

    addMatrices(a, b, rows, cols, result);

    cout << "\nSum of Matrices:" << endl;
    printMatrix(result, rows, cols);
}

void runMultiplication() {
    int a[MAX_DIM][MAX_DIM], b[MAX_DIM][MAX_DIM], result[MAX_DIM][MAX_DIM];
    int m, n, n2, p;

    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A (N): ";
    cin >> n;

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(a, m, n);

    cout << "\nEnter rows of Matrix B (must equal N = " << n << "): ";
    cin >> n2;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;

    if (n2 != n) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return;
    }

    cout << "\nEnter Matrix B:" << endl;
    readMatrix(b, n2, p);

    multiplyMatrices(a, b, m, n, p, result);

    cout << "\nProduct of Matrices (A x B):" << endl;
    printMatrix(result, m, p);
}

int main() {
    int choice;

    cout << "Matrix Operations" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Choose an operation (1-3): ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            runTranspose();
            break;
        case 2:
            runAddition();
            break;
        case 3:
            runMultiplication();
            break;
        default:
            cout << "Error: Invalid choice." << endl;
    }

    return 0;
}
