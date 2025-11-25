Heap Sort in C
=================

Overview
--------
This program implements **Heap Sort**, a comparison-based sorting algorithm
that uses a **Binary Heap** (Max-Heap) to sort an array in ascending order.

Heap Sort consists of two main stages:
1. Build a max-heap from the input array.
2. Repeatedly remove the maximum element and place it at the end of the array.

Files
-----
- `heapsort.c` — Contains the complete implementation.

Functions
---------

### 1. swap(arr, i, j)
Swaps two elements in the array at positions `i` and `j`.

### 2. heapify(arr, n, i)
Ensures the subtree rooted at index `i` follows the **max-heap** property.
- `n` → size of heap.
- Compares node with left & right children.
- Swaps if child is larger and recursively fixes the subtree.

### 3. heapSort(arr, n)
Performs Heap Sort:
- Builds a max-heap.
- Swaps the root (largest element) with the last element.
- Reduces heap size and heapifies again.

### 4. printArray(arr, n)
Prints array elements.

### 5. main()
- Reads array size `n`.
- Inputs `n` values from user.
- Displays original and sorted arrays.
- Calls `heapSort()` to sort.

Sample Input
------------
Enter number of elements:
```
5
```
Enter values:
```
9 4 7 1 3
```

Sample Output
-------------
Original array:
```
9 4 7 1 3
```
Sorted array:
```
1 3 4 7 9
```

Notes
-----
- Uses max-heap logic.
- Time Complexity: O(n log n)
- Space Complexity: O(1)
