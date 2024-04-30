# Find Mode in Binary Search Tree

Problem: 501
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: Depth-First Search (DFS), binary search tree, binary tree, tree
Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
Completed On : April 10, 2024
Last Review: April 10, 2024
Days Since Review: 20

## Problem

---

Given the `root` of a binary search tree (BST) with duplicates, return *all the [mode(s)](https://en.wikipedia.org/wiki/Mode_(statistics)) (i.e., the most frequently occurred element) in it*.

If the tree has more than one mode, return them in **any order**.

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys **less than or equal to** the node's key.
- The right subtree of a node contains only nodes with keys **greater than or equal to** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg](https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg)

```
Input: root = [1,null,2,2]
Output: [2]
```

**Example 2:**

```
Input: root = [0]
Output: [0]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `105 <= Node.val <= 105`

**Follow up:**

Could you do that without using any extra 
space? (Assume that the implicit stack space incurred due to recursion 
does not count).

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

    def inorderTraversal(self,node,dict):

        if not node:
            return 

        dict[node.val] = dict.get(node.val,0) + 1

        self.inorderTraversal(node.left,dict)
        self.inorderTraversal(node.right,dict)

    def findMode(self, root: Optional[TreeNode]) -> List[int]:

        node_dict = {}
        modes = []
        max_freq = 0

        self.inorderTraversal(root,node_dict)

        max_freq = max(node_dict.values())

        for key ,value in node_dict.items():

            if value == max_freq:
                modes.append(key)

        return modes
```

```python

```

## Optimal Solutions

---

[https://leetcode.com/problems/find-mode-in-binary-search-tree/editorial/](https://leetcode.com/problems/find-mode-in-binary-search-tree/editorial/)

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)