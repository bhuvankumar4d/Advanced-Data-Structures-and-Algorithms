Binary Search (Recursive and Iterative) in C
This program implements both recursive and iterative versions of the Binary Search algorithm, which efficiently searches for a key in a sorted array using the divide-and-conquer approach.

Features:
- Recursive binary search implementation.
- Iterative binary search implementation.
- Allows user to choose which method to use.
- Handles sorted input arrays of any size.
- Prints whether the key was found and at which index.

Functions Implemented:
recursiveBinarySearch(arr, low, high, key) – searches for the key using recursion.
iterativeBinarySearch(arr, n, key) – searches for the key using loops.
main() – takes input, chooses method, performs search, and prints the result.

How It Works:
- User enters a sorted array and a key to search.
- Recursive version:
  * Recursively splits the search interval based on mid.
  * Continues until key is found or interval becomes invalid.
- Iterative version:
  * Uses a loop to adjust low and high until key is found or exhausted.
- Both versions return the index of the key or –1 if not found.

Notes:
- Time complexity: O(log n) for both versions.
- Array must be sorted for binary search to work correctly.
- Recursive version uses call stack; iterative version uses simple loops.
- Program demonstrates core divide-and-conquer search logic.

Why I Made This:
To understand and practice:
- Recursive vs iterative problem-solving approaches.
- Efficient searching in sorted data.
- Divide-and-conquer algorithm design.
- Implementing user-driven algorithm selection in C.
