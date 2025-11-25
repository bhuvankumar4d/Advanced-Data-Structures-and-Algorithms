Dijkstra’s Algorithm in C
This program implements Dijkstra’s Single Source Shortest Path (SSSP) algorithm on a weighted graph represented as an adjacency matrix. It computes the shortest distance from a given source node to every other vertex.

Features:
- Computes shortest paths from a single source vertex.
- Uses a greedy approach to pick the nearest unvisited vertex.
- Supports weighted graphs with non-negative edge weights.
- Prints the final shortest distances in a clean format.

Functions Implemented:
minDistance(dist, sptSet) – finds the unvisited vertex with the minimum distance.
printSolution(dist, src) – prints all vertex distances from the source.
dijkstra(graph, src) – performs Dijkstra’s algorithm using adjacency matrix representation.
main() – defines a sample graph and calls Dijkstra from source 0.

How It Works:
- dist[] array stores shortest known distances.
- sptSet[] marks vertices already processed.
- Each step:
  * Pick vertex u with minimum distance.
  * Relax all edges from u to update distances.
- Repeats for V−1 iterations.
- Finally prints shortest distances from the source.

Notes:
- Time complexity: O(V^2) using adjacency matrix.
- Requires non‑negative edge weights (Dijkstra’s requirement).
- Graph size fixed at V = 6.
- Can be extended using min‑heap for faster O(E log V) implementation.

Why I Made This:
To understand and practice:
- Greedy algorithms.
- Shortest path computation in weighted graphs.
- Relaxation technique in graph algorithms.
- Implementing Dijkstra using simple arrays in C.
