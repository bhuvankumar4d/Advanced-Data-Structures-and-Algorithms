B-Tree Implementation in C (Order T = 3)
This program implements a B-Tree of minimum degree T = 3, supporting insertion, deletion, search, traversal, and node rebalancing operations through splitting, merging, and borrowing.

Features:
- Insert keys into a B-Tree with automatic node splitting.
- Delete keys using full B-Tree deletion algorithm.
- Search for keys inside any node level.
- Traverse the entire tree in sorted order.
- Full handling of underflow: merge, borrow from siblings, and fix children.
- Menu-driven interface for user interaction.

Functions Implemented:
createNode(leaf) – creates a new B-Tree node.
traverse(root) – prints all keys in sorted order.
search(root, k) – searches for a key in the tree.
splitChild(x, i, y) – splits a full child node during insertion.
insertNonFull(x, k) – inserts a key in a non-full node.
insert(root, k) – main insertion logic that handles root splitting.
getPred(x) – finds predecessor key.
getSucc(x) – finds successor key.
merge(x, idx) – merges two child nodes during deletion.
borrowFromPrev(x, idx) – borrows a key from left sibling.
borrowFromNext(x, idx) – borrows a key from right sibling.
fill(x, idx) – ensures children have enough keys during deletion.
removeFromNode(x, k) – removes a key from the subtree.
deleteKey(root, k) – top-level deletion function.
main() – menu for inserting, deleting, and traversing the B-Tree.

How It Works:
- A B-Tree keeps all leaves at the same level and maintains sorted keys in each node.
- Insertion:
  * If root is full, a new root is created and old root is split.
  * Keys propagate down to correct child node.
- Deletion:
  * Handles all complex cases—leaf deletion, internal deletion, predecessor/successor replacement, merging, and borrowing.
  * Ensures nodes always maintain at least T–1 keys.
- Traversal prints all keys in ascending order.

Notes:
- Minimum degree T = 3 → max keys = 2T–1 = 5.
- Balanced M-way search tree ensures O(log n) complexity.
- Fully robust deletion algorithm (most complex part of B-Trees).
- Can store large datasets with fewer disk reads in real applications.

Why I Made This:
To understand and practice:
- Multi-way trees and advanced search tree structures.
- Complex operations like splitting, merging, borrowing.
- Efficient indexing structures used in databases and filesystems.
- Full B-Tree insertion and deletion logic.
