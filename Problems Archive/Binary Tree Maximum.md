# Binary Tree Maximum Path

Problem: 124
Official Difficulty: hard
Feels Like : medium
My Understanding: Needs Review
Topic: Depth-First Search (DFS), binary tree, dynamic programming, tree
Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
Completed On : December 23, 2024
Last Review: December 23, 2024
Days Since Review: 69
Neetcode: Yes

## Problem

---

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return *the maximum **path sum** of any **non-empty** path*.

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
        self.max = float('-inf')

    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        def dfs(node):

            if not node:
                return 0

            left = max(dfs(node.left), 0)  
            right = max(dfs(node.right), 0)

            self.max = max(self.max, node.val + left + right)

            return node.val + max(left, right)

        dfs(root)

        return self.max
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