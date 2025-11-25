Matrix Inversion
This program performs matrix inversion of a 3×3 matrix using the Gauss–Jordan elimination method and prints the resulting inverse matrix.

Features:
- Reads a 3×3 matrix from user input.
- Uses Gauss–Jordan elimination to convert the matrix into the identity matrix.
- Simultaneously transforms an identity matrix into the inverse.
- Prints the final inverse matrix in a formatted manner.

Functions Implemented:
printMatrix(float A[N][N]) – prints a 3×3 matrix with 3 decimal precision.
main() – reads input, performs Gauss–Jordan elimination, checks singularity, and prints the inverse.

How It Works:
- The matrix A is augmented with an identity matrix I.
- Each row is normalized by dividing by the diagonal element.
- Other rows are adjusted to make all off-diagonal elements zero.
- If any diagonal element becomes zero, the matrix is singular and inversion stops.
- After complete elimination, matrix I becomes the inverse of A.

Notes:
- Uses fixed size N = 3 for simplicity.
- Performs full elimination without partial pivoting.
- Prints matrix in floating-point format for readability.
- Reports if the input matrix is singular (non-invertible).

Why I Made This:
To understand and practice:
- Gauss–Jordan elimination.
- Matrix inversion fundamentals.
- Row operations and numerical stability.
- Implementing linear algebra techniques directly in C.
