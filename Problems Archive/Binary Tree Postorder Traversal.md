# Binary Tree Postorder Traversal

Problem: 145
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: Depth-First Search (DFS), Stack, binary tree, tree
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
Completed On : March 25, 2024
Last Review: August 25, 2024
Days Since Review: 1

## Problem

---

Given the `root` of a binary tree, return *the postorder traversal of its nodes' values*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg](https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg)

```
Input: root = [1,null,2,3]
Output: [3,2,1]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Constraints:**

- The number of the nodes in the tree is in the range `[0, 100]`.
- `100 <= Node.val <= 100`

**Follow up:**

Recursive solution is trivial, could you do it iteratively?

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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        if not root:

            return []

        return self.postorderTraversal(root.left)  + self.postorderTraversal(root.right) + [root.val]
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def __init__(self):
        self.output = []

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        if not root:
            return

        self.postorderTraversal(root.left)

        self.postorderTraversal(root.right)

        self.output.append(root.val)

        return self.output
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