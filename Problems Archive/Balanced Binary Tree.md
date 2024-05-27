# Balanced Binary Tree

Problem: 110
Official Difficulty: easy
Feels Like : medium
My Understanding: Needs Review
Topic: Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/balanced-binary-tree/description/
Completed On : May 22, 2024
Last Review: May 22, 2024
Days Since Review: 4

## Problem

---

Given a binary tree, determine if it is

**height-balanced**

.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: true

```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

**Example 3:**

```
Input: root = []
Output: true
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `104 <= Node.val <= 104`

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
    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        def dfs(node):
            if not node:
                return 0

            left_height = dfs(node.left)
            if left_height == -1:
                return -1
            
            right_height = dfs(node.right)
            if right_height == -1: 
                return -1
            
            if abs(left_height - right_height) >= 2:
                return -1 

            return max(left_height, right_height) + 1

        return dfs(root) != -1
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        def dfs(node):

            if not node :
                return True , 0

            L_balanced , L_height = dfs(node.left)
            R_balanced , R_height = dfs(node.right)

            cur_balanced = abs(L_height - R_height) <= 1
            balanced = L_balanced and R_balanced and cur_balanced

            return balanced , max(L_height,R_height) + 1

        bal , height = dfs(root)

        return bal
```

## Optimal Solutions

---

### Problem Description

Given a binary tree, determine if it is height-balanced. A binary tree is balanced if the depths of the two subtrees of every node never differ by more than one.

### Example

```python
Input: root = [3, 9, 20, None, None, 15, 7]
Output: True

Input: root = [1, 2, 2, 3, 3, None, None, 4, 4]
Output: False
```

### Optimal Solution and Explanation

To solve this problem, we can use a recursive approach. We will create a helper function that returns two values:

1. Whether the subtree is balanced.
2. The height of the subtree.

By combining these two pieces of information, we can determine if the entire tree is balanced.

### Recursive Solution

Here's the Python code for the recursive solution:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isBalanced(root):
    def checkBalance(node):
        if not node:
            return True, -1  # A null node is balanced with height -1

        left_balanced, left_height = checkBalance(node.left)
        if not left_balanced:
            return False, 0  # If left subtree is not balanced, no need to check further

        right_balanced, right_height = checkBalance(node.right)
        if not right_balanced:
            return False, 0  # If right subtree is not balanced, no need to check further

        # The current node is balanced if the heights of the subtrees differ by no more than 1
        # and both subtrees are balanced
        balanced = abs(left_height - right_height) <= 1
        height = max(left_height, right_height) + 1

        return balanced, height

    balanced, _ = checkBalance(root)
    return balanced

# Example usage
# Construct the tree: root = [3, 9, 20, None, None, 15, 7]
root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)

print(isBalanced(root))  # Output: True

# Construct the tree: root = [1, 2, 2, 3, 3, None, None, 4, 4]
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(2)
root.left.left = TreeNode(3)
root.left.right = TreeNode(3)
root.left.left.left = TreeNode(4)
root.left.left.right = TreeNode(4)

print(isBalanced(root))  # Output: False

```

### Explanation

1. **Base Case**: A null node is considered balanced with a height of -1.
2. **Recursive Case**:
    - Check if the left subtree is balanced and get its height.
    - If the left subtree is not balanced, return `False`.
    - Check if the right subtree is balanced and get its height.
    - If the right subtree is not balanced, return `False`.
    - Determine if the current node is balanced by checking if the difference in heights of the left and right subtrees is no more than 1.
    - Compute the height of the current node as the maximum height of its subtrees plus one.
3. **Return**: Whether the tree is balanced and its height.

### Explain Like I'm Five (ELI5)

Imagine you have a bunch of building blocks stacked in two columns. You want to check if the columns are balanced:

1. **Balanced stacks**: If you can add one more block to either column without making one column much taller than the other, the columns are balanced.
2. **Check each level**: Start from the bottom and go up, checking each pair of blocks.
3. **Difference in height**: If at any level, the difference in height between the two columns is more than one block, the columns are not balanced.

By doing this for each level, you can determine if the entire structure is balanced.

## Notes

---

 

## Related Videos

---

[https://youtu.be/QfJsau0ItOY](https://youtu.be/QfJsau0ItOY)