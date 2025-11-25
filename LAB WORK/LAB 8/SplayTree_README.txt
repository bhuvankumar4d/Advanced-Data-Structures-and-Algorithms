Splay Tree Implementation in C
================================

Overview
--------
This program implements a **Splay Tree**, a self-adjusting binary search tree.  
Whenever you insert, delete, or search a key, the accessed node is brought to the **root** using rotations.  
This helps frequently accessed elements get faster over time.

Features
--------
- Insert a key
- Delete a key
- Search for a key
- Inorder traversal (sorted output)
- Splaying after each operation
- Menu-driven UI for user interaction

How It Works
------------
1. **Splaying**  
   The core of the structure.  
   The tree rotates nodes such that the searched/inserted/deleted key becomes the root.

2. **Rotations**
   - Right rotation (Zig)
   - Left rotation (Zag)
   - Zig-Zig, Zig-Zag, Zag-Zig, Zag-Zag cases handled automatically inside splay().

3. **Insert**
   - Splay the key.
   - If key exists, nothing changes.
   - Else insert new node and adjust children.

4. **Delete**
   - Splay the key to root.
   - Remove it.
   - Rebuild tree by splaying max of left subtree.

5. **Search**
   - Splays the found node to root.
   - If not found, closest node is splayed to root.

Menu Options
------------
1 — Insert  
2 — Delete  
3 — Search  
4 — Inorder Traversal  
5 — Exit

Input Example
-------------
1 50  
1 30  
1 20  
1 40  
1 60  
4  
3 40  
2 30  
4  
5  

Compilation
-----------
Use:
    gcc splaytrees.c -o splaytrees

Run:
    ./splaytrees

Notes
-----
- Designed for ADSA lab use.
- No extra libraries required.
- Works on GCC/MinGW.

