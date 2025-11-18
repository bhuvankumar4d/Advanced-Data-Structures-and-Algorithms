Interior Point Method for Linear Programming in C

This program implements the Primal–Dual Interior Point Method to solve Linear Programming (LP) minimization problems of the form:

Minimize:
Z = c1*x1 + c2*x2 + ... + cn*xn

Subject to:
Ax = b
xi >= 0

Overview:
- Uses primal–dual interior point algorithm
- Computes primal residual, dual residual, duality gap
- Newton direction computed from normal equations
- Iteratively updates x, y, s until convergence

Input Example:
n = 3
m = 2
c = 3 1 2
A =
1 1 1
2 1 0
b = 4 3

Example Output:
x = 0.0000 3.0000 1.0000
Optimal Objective Value = 5.0000
