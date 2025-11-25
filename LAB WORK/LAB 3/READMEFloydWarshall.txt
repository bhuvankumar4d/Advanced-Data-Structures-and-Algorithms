Floyd–Warshall Algorithm in C
This program implements the Floyd–Warshall algorithm, a dynamic programming technique used to compute the shortest paths between all pairs of vertices in a weighted graph.

Features:
- Computes shortest distances between every pair of vertices.
- Supports large weights using INF.
- Dynamic programming refinement of shortest paths.
- Prints final distance matrix.

Functions Implemented:
printSolution(int dist[V][V]) – prints the final shortest-path matrix.
floydWarshall(int graph[V][V]) – runs the Floyd–Warshall algorithm, updates distances, and prints results.
main() – defines a sample graph and executes the algorithm.

How It Works:
- Initializes distance matrix using the given graph.
- Iteratively checks if an intermediate vertex k offers a shorter path from i to j.
- Updates dist[i][j] when a better path is found.
- After all iterations, the matrix contains shortest distances between all pairs.

Notes:
- Time complexity: O(V^3).
- Handles negative edges but not negative cycles.
- INF means no direct path between vertices.
- Good for dense graphs and all-pairs shortest path computations.

Why I Made This:
To understand and practice:
- Dynamic programming on graphs.
- All-pairs shortest path algorithms.
- Efficient path computation techniques used in routing and network systems.
