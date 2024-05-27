# Diameter of Binary Tree

Problem: 543
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/diameter-of-binary-tree/description/
Completed On : May 24, 2024
Last Review: May 24, 2024
Days Since Review: 2

## Problem

---

Given the `root` of a binary tree, return *the length of the **diameter** of the tree*.

The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The **length** of a path between two nodes is represented by the number of edges between them.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

**Example 2:**

```
Input: root = [1,2]
Output: 1
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `100 <= Node.val <= 100`

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

    def __init__(self):
        self.max = 0

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:

        if not root:
            return 0

        def dfs(node):

            if not node:
                return 0

            left = dfs(node.left)
            right = dfs(node.right)
            
            self.max = max(self.max,left + right)

            return max(left,right) + 1

        dfs(root)

        return self.max  
```

```python

```

## Optimal Solutions

---

### Problem Description

Given the root of a binary tree, return the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

### Example

```python
Input: root = [1, 2, 3, 4, 5]
Output: 3

Explanation:
The longest path is 4 -> 2 -> 1 -> 3 or 5 -> 2 -> 1 -> 3, both of which have length 3.
```

### Optimal Solution and Explanation

To solve this problem, we need to find the longest path between any two nodes in the binary tree. We can achieve this by using a depth-first search (DFS) approach to calculate the depth of each subtree and keep track of the longest path found so far.

### Recursive Solution

Here’s the Python code for the recursive solution:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def diameterOfBinaryTree(root):
    def dfs(node):
        nonlocal diameter
        if not node:
            return 0

        left_depth = dfs(node.left)
        right_depth = dfs(node.right)

        # Update the diameter if the path through this node is larger
        diameter = max(diameter, left_depth + right_depth)

        # Return the depth of the tree rooted at this node
        return max(left_depth, right_depth) + 1

    diameter = 0
    dfs(root)
    return diameter

# Example usage
# Construct the tree: root = [1, 2, 3, 4, 5]
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

print(diameterOfBinaryTree(root))  # Output: 3

```

### Explanation

1. **DFS Traversal**: Perform a depth-first search to calculate the depth of each subtree.
2. **Depth Calculation**:
    - For each node, calculate the depth of its left and right subtrees.
    - The depth of the tree rooted at this node is `max(left_depth, right_depth) + 1`.
3. **Diameter Update**: Update the diameter at each node by considering the longest path through this node, which is `left_depth + right_depth`.
4. **Return Diameter**: After the DFS traversal, return the maximum diameter found.

### Explain Like I'm Five (ELI5)

Imagine you are in a garden with a lot of trees, and you want to find the longest path you can walk without retracing your steps.

1. **Check each tree**: For each tree, measure how far you can go left and how far you can go right.
2. **Longest path**: For each tree, if you can go farther than any other tree, remember this distance as the longest path.
3. **Repeat for all trees**: Do this for all trees in the garden to find the longest path overall.

By doing this, you can find the longest path in the entire garden!

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=bkxqA8Rfv04&pp=ygUXZGlhbWV0ZXIgb2YgYmluYXJ5IHRyZWU%3D](https://www.youtube.com/watch?v=bkxqA8Rfv04&pp=ygUXZGlhbWV0ZXIgb2YgYmluYXJ5IHRyZWU%3D)