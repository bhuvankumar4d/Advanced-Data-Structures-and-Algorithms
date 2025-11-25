Strassen’s Matrix Multiplication in C
This program implements Strassen’s algorithm, an optimized divide‑and‑conquer technique for matrix multiplication that reduces the usual O(n³) time toward O(n^2.81). It recursively splits matrices into quadrants and computes seven intermediate matrices (M1–M7) to construct the final product.

Features:
- Performs matrix multiplication using Strassen’s algorithm.
- Uses recursive calls and temporary matrices.
- Supports any power‑of‑two matrix size up to MAX = 64.
- Includes helper functions for matrix addition and subtraction.
- Prints final product matrix.

Functions Implemented:
add(A, B, C, ...) – adds two submatrices and stores in C.
sub(A, B, C, ...) – subtracts two submatrices and stores in C.
strassen(A, B, C, ...) – recursive Strassen multiplication algorithm.
printMatrix(A, n) – prints an n×n matrix.
main() – defines example 2×2 matrices and multiplies them with Strassen.

How It Works:
- Given two n×n matrices, Strassen divides them into four n/2×n/2 blocks.
- Computes seven products:
  * M1 = (A11 + A22)(B11 + B22)
  * M2 = (A21 + A22)B11
  * M3 = A11(B12 − B22)
  * M4 = A22(B21 − B11)
  * M5 = (A11 + A12)B22
  * M6 = (A21 − A11)(B11 + B12)
  * M7 = (A12 − A22)(B21 + B22)
- These are combined into the final four blocks of result matrix C.
- Base case: n = 1 → direct multiplication.

Notes:
- Works best for n as a power of 2; otherwise zero‑padding is required.
- Uses temporary matrices M1–M7 and T1–T2 for intermediate computations.
- Faster than classical multiplication for large matrices.
- Code provided here uses fixed MAX size for simplicity.

Why I Made This:
To understand and practice:
- Divide‑and‑conquer algorithms.
- Efficient matrix multiplication techniques.
- Recursive block matrix operations.
- Implementation details of Strassen’s O(n^2.81) algorithm in C.
