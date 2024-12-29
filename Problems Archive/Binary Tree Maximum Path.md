Problem: 124
Official Difficulty: hard
Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
Completed On : 2024-12-23
Feels Like : medium
Topic: dynamic programming, tree, Depth-First Search (DFS), binary tree
My Understanding: Needs Review
Last Review: 2024-12-23
Days Since Review: 6
Name: Binary Tree Maximum Path

# Binary Tree Maximum Path
### Problem
___
A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.
The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return *the maximum ****path sum**** of any ****non-empty**** path*.
### My Solutions
___
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

Time Complexity :
```python

```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()