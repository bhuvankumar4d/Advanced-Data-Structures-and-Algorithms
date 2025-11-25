Binary Search Tree (BST) Implementation in C
This program implements a Binary Search Tree with insertion, deletion, and traversal operations, along with a menu-driven interface for user interaction.

Features:
- Insert nodes into the BST.
- Delete nodes while maintaining BST structure.
- Supports inorder, preorder, and postorder traversals.
- Menu-driven interface with continuous operation.
- Implements minimum-value search for deletion logic.

Functions Implemented:
createNode(value) – allocates and initializes a new node.
insert(root, value) – inserts a value following BST rules.
findMin(root) – finds the smallest value in a subtree.
deleteNode(root, value) – deletes a value and restructures the tree.
inorder(root) – prints left, root, right.
preorder(root) – prints root, left, right.
postorder(root) – prints left, right, root.
main() – runs a menu for user operations on the BST.

How It Works:
- Insertion places smaller values in the left subtree and larger values in the right.
- Deletion handles three cases:
  * Node has no children.
  * Node has one child (left or right).
  * Node has two children — replaced with inorder successor.
- Traversals display tree structure in different orders.
- Menu loop runs until user selects Exit.

Notes:
- Time complexity: O(h), where h is tree height.
- BST is unbalanced — worst-case O(n) performance.
- Inorder traversal always prints sorted values.
- Uses dynamic memory allocation for node creation.

Why I Made This:
To understand and practice:
- Binary search tree fundamentals.
- Node insertion and deletion cases.
- Different types of tree traversals.
- Building interactive menu-based C programs for data structures.
