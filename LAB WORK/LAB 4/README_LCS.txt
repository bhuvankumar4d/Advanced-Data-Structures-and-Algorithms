Longest Common Subsequence (LCS) Algorithms in C
This program computes the Longest Common Subsequence (LCS) of two strings using dynamic programming. It also prints **all possible common subsequences**, the actual LCS string, and the final LCS length.

Features:
- Computes LCS length using DP table.
- Prints the actual LCS string by backtracking.
- Recursively prints all common subsequences.
- Works with string lengths up to MAX = 100.

Functions Implemented:
max(a, b) – returns the larger of two integers.
LCSLength(X, Y, m, n) – builds a DP table to compute LCS length.
printAllCommon(X, Y, m, n, res, index) – recursively prints all common subsequences.
printLCS(X, Y, m, n) – reconstructs and prints one longest common subsequence.
main() – reads input strings and calls all helper functions.

How It Works:
- A DP matrix L[i][j] is built such that:
  * L[i][j] = 0 when i = 0 or j = 0
  * L[i][j] = L[i-1][j-1] + 1 when characters match
  * Otherwise max(L[i-1][j], L[i][j-1])
- LCS reconstruction:
  * Start at L[m][n] and backtrack through the matrix.
- All subsequences:
  * Uses recursion to explore both branches whenever characters differ.
  * Prints subsequences when either string length hits zero.

Notes:
- Time complexity for LCS length: O(m × n).
- printAllCommon() may print duplicates because it explores all recursion paths.
- LCS is different from substring; characters need not be contiguous.
- Useful for bioinformatics, text diff tools, and sequence comparison.

Why I Made This:
To understand and practice:
- Dynamic programming matrix construction.
- LCS backtracking logic.
- Recursive enumeration of subsequences.
- String comparison algorithms commonly used in CS and bioinformatics.
