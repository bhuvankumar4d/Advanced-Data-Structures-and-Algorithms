Fibonacci Heap Implementation in C
================================

Overview
--------
This program implements a Fibonacci Heap, an advanced priority queue data structure that supports efficient insert, extract-min, decrease-key, and delete operations. It maintains a collection of min-heap ordered trees connected in a circular doubly linked list and uses lazy structural updates and cascading cuts to achieve excellent amortized performance.

Features
--------
- Insert a key
- Find minimum
- Extract minimum
- Decrease key
- Delete key
- Display root list
- Menu-driven interface

How It Works
------------
1. Root List
   All trees exist in a circular doubly linked list. `mini` holds a pointer to the current minimum root.

2. Insert
   - Creates a new node as a single-node tree
   - Adds it to the root list
   - Updates minimum if needed
   - O(1) amortized

3. Extract Min
   - Removes the global minimum
   - Moves all its children to the root list
   - Performs consolidation to merge trees of same degree
   - O(log n) amortized

4. Consolidation
   Ensures no two trees in the root list have the same degree.
   - Uses an array A[] indexed by degree
   - Repeatedly links trees with same degree
   - Rebuilds root list
   - Updates the minimum pointer

5. Decrease Key
   If a decreased key violates heap order:
   - The node is cut from its parent
   - Moved to the root list
   - Cascading cuts may occur up the tree
   - O(1) amortized

6. Delete Key
   - Decrease key to negative infinity
   - Extract the new minimum
   - Removes the node effectively

Menu Options
------------
1 — Insert
2 — Find Min
3 — Extract Min
4 — Decrease Key
5 — Delete Key
6 — Display Roots
7 — Exit

Input Example
-------------
1 10
1 3
1 15
1 6
2
3
4 15 4
5 10
6
7

Compilation
-----------
Use:
    gcc fibonacciheap.c -lm -o fibheap

Run:
    ./fibheap

Notes
-----
- The program uses recursive search (find_node) to locate keys.
- Recursive search is O(n) and may be fragile for large heaps.
- For robustness, using handle IDs is recommended.
- Works with GCC/MinGW.
- Designed for ADSA/DS lab usage.
