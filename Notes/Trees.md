# Trees

A tree is a hierarchical data structure that consists of nodes connected by edges. Each node has a value and can have zero or more child nodes. Trees are widely used in computer science for various applications, such as organizing data, representing hierarchical structures, and solving complex problems.

### Basic Terminology

| Term | Definition |
| --- | --- |
| Node | A fundamental unit of a tree that contains data and may have child nodes. |
| Edge | A connection between nodes that represents a relationship. |
| Root | The topmost node in a tree, from which all other nodes are descendants. |
| Parent | A node that has one or more child nodes. |
| Child | A node that has a parent node. |
| Leaf | A node that has no child nodes. |
| Sibling | Nodes that share the same parent. |
| Depth | The level or distance of a node from the root. |
| Height | The maximum depth of the tree (the length of the longest path from the root to a leaf). |

# Common Tree Operations in LeetCode

When working with trees in LeetCode and competitive programming, some common tree operations are frequently encountered. Below, we'll explore these operations and provide Python code examples for each.

## 1. Tree Traversal

Tree traversal is a fundamental operation that involves visiting all nodes of a tree in a specific order. The three most common traversal methods are:

### Inorder Traversal

In inorder traversal, we visit the left subtree, the current node, and then the right subtree. It is commonly used for binary search trees (BSTs) to retrieve elements in sorted order.

**Python Code Example:**

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder_traversal(root):
    result = []
    if root:
        result.extend(inorder_traversal(root.left))
        result.append(root.val)
        result.extend(inorder_traversal(root.right))
    return result

```

### Preorder Traversal

In preorder traversal, we visit the current node, the left subtree, and then the right subtree. It is useful for creating a copy of the tree.

**Python Code Example:**

```python
def preorder_traversal(root):
    result = []
    if root:
        result.append(root.val)
        result.extend(preorder_traversal(root.left))
        result.extend(preorder_traversal(root.right))
    return result

```

### Postorder Traversal

In postorder traversal, we visit the left subtree, the right subtree, and then the current node. It is often used for deleting a tree.

**Python Code Example:**

```python
def postorder_traversal(root):
    result = []
    if root:
        result.extend(postorder_traversal(root.left))
        result.extend(postorder_traversal(root.right))
        result.append(root.val)
    return result

```

## 2. Insertion

Insertion involves adding a new node to the tree. The code for inserting a node depends on the type of tree.

## 3. Deletion

Deletion involves removing a node from the tree. Similar to insertion, the deletion process depends on the tree type and may require rebalancing in some cases.

## 4. Searching

Searching for a specific node or value in a tree is a common operation. It can be performed using various traversal methods or specialized algorithms, such as binary search in BSTs.

**Python Code Example (BST Search):**

```python
def search(root, val):
    if not root:
        return False
    if root.val == val:
        return True
    if val < root.val:
        return search(root.left, val)
    else:
        return search(root.right, val)

```

## 5. Finding the Height

Finding the height of a tree is essential for understanding its structure and performance. The height is the length of the longest path from the root to a leaf node.

**Python Code Example:**

```python
def find_height(root):
    if not root:
        return 0
    left_height = find_height(root.left)
    right_height = find_height(root.right)
    return max(left_height, right_height) + 1

```

These common tree operations and their Python code examples will help you tackle tree-related problems on LeetCode and enhance your problem-solving skills.

## Types of Trees

### 1. Binary Tree

- A tree in which each node has at most two children: a left child and a right child.

![https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Binary_tree.svg/400px-Binary_tree.svg.png](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Binary_tree.svg/400px-Binary_tree.svg.png)

### 2. Binary Search Tree (BST)

- A binary tree with the property that the value of each node in the left subtree is less than or equal to the node's value, and the value of each node in the right subtree is greater than the node's value.

![https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/400px-Binary_search_tree.svg.png](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/400px-Binary_search_tree.svg.png)

### 3. Balanced Tree

- A tree in which the depth of the left and right subtrees of every node differs by at most one. Common types include AVL trees and Red-Black trees.

![https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/AVL_Tree_Example.gif/400px-AVL_Tree_Example.gif](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/AVL_Tree_Example.gif/400px-AVL_Tree_Example.gif)

### 4. Binary Heap

- A specialized binary tree that satisfies the heap property, where the parent node's value is greater (or smaller) than the values of its children.

![https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Max-Heap.svg/400px-Max-Heap.svg.png](https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Max-Heap.svg/400px-Max-Heap.svg.png)

### 5. Trie (Prefix Tree)

- A tree-like data structure used to store a dynamic set of strings, often used in text autocomplete and search algorithms.

![https://upload.wikimedia.org/wikipedia/commons/thumb/b/be/Trie_example.svg/400px-Trie_example.svg.png](https://upload.wikimedia.org/wikipedia/commons/thumb/b/be/Trie_example.svg/400px-Trie_example.svg.png)

### 6. B-Tree

- A self-balancing tree data structure that maintains sorted data and is commonly used in databases and file systems.

![https://upload.wikimedia.org/wikipedia/commons/thumb/6/65/B-tree.svg/400px-B-tree.svg.png](https://upload.wikimedia.org/wikipedia/commons/thumb/6/65/B-tree.svg/400px-B-tree.svg.png)

## Tree Traversal

Traversal is the process of visiting all the nodes of a tree in a specific order. There are two main types of tree traversal:

### 1. Depth-First Traversal

In-depth-first traversal, you explore as far as possible along a branch before backtracking. Common methods include:

### a. Inorder Traversal

- Visit left subtree, current node, then right subtree.
- Used for sorting in BSTs.

### b. Preorder Traversal

- Visit current node, then left subtree, then right subtree.
- Used for creating a copy of the tree.

### c. Postorder Traversal

- Visit left subtree, right subtree, then current node.
- Used for deleting a tree.

### 2. Breadth-First Traversal

In breadth-first traversal, you explore all nodes at the current depth before moving on to the next depth. This is often done using a queue data structure.

## Example Python Code for a Binary Tree

Here's an example of a binary tree implemented in Python:

```python
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

# Create a binary tree
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

# Tree structure:
#        1
#       / \\
#      2   3
#     / \\
#    4   5

```

Trees are a versatile and powerful data structure used in a wide range of applications, including databases, compilers, file systems, and more. Understanding the basic concepts, types of trees, and traversal techniques is essential for solving complex problems and designing efficient algorithms. Whether you're working with binary trees, binary search trees, or more advanced tree structures, the principles of tree-based data structures remain fundamental in computer science.