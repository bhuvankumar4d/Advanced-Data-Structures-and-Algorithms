LU Decomposition in C
=======================

Overview
--------
This program performs **LU Decomposition** of a 4×4 matrix A into:
- **L** → Lower triangular matrix (unit diagonal)
- **U** → Upper triangular matrix

It then solves the linear system:

    A * x = b

using:
1. **Forward Substitution** → Solve L * y = b  
2. **Backward Substitution** → Solve U * x = y  

This produces the final solution vector **x**.

Matrix Size
-----------
The program is fixed to **N = 4** for simplicity.

Files
-----
- `ludecomposition.c` — complete implementation

Functions
---------

### 1. luDecomposition(A, L, U)
- Computes matrices L and U such that:
      A = L × U
- For each pivot row `i`, it:
  - Computes U’s row (i to N-1)
  - Computes L’s column (i to N-1)

### 2. forwardSubstitution(L, b, y)
Solves lower triangular system:

    L * y = b

### 3. backwardSubstitution(U, y, x)
Solves upper triangular system:

    U * x = y

### 4. main()
- Takes matrix A (4×4) and vector b (4×1) as input.
- Computes L and U.
- Displays both matrices.
- Computes y using L.
- Computes final solution x using U.

Input Format
------------
Matrix A (4×4):
Example:
```
1 2 3 4
2 5 3 1
1 2 1 3
4 1 2 2
```

Vector b:
```
10 8 7 6
```

Output Format
-------------
- L matrix  
- U matrix  
- Solution vector x  

Example (Format Only):
```
L matrix:
1.0000 0.0000 0.0000 0.0000
0.5000 1.0000 0.0000 0.0000
...

U matrix:
2.0000 3.0000 1.0000 4.0000
0.0000 1.5000 2.0000 1.0000
...

Solution vector x:
x[0] = ...
x[1] = ...
x[2] = ...
x[3] = ...