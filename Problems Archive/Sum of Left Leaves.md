# Sum of Left Leaves

Problem: 404
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/sum-of-left-leaves/description/
Completed On : April 15, 2024
Last Review: April 15, 2024
Days Since Review: 15

## Problem

---

Given the `root` of a binary tree, return *the sum of all left leaves.*

A **leaf** is a node with no children. A **left leaf** is a leaf that is the left child of another node.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
```

**Example 2:**

```
Input: root = [1]
Output: 0
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `1000 <= Node.val <= 1000`

## My Solutions

---

```python

```

```python

```

## Optimal Solutions

---

```python
class Solution:
    
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        
        if root is None: 
            return 0

        def is_leaf(node):
            return node is not None and node.left is None and node.right is None

        stack = [root]
        total = 0
        while stack:
            sub_root = stack.pop()
            # Check if the left node is a leaf node.
            if is_leaf(sub_root.left):
                total += sub_root.left.val
            # If the right node exists, put it on the stack.
            if sub_root.right is not None:
                stack.append(sub_root.right)
            # If the left node exists, put it on the stack.
            if sub_root.left is not None:
                stack.append(sub_root.left)

        return total
```

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=QklIrzxiqcM](https://www.youtube.com/watch?v=QklIrzxiqcM)