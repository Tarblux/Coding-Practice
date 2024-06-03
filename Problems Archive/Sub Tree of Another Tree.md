# Sub Tree of Another Tree

Problem: 572
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: Depth-First Search (DFS), binary tree, hash function, string matching, tree
Link: https://leetcode.com/problems/subtree-of-another-tree/description/
Completed On : May 27, 2024
Last Review: May 27, 2024
Days Since Review: 7

## Problem

---

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg](https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg)

```
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg](https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg)

```
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
```

**Constraints:**

- The number of nodes in the `root` tree is in the range `[1, 2000]`.
- The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
- `104 <= root.val <= 104`
- `104 <= subRoot.val <= 104`

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

    def sameTree(self,s:Optional[TreeNode],t:Optional[TreeNode]) -> bool:

        if not s and not t :
            return True

        if s and t and s.val == t.val:

            left = self.sameTree(s.left,t.left)
            right = self.sameTree(s.right,t.right)

            return left and right

        return False 

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        if not subRoot:
            return True

        if not root and subRoot:
            return False

        if self.sameTree(root,subRoot):
            return True

        left = self.isSubtree(root.left,subRoot)
        right = self.isSubtree(root.right,subRoot)

        return left or right
```

```python

```

## Optimal Solutions

---

### Problem Description

Given two non-empty binary trees `s` and `t`, check whether tree `t` has exactly the same structure and node values with a subtree of `s`. A subtree of `s` is a tree `consists of a node in` s`and all of this node's descendants. The tree`s` could also be considered as a subtree of itself.

### Example

```python
Input: s = [3,4,5,1,2], t = [4,1,2]
Output: True

Input: s = [3,4,5,1,2,None,None,0], t = [4,1,2]
Output: False

```

### Optimal Solution and Explanation

To determine if `t` is a subtree of `s`, we can use a combination of tree traversal and subtree comparison. We will traverse the tree `s` and at each node, we will check if the subtree rooted at that node is identical to `t`.

### Steps:

1. **Tree Traversal**: Traverse the tree `s` using a depth-first search (DFS) or breadth-first search (BFS).
2. **Subtree Comparison**: At each node in `s`, check if the subtree rooted at that node is identical to `t`. This involves a recursive comparison of nodes and their respective children.

### Python Code

Here’s the Python code to achieve this:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isSubtree(s, t):
    if not s:
        return False

    if isSameTree(s, t):
        return True

    return isSubtree(s.left, t) or isSubtree(s.right, t)

def isSameTree(s, t):
    if not s and not t:
        return True
    if not s or not t:
        return False
    if s.val != t.val:
        return False

    return isSameTree(s.left, t.left) and isSameTree(s.right, t.right)

# Example usage
# Construct the tree s: root = [3, 4, 5, 1, 2]
s = TreeNode(3)
s.left = TreeNode(4)
s.right = TreeNode(5)
s.left.left = TreeNode(1)
s.left.right = TreeNode(2)

# Construct the tree t: root = [4, 1, 2]
t = TreeNode(4)
t.left = TreeNode(1)
t.right = TreeNode(2)

print(isSubtree(s, t))  # Output: True

# Construct another example where t is not a subtree
# Construct the tree s: root = [3, 4, 5, 1, 2, None, None, 0]
s = TreeNode(3)
s.left = TreeNode(4)
s.right = TreeNode(5)
s.left.left = TreeNode(1)
s.left.right = TreeNode(2)
s.left.left.left = TreeNode(0)

print(isSubtree(s, t))  # Output: False

```

### Explanation

1. **Tree Traversal**:
    - Traverse the tree `s` starting from the root.
    - At each node, check if the subtree rooted at that node matches tree `t`.
2. **Subtree Comparison**:
    - The function `isSameTree(s, t)` checks if two trees are identical.
    - This involves comparing the values of the current nodes and recursively checking their left and right children.
3. **Return Results**:
    - If `isSameTree(s, t)` returns `True` at any node, `t` is a subtree of `s`.
    - If not, recursively check the left and right subtrees of `s`.

### Explain Like I'm Five (ELI5)

Imagine you have two sets of building blocks, and you want to see if one set (t) is exactly the same as a part of the other set (s):

1. **Check Each Block**: Start from the first block of the big set (s) and see if it matches the first block of the small set (t).
2. **Compare Block by Block**: If the first blocks match, check the next blocks to see if they also match exactly.
3. **Move to Next Block**: If at any point they don't match, move to the next block in the big set and repeat the process.
4. **Find a Match**: If you find a spot where the small set fits perfectly in the big set, then the small set is part of the big set.

By following this process, you can determine if one set of blocks is a perfect match for a part of another set.

## Notes

---

 

## Related Videos

---

[https://youtu.be/E36O5SWp-LE](https://youtu.be/E36O5SWp-LE)