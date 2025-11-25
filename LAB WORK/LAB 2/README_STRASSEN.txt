Strassen Matrix Multiplication in C

This program implements Strassen’s Algorithm for fast matrix multiplication.  
It multiplies two n×n matrices (where n is a power of 2) using 7 recursive multiplications instead of 8.

FEATURES
--------
- Implements Strassen’s Divide-and-Conquer method
- Works for matrices up to 64×64 (MAX = 64)
- Uses helper functions:
  - add()  -> matrix addition
  - sub()  -> matrix subtraction
  - strassen() -> recursive Strassen multiplication
- Prints the resulting matrix

HOW STRASSEN WORKS
------------------
Given matrices A and B, split them into 4 submatrices:

A = | A11 A12 |
    | A21 A22 |

B = | B11 B12 |
    | B21 B22 |

Strassen computes 7 matrix products:

M1 = (A11 + A22)(B11 + B22)
M2 = (A21 + A22) B11
M3 = A11 (B12 - B22)
M4 = A22 (B21 - B11)
M5 = (A11 + A12) B22
M6 = (A21 - A11)(B11 + B12)
M7 = (A12 - A22)(B21 + B22)

Final results:

C11 = M1 + M4 - M5 + M7
C12 = M3 + M5
C21 = M2 + M4
C22 = M1 - M2 + M3 + M6

Example matrices used in code:
A = [[1,2],[3,4]]
B = [[5,6],[7,8]]

Output:
19 22
43 50

NOTES
-----
- n must be a power of 2 (2, 4, 8…)
- Uses static 64×64 arrays
- Demonstrates divide-and-conquer optimization
