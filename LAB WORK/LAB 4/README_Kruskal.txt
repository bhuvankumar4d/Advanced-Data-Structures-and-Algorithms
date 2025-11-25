Kruskal’s Algorithm (Union–Find Based) in C
This program implements Kruskal’s Minimum Spanning Tree (MST) algorithm using the Union–Find (Disjoint Set Union) data structure. The graph is given as an adjacency matrix, and the program finds the MST by repeatedly selecting the lowest-cost edge that does not form a cycle.

Features:
- Uses Union–Find (Disjoint Set Union) for cycle detection.
- Selects minimum-weight edges one by one.
- Builds and prints the MST step-by-step.
- Calculates total cost of the MST.
- Works directly with an adjacency matrix input.

Functions Implemented:
find(i) – finds the representative (root) of vertex i using parent[].
union_sets(i, j) – merges two sets by connecting their roots.
main() – reads graph, applies Kruskal’s algorithm, prints edges and final cost.

How It Works:
- User enters number of vertices and adjacency matrix.
- All zero entries are treated as no edge and replaced with 9999 (infinity).
- Each vertex is initially its own parent in the DSU.
- Algorithm repeatedly:
  * Finds the smallest cost edge.
  * Checks if its endpoints belong to different sets using find().
  * If yes, includes the edge in MST and merges the sets.
- Stops after selecting exactly n − 1 edges.

Notes:
- Time complexity: O(V²) due to adjacency matrix scanning.
- Union–Find provides efficient cycle detection.
- Prints each selected MST edge in order of increasing cost.
- Uses 1-based vertex labels in output for clarity.

Why I Made This:
To understand and practice:
- Minimum spanning tree algorithms.
- Union–Find (DSU) operations for cycle detection.
- Greedy algorithm design.
- Working with weighted graphs in adjacency matrix form.
