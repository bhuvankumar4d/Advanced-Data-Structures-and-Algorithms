# Graph Matching in C

This program implements maximum bipartite matching using a DFS-based augmenting path algorithm in C.

🔹 Overview

The program reads:
1. Number of vertices in set **U** and set **V**
2. An adjacency matrix representing edges between **U** and **V**

It then finds the **maximum matching** — the largest possible set of vertex pairs `(u, v)` where:
- Each vertex from `U` is connected to one from `V`
- No two pairs share a vertex

🧠 Algorithm Used

The algorithm uses a **Depth-First Search (DFS)** based approach:
- Tries to find an augmenting path for each vertex `u` in `U`.
- Uses a `matchR[]` array to track which vertex in `V` is matched to which `U`.
- Uses a `seen[]` array to avoid revisiting vertices in `V` during one DFS.

This is a standard approach for **maximum bipartite matching**, similar to the **Hungarian algorithm’s** basic version.

⚙️ Input Format

Enter number of vertices in U and V: 4 4
Enter adjacency matrix (4 x 4):
0 1 1 0
1 0 0 1
0 0 1 0
1 0 0 0

## 🧾 Example Output

```
Maximum Matching is 4
Matched pairs (U->V):
U3 -> V0
U0 -> V1
U2 -> V2
U1 -> V3