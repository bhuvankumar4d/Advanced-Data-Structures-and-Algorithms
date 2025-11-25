Multiple Sorting Algorithms in C (Quick Sort, Merge Sort, Heap Sort)
This program implements three major comparison-based sorting algorithms—Quick Sort, Merge Sort, and Heap Sort—and allows the user to choose which one to run on a given list of integers.

Features:
- Quick Sort using Lomuto partition scheme.
- Merge Sort using divide-and-conquer and temporary arrays.
- Heap Sort using max-heap construction.
- User can choose any sorting method.
- Prints sorted output after execution.

Functions Implemented:
partition(arr, low, high) – Lomuto partitioning for quicksort.
quickSort(arr, low, high) – recursive quicksort algorithm.
merge(arr, l, m, r) – merges two sorted halves for mergesort.
mergeSort(arr, l, r) – recursive mergesort algorithm.
heapify(arr, n, i) – enforces heap property at index i.
heapSort(arr, n) – builds max-heap and sorts by extraction.
printArray(arr, n) – displays array elements.
main() – takes input, chooses sorting algorithm, and prints output.

How It Works:
Quick Sort:
- Picks last element as pivot.
- Partitions array so smaller elements stay left.
- Recursively sorts left and right parts.

Merge Sort:
- Divides array into halves until size is one.
- Recursively merges sorted halves.
- Stable and predictable performance.

Heap Sort:
- Builds a max-heap from input.
- Repeatedly swaps max element with end and heapifies.
- Fully in-place, no extra memory needed.

Notes:
- All algorithms run in O(n log n) average/worst-case except quicksort worst-case O(n²).
- Restore performance: mergesort is stable, heapsort is not, quicksort is fastest in practice.
- Switching algorithms illustrates how different strategies solve sorting.

Why I Made This:
To understand and practice:
- Differences between multiple sorting algorithms.
- Divide-and-conquer strategies in quicksort and mergesort.
- Heap data structure and heapify operations.
- Building an interactive comparison tool for sorting methods in C.
