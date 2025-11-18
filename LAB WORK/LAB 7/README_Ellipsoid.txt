Ellipsoid Method for Linear Programming in C

This program implements the Ellipsoid Algorithm to solve Linear Programming (LP) maximization problems of the form:

Maximize:
Z = c1*x1 + c2*x2 + ... + cn*xn

Subject to constraints:
a11*x1 + a12*x2 + ... + a1n*xn <= b1
a21*x1 + a22*x2 + ... + a2n*xn <= b2
...
am1*x1 + am2*x2 + ... + amn*xn <= bm

xi >= 0 (non-negativity added manually if needed)

Overview:
- The ellipsoid algorithm checks whether a point satisfies all constraints.
- If a constraint is violated, it creates a cutting plane and shrinks the ellipsoid.
- Repeated shrinking eventually identifies a feasible point.
- Maximization is done using binary search on the objective value:
  - Convert objective constraint to –c^T x <= –t
  - Check feasibility repeatedly using ellipsoid cuts.

Algorithm Used:
- Initialize a large ellipsoid (center and matrix)
- Detect the most violated constraint
- Normalize the constraint and generate a cut
- Update the ellipsoid center and matrix
- Repeat until all constraints are satisfied
- For maximization, binary search is applied on Z

Input Format (Example):
2 4
1 2
4 2
-1 0
0 -1
4
12
0
0
1 1

Example Output:
Optimal value: 3.333333
x: 2.666667 0.666667

Meaning of Output:
The maximum Z value is 3.333333.
x1 = 2.666667 and x2 = 0.666667 give the optimal value.
If no feasible solution exists, the output will be:
Infeasible or failed
