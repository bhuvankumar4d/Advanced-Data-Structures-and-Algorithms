LU Decomposition in C

This program performs LU Decomposition of a 4×4 matrix using the Doolittle method (where L has 1s on the diagonal).

FEATURES
--------
- Accepts a 4×4 matrix from the user.
- Computes:
  - L (Lower Triangular Matrix) with diagonal elements = 1.
  - U (Upper Triangular Matrix).
- Displays the resulting matrices.

HOW IT WORKS
------------
LU decomposition splits matrix A into:

A = L × U

Steps Performed:
1. Compute U using:
   U[i][k] = A[i][k] - Σ(L[i][j] * U[j][k])

2. Compute L:
   - L diagonal = 1
   - L[k][i] = (A[k][i] - Σ(L[k][j] * U[j][i])) / U[i][i]

3. Prints L and U matrices.

Enter the 4×4 matrix elements when prompted.

FILE INFORMATION
----------------
- Language: C
- Concept: Numerical Methods — LU Decomposition
