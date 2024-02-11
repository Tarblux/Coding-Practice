# Maximum Depth of Binary Tree

Problem: 104
Official Difficulty: easy
Feels Like : medium
Topic: Depth-First Search (DFS), tree
Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
Completed On : January 4, 2024
My Understanding: I Have No Idea
Last Review: January 4, 2024
Days Since Review: 37

## Problem

---

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:

![https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

```python
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

Example 2:

```python
Input: root = [1,null,2]
Output: 2
```

Example 3:

```python
Input: root = []
Output: 0 
```

Example 4:

```python
Input: root = [0]
Output: 1 
```

Constraints:

- The number of nodes in the tree is in the range [0, 10^4].
- 100 <= Node.val <= 100

**Follow-up:**
Could you solve it both recursively and iteratively? 

## My Solutions

---

```python
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        if root == None:
            return 0
        
        leftCounter = 1
        leftCounter += self.maxDepth(root.left)
        
        rightCounter = 1
        rightCounter += self.maxDepth(root.right)
        
        return max(rightCounter, leftCounter)
```

```python

```

## Optimal Solutions

---

The most optimal approach for finding the maximum depth of a binary tree is to use depth-first search (DFS), typically implemented recursively. This approach has a time complexity of \(O(n)\), where \(n\) is the number of nodes in the binary tree, and a space complexity of \(O(h)\), where \(h\) is the height of the binary tree.

Here's a simple and efficient Python implementation:

```python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)

        return max(left_depth, right_depth) + 1

```

This code recursively calculates the maximum depth of the left and right subtrees, returning the maximum depth of the entire tree. The `maxDepth` function visits each node once, resulting in a linear time complexity. The space complexity is determined by the height of the tree due to the recursive calls, making it \(O(h)\).

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=hTM3phVI6YQ](https://www.youtube.com/watch?v=hTM3phVI6YQ)

[https://www.youtube.com/watch?v=4_UDUj1j1KQ](https://www.youtube.com/watch?v=4_UDUj1j1KQ)