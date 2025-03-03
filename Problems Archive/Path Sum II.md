# Path Sum II

Problem: 113
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Depth-First Search (DFS), backtracking, binary tree, tree
Link: https://leetcode.com/problems/path-sum-ii/description/
Completed On : December 10, 2024
Last Review: December 10, 2024
Days Since Review: 82
Neetcode: No

## Problem

---

Given the `root` of a binary tree and an integer `targetSum`, return *all **root-to-leaf** paths where the sum of the node values in the path equals* `targetSum`*. Each path should be returned as a list of the node **values**, not node references*.

A **root-to-leaf** path is a path starting from the root and ending at any leaf node. A **leaf** is a node with no children.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
Input: root = [1,2,3], targetSum = 5
Output: []

```

**Example 3:**

```
Input: root = [1,2], targetSum = 0
Output: []

```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `1000 <= Node.val <= 1000`
- `1000 <= targetSum <= 1000`

## My Solutions

---

```python

```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isLeaf(self, node):
        return not node.left and not node.right

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        def pathTraversal(node, currentSum, path, output):
            if not node:
                return
            
            # Update the current path and current sum
            currentSum += node.val
            path.append(node.val)
            
            # Check if the current node is a leaf and the current sum equals target sum
            if self.isLeaf(node) and currentSum == targetSum:
                output.append(path.copy())  # Append a copy of the current path
            
            # Traverse left and right subtrees
            pathTraversal(node.left, currentSum, path, output)
            pathTraversal(node.right, currentSum, path, output)
            
            # Backtrack to explore other paths
            path.pop()
        
        output = []
        pathTraversal(root, 0, [], output)
        return output

```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)