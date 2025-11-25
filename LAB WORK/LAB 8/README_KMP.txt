KMP STRING SEARCHING ALGORITHM (C IMPLEMENTATION)

Overview:
This program implements the Knuth–Morris–Pratt (KMP) pattern searching algorithm,
which efficiently finds all occurrences of a pattern inside a given text.
KMP improves on brute force by avoiding unnecessary re-checking of characters.

Key Concepts:
1. LPS Array (Longest Prefix Suffix)
   - Preprocessed table for the pattern.
   - lps[i] = length of longest prefix of pattern that is also a suffix ending at index i.
   - Helps skip characters intelligently during mismatches.

2. Searching Phase
   - Text is scanned using two pointers:
       i -> index of text
       j -> index of pattern
   - Matches increase both pointers.
   - Mismatches use the LPS table to decide how much to shift without re-checking characters.
   - Outputs all indices where the full pattern is matched.

Input Format:
Two strings:
1. Text
2. Pattern

Example Input:
ababcabcabababd
ababd

Example Output:
Found at index 10

Meaning:
The pattern "ababd" occurs starting at position 10 in the text.

Time Complexity:
Preprocessing LPS: O(m)
Searching: O(n)
Total: O(n + m)

This makes KMP suitable for efficient pattern matching in large texts.

