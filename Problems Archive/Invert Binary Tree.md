# Invert Binary Tree

Problem: 226
Official Difficulty: easy
Feels Like : easy
My Understanding: Mostly Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/invert-binary-tree/description/
Completed On : March 21, 2024
Last Review: March 21, 2024
Days Since Review: 40

## Problem

---

Given the `root` of a binary tree, invert the tree, and return *its root*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)

```
Input: root = [2,1,3]
Output: [2,3,1]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
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

    def inverter(self, node: Optional[TreeNode]) -> None:

        if not node:
            return

        temp = node.right
        node.right = node.left
        node.left = temp

        self.inverter(node.left)
        self.inverter(node.right)

        return node

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        self.inverter(root)

        return root
```

```python

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)