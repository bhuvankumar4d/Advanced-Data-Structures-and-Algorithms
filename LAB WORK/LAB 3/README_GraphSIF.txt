Graph Construction from Text Input in C
This program reads lines of text describing node interactions and builds a graph dynamically. It supports unlimited nodes, dynamic adjacency lists, and prints all relationships at the end.

Features:
- Dynamically adds nodes based on input text.
- Builds adjacency lists using growable arrays.
- Parses space‑separated relationships from each line.
- Outputs all nodes with their connected neighbors.
- Efficient memory handling with realloc and strdup.

Functions Implemented:
my_strdup(s) – duplicates a string using malloc and memcpy.
find_or_add(nodes, n_nodes, name) – returns index of a node, or creates it if missing.
add_edge(nodes, u, v) – appends neighbor v to node u’s adjacency list.
main() – reads text input, builds graph, and prints adjacency lists.

How It Works:
- Input format: each line starts with a source node, followed by an interaction token, followed by target nodes.
  Example: A interacts B C D
- For each word:
  * find_or_add() checks if node exists; otherwise creates it.
  * add_edge() stores the connection in the adjacency list.
- Uses dynamic resizing:
  * Adjacency list grows as needed using doubling capacity.
- After processing input, every node prints:
  name: neighbor1, neighbor2, ...

Notes:
- Works with arbitrary node names (strings).
- Uses strtok for tokenization of each line.
- Handles input from stdin or file if filename passed as argument.
- Frees all allocated memory before exiting.
- Useful for parsing biological interactions, social networks, dependency graphs, etc.

Why I Made This:
To understand and practice:
- Dynamic graph construction from unstructured text.
- String manipulation, tokenization, and memory allocation.
- Building adjacency lists manually using realloc.
- Processing graph-like relationships from real-world data.
