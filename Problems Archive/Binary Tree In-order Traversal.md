# Binary Tree In-order Traversal

Problem: 94
Official Difficulty: easy
Feels Like : medium
Topic: Depth-First Search (DFS), Stack, binary tree, tree
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
Completed On : January 15, 2024
My Understanding: Needs Review
Last Review: January 15, 2024
Days Since Review: 26

## Problem

---

Given the `root` of a binary tree, return *the in-order traversal of its nodes' values*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,3,2]

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

- The number of nodes in the tree is in the range `[0, 100]`.
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
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        array = []
        
        def travis(node , array) :
            
            if node == None :
                
                return array
        
            travis(node.left , array)
            
            array.append(node.val)
            
            travis(node.right , array)
        
            return array
        
        return travis(root,array)
```

```python

```

## Optimal Solutions

---

In-order traversal of a binary tree is one of the most common tree traversal methods. It involves visiting the left subtree, the root node, and then the right subtree. When performed on a binary search tree, it visits the nodes in ascending order.

### Problem Statement

Given the root of a binary tree, return the in-order traversal of its nodes' values.

### Recursive Solution

The recursive approach is straightforward, following the definition of in-order traversal.

### Python Implementation

Assuming the definition of a Tree-node is given as:

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

```

Here's the implementation:

```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        def inorder(node, traversal):
            if node:
                inorder(node.left, traversal)
                traversal.append(node.val)
                inorder(node.right, traversal)

        result = []
        inorder(root, result)
        return result

```

### Iterative Solution

The iterative approach uses a stack to simulate the recursion process.

### Python Implementation

```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        result, stack = [], []
        current = root

        while current or stack:
            while current:
                stack.append(current)
                current = current.left

            current = stack.pop()
            result.append(current.val)
            current = current.right

        return result

```

### Explanation

- **Recursive Approach**: A helper function `inorder` is used to perform the traversal. It visits the left child, appends the node's value, and then visits the right child. The result is collected in the `result` list.
- **Iterative Approach**: A stack is used to keep track of nodes. We go as left as possible, pushing nodes onto the stack. When we can't go left anymore, we pop from the stack, append the node's value to the result, and then proceed to the right.

### Complexity Analysis

- **Time Complexity**: O(n) for both approaches, as each node is visited once, where `n` is the number of nodes in the tree.
- **Space Complexity**:
    - Recursive: O(n) in the worst case due to the recursion stack.
    - Iterative: O(n) in the worst case for the auxiliary stack.

Both approaches are commonly used for inorder traversal. The choice between recursive and iterative depends on personal preference and any space complexity considerations.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)