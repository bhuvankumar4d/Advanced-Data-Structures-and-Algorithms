Simplex Method for Linear Programming in C

This program implements the Simplex Method to solve Linear Programming (LP) maximization problems of the form:

Maximize: Z = c1*x1 + c2*x2 + ... + cn*xn

Subject to constraints:
a11*x1 + a12*x2 + ... + a1n*xn <= b1
a21*x1 + a22*x2 + ... + a2n*xn <= b2
...
am1*x1 + am2*x2 + ... + amn*xn <= bm
xi >= 0

Overview:
- Adds slack variables to convert inequalities to equalities
- Builds the Simplex tableau
- Repeatedly selects pivot column (entering variable) and pivot row (leaving variable)
- Performs pivot operations (Gauss–Jordan elimination)
- Stops when all values in the Z-row are >= 0, indicating the optimal solution has been reached

Algorithm Used:
- Slack variable introduction
- Minimum positive ratio test for pivot row selection
- Most negative Z-row coefficient for pivot column selection
- Iterative tableau updates until optimality

Input Format (Example):
Enter number of variables: 2
Enter number of constraints: 2
Enter coefficients of objective function:
3 5
Constraint 1 coefficients:
2 1
RHS: 100
Constraint 2 coefficients:
1 3
RHS: 90

This represents:
Maximize Z = 3x1 + 5x2
Subject to:
2x1 + x2 <= 100
x1 + 3x2 <= 90
x1, x2 >= 0

Example Output:
Current Simplex Table:
--------------------------------------------------
   2.00   1.00   1.00   0.00  100.00
   1.00   3.00   0.00   1.00   90.00
  -3.00  -5.00   0.00   0.00    0.00
--------------------------------------------------
...
Optimal solution found:
x1 = 42.00
x2 = 16.00
Maximum Z = 206.00

Meaning of Output:
x1 = 42 and x2 = 16 give the maximum possible value Z = 206 under the given constraints.
