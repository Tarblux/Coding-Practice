# Kth Smallest Element in a BST

Problem: 230
Official Difficulty: medium
Feels Like : easy
My Understanding: Mostly Understand
Topic: Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
Completed On : May 22, 2024
Last Review: May 22, 2024
Days Since Review: 4

## Problem

---

Given the `root` of a binary search tree, and an integer `k`, return *the* `kth` *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)

```
Input: root = [3,1,4,null,2], k = 1
Output: 1
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg](https://assets.leetcode.com/uploads/2021/01/28/kthtree2.jpg)

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
```

**Constraints:**

- The number of nodes in the tree is `n`.
- `1 <= k <= n <= 104`
- `0 <= Node.val <= 104`

**Follow up:** If the BST is modified often (i.e., we 
can do insert and delete operations) and you need to find the kth 
smallest frequently, how would you optimize?

## My Solutions

---

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def dfsTraversal(self,node:Optional[TreeNode],array:List[int])-> int:

        if not node:
            return

        self.dfsTraversal(node.left,array)

        array.append(node.val)

        self.dfsTraversal(node.right,array)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:

        nodes = []

        self.dfsTraversal(root,nodes)

        return nodes[k-1]
```

```python

```

## Optimal Solutions

---

### Problem Description

Given the root of a binary search tree (BST) and an integer `k`, return the `k`-th smallest value (1-indexed) of all the values of the nodes in the tree.

### Example

```python
Input: root = [3, 1, 4, None, 2], k = 1
Output: 1

Input: root = [5, 3, 6, 2, 4, None, None, 1], k = 3
Output: 3
```

### Optimal Solution and Explanation

To solve this problem, we can leverage the properties of a binary search tree (BST), where an in-order traversal yields the nodes in sorted order. Thus, the `k`-th smallest element in the BST can be found by performing an in-order traversal and keeping track of the count of nodes visited.

### Recursive Solution

Here's the Python code for the recursive solution:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def kthSmallest(root, k):
    def inorder(node):
        if not node:
            return []
        return inorder(node.left) + [node.val] + inorder(node.right)

    return inorder(root)[k-1]

# Example usage
# Construct the tree: root = [3, 1, 4, None, 2]
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.right = TreeNode(2)

print(kthSmallest(root, 1))  # Output: 1

# Construct the tree: root = [5, 3, 6, 2, 4, None, None, 1]
root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(6)
root.left.left = TreeNode(2)
root.left.right = TreeNode(4)
root.left.left.left = TreeNode(1)

print(kthSmallest(root, 3))  # Output: 3
```

### Iterative Solution

Here’s the Python code for the iterative solution using an explicit stack:

```python
def kthSmallestIterative(root, k):
    stack = []
    while True:
        while root:
            stack.append(root)
            root = root.left
        root = stack.pop()
        k -= 1
        if k == 0:
            return root.val
        root = root.right

# Example usage
# Construct the tree: root = [3, 1, 4, None, 2]
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.right = TreeNode(2)

print(kthSmallestIterative(root, 1))  # Output: 1

# Construct the tree: root = [5, 3, 6, 2, 4, None, None, 1]
root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(6)
root.left.left = TreeNode(2)
root.left.right = TreeNode(4)
root.left.left.left = TreeNode(1)

print(kthSmallestIterative(root, 3))  # Output: 3
```

### Explanation

1. **Recursive Solution**:
    - Perform an in-order traversal of the BST.
    - Collect the values of the nodes in a list.
    - Return the `k`th smallest element from the list.
2. **Iterative Solution**:
    - Use an explicit stack to perform the in-order traversal.
    - Push all left nodes to the stack until reaching the leftmost node.
    - Pop nodes from the stack, decrement `k`, and if `k` becomes zero, return the current node's value.
    - Move to the right subtree and continue the process.

### Explain Like I'm Five (ELI5)

Imagine you have a bookshelf where each shelf is perfectly ordered from smallest book to largest book. You want to find the `k`-th smallest book:

1. **Recursive Approach**:
    - Walk along each shelf, picking books from left to right, and put them in a line.
    - Once you've got all the books in a line, just count to the `k`th book in the line.
2. **Iterative Approach**:
    - Start at the top-left corner of the bookshelf.
    - Use a stack of sticky notes to mark the books you've seen.
    - Keep moving left until you can't move further.
    - Start picking the books from your stack of sticky notes and count each one.
    - Once you've picked the `k`th book, you have your answer!

Both methods help you efficiently find the book you need without having to search through every book one by one.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=5LUXSvjmGCw&pp=ygUdS3RoIHNtYWxsZXN0IGVsZW1lbnQgaW4gYSBCU1Q%3D](https://www.youtube.com/watch?v=5LUXSvjmGCw&pp=ygUdS3RoIHNtYWxsZXN0IGVsZW1lbnQgaW4gYSBCU1Q%3D)