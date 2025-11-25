KMP and Rabin-Karp Pattern Matching Algorithms in C
This program implements two string searching algorithms—Knuth–Morris–Pratt (KMP) and Rabin–Karp—allowing efficient pattern matching inside a given text.

Features:
- KMP pattern matching with LPS preprocessing.
- Rabin–Karp hashing-based pattern matching.
- Reports all occurrences of the pattern in the text.
- Handles arbitrary input strings.

Functions Implemented:
computeLPSArray(pat, M, lps) – builds LPS (Longest Prefix Suffix) array for KMP.
KMP(pat, txt) – runs KMP pattern matching and prints all match positions.
RabinKarp(pat, txt) – runs Rabin–Karp using rolling hash to find matches.
main() – takes input, runs both algorithms, prints results.

How It Works:
KMP:
- Preprocesses the pattern into an LPS array.
- Avoids re-checking characters during mismatch.
- Uses two pointers: i for text, j for pattern.

Rabin–Karp:
- Computes hash of first window in text and pattern.
- Slides window across text using rolling hash.
- Verifies matches only when hashes match.

Notes:
- KMP runs in O(N + M) time.
- Rabin–Karp runs in O(N + M) average but O(NM) worst case.
- Uses modulo q = 101 and alphabet size d = 256.
- Program uses gets() for simplicity (unsafe in real programs).

Why I Made This:
To understand and practice:
- String pattern matching algorithms.
- LPS preprocessing logic in KMP.
- Rolling hash concept in Rabin–Karp.
- Comparing deterministic vs probabilistic search approaches.
