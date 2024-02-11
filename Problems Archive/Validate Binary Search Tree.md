# Validate Binary Search Tree

Problem: 98
Official Difficulty: medium
Feels Like : hard
Topic: Depth-First Search (DFS), binary search, tree
Link: https://leetcode.com/problems/validate-binary-search-tree/
Completed On : December 12, 2023
My Understanding: I Have No Idea
Last Review: December 12, 2023
Days Since Review: 60

## Problem

---

Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

```
Input: root = [2,1,3]
Output: true

```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `231 <= Node.val <= 231 - 1`

## My Solutions

---

### Big Play Zwea

```python
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def helper(node, lower=float('-inf'), upper=float('inf')):
            if not node:
                return True
            
            val = node.val
            if val <= lower or val >= upper:
                return False

            if not helper(node.right, val, upper):
                return False
            if not helper(node.left, lower, val):
                return False
            return True
        
        return helper(root)
```

### Sanya

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def validate(root, low, high):
            
            if not root:
                return True
            
            if not (low < root.val < high):
                return False
            
            return validate(root.left, low, root.val) and validate(root.right, root.val, high)
        
        return validate(root, -2**31 - 1, 2**31)
```

## Optimal Solutions

---

The "Validate Binary Search Tree" problem involves checking whether a given binary tree is a valid binary search tree (BST). A BST is a tree in which all the nodes follow the below two properties:

1. The left subtree of a node contains only nodes with keys less than the node's key.
2. The right subtree of a node contains only nodes with keys greater than the node's key.

Additionally, both the left and right subtrees must also be binary search trees.

### Solution Approach

A common approach to solving this problem is to perform an in-order traversal of the tree. During the traversal, we check if the node values are in ascending order, which is a property of BSTs. If at any point we find that the order is not maintained, we can conclude that the tree is not a BST.

### Python Implementation

Here is a possible Python implementation using recursive in-order traversal:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def validate(node, low=float('-inf'), high=float('inf')):
            # An empty tree is a BST
            if not node:
                return True

            # The current node's value must be between low and high.
            if node.val <= low or node.val >= high:
                return False

            # Recursively check the subtrees with updated range
            return (validate(node.right, node.val, high) and
                    validate(node.left, low, node.val))

        return validate(root)

```

### Explanation

- The `validate` function is a helper function that checks whether the tree is a BST.
- It takes three parameters: the current `node`, the `low` boundary, and the `high` boundary. The `low` and `high` values define the range of valid values for the current node.
- For each node, we check if its value is within the range `(low, high)`. If it's not, we return `False`.
- We then recursively check the left and right subtrees. For the left subtree, the `high` boundary becomes the value of the current node. For the right subtree, the `low` boundary becomes the value of the current node.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of nodes in the tree. In the worst case, we visit each node once.
- **Space Complexity**: O(n) in the worst case (the tree is completely unbalanced) for the call stack during the recursion. For a balanced tree, the space complexity would be O(log n).

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)