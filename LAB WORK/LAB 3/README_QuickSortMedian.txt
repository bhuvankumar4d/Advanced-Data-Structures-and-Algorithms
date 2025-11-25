Quicksort Using Median-of-Three Pivot in C
This program implements the Quicksort algorithm using the median-of-three pivot selection technique to improve performance and reduce worst-case behavior on partially sorted data.

Features:
- Uses median-of-three (low, mid, high) to choose a better pivot.
- Partitioning logic ensures efficient in-place sorting.
- Recursively sorts left and right partitions.
- Accepts user input and prints sorted output.

Functions Implemented:
swap(arr, i, j) – swaps two elements in the array.
medianOfThree(arr, low, high) – selects pivot as the median of arr[low], arr[mid], arr[high].
partition(arr, low, high) – partitions array around pivot.
quickSort(arr, low, high) – recursive quicksort algorithm.
printArray(arr, n) – prints all array elements.
main() – reads input, calls quicksort, and prints the sorted array.

How It Works:
- Median-of-three chooses the pivot more intelligently:
  * Sorts low, mid, high elements.
  * Places the median at arr[high] to use as pivot.
- Partition function rearranges elements ≤ pivot to the left and > pivot to the right.
- Quicksort recursively processes each partition until the array is fully sorted.

Notes:
- Time complexity:
  * Average case: O(n log n)
  * Worst case (greatly reduced by median-of-three)
- In-place sorting: no extra arrays required.
- Works well on random and partially sorted inputs.
- Median-of-three significantly improves pivot stability.

Why I Made This:
To understand and practice:
- Efficient quicksort optimizations.
- Median-of-three pivoting strategy.
- Recursive divide-and-conquer algorithms.
- Clean and efficient in-place sorting techniques.
