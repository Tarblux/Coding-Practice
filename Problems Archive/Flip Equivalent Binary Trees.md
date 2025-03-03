# Flip Equivalent Binary Trees

Problem: 951
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/flip-equivalent-binary-trees/description/?envType=daily-question&envId=2024-10-24
Completed On : October 23, 2024
Last Review: October 23, 2024
Days Since Review: 130
Neetcode: No

## Problem

---

For a binary tree **T**, we can define a **flip operation** as follows: choose any node, and swap the left and right child subtrees.

A binary tree **X** is *flip equivalent* to a binary tree **Y** if and only if we can make **X** equal to **Y** after some number of flip operations.

Given the roots of two binary trees `root1` and `root2`, return `true` if the two trees are flip equivalent or `false` otherwise.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/11/29/tree_ex.png)

```
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation:We flipped at nodes with values 1, 3, and 5.

```

**Example 2:**

```
Input: root1 = [], root2 = []
Output: true

```

**Example 3:**

```
Input: root1 = [], root2 = [1]
Output: false

```

**Constraints:**

- The number of nodes in each tree is in the range `[0, 100]`.
- Each tree will have **unique node values** in the range `[0, 99]`.

## My Solutions

---

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:

    def isEqual(self, n1, n2):
        if not n1 and not n2:
            return True
        if not n1 or not n2:
            return False
        return n1.val == n2.val

    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        queue = deque([(root1, root2)])

        while queue:
            node1, node2 = queue.popleft()
            
            if not node1 and not node2:
                continue
            if not node1 or not node2 or node1.val != node2.val:
                return False

            if self.isEqual(node1.left, node2.left) and self.isEqual(node1.right, node2.right):
                queue.append((node1.left, node2.left))
                queue.append((node1.right, node2.right))
            elif self.isEqual(node1.left, node2.right) and self.isEqual(node1.right, node2.left):
                queue.append((node1.left, node2.right))
                queue.append((node1.right, node2.left))
            else:
                return False

        return True

        
```

Alex’s dfs 

```python
# Definition for a binary tree node.
# class TreeNode:
#     def init(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:

        def dfs(node_1, node_2):
            if not node_1 and not node_2:
                return True
            if not node_1 or not node_2 or node_1.val != node_2.val:
                return False
            if node_1.left and node_2.left:
                if node_1.left.val != node_2.left.val: 
                    return dfs(node_1.left, node_2.right)and dfs(node_1.right, node_2.left)   
            elif node_1.left or node_2.left:
                return dfs(node_1.left, node_2.right)and dfs(node_1.right, node_2.left)           
            return dfs(node_1.left, node_2.left) and dfs(node_1.right, node_2.right)

        return dfs(root1, root2)
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)