Prim’s Algorithm (Greedy MST) in C
This program implements Prim’s algorithm to find the Minimum Spanning Tree (MST) for a connected, weighted graph represented using an adjacency matrix.

Features:
- Greedy selection of the minimum-weight edge connecting visited and unvisited vertices.
- Tracks visited[] array to grow the MST step by step.
- Prints each selected edge and its cost.
- Computes the total minimum cost of the MST.

Functions Implemented:
main() – reads graph input, applies Prim’s algorithm, prints all MST edges and the final cost.

How It Works:
- User enters the number of vertices and the adjacency matrix.
- All 0 values are treated as no edge and converted to INT_MAX.
- The algorithm begins from vertex 0 (arbitrary starting point).
- At each step:
  * Search all edges from visited → unvisited vertices.
  * Select the smallest weight edge.
  * Add the chosen vertex to visited[].
  * Add the cost to the total MST cost.
- Stops after selecting n − 1 edges.

Notes:
- Time complexity: O(V²) using adjacency matrix scanning.
- Suitable for dense graphs.
- Always produces a minimum spanning tree if the graph is connected.
- Very similar to Dijkstra’s logic but for MST instead of shortest paths.

Why I Made This:
To understand and practice:
- Greedy algorithms for graph processing.
- Minimum spanning tree construction.
- Difference between Prim’s and Kruskal’s approaches.
- Weighted adjacency matrix handling in C.
