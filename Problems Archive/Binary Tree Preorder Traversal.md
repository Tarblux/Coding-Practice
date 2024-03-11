# Binary Tree Preorder Traversal

Problem: 144
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: binary tree
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
Completed On : March 3, 2024
Last Review: March 3, 2024
Days Since Review: 7

## Problem

---

Given the `root` of a binary tree, return *the preorder traversal of its nodes' values*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,2,3]
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

**Follow up:** Recursive solution is trivial, could you do it iteratively?

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

    def traversalHelper(self,node,array):

        if not node : 
            return

        array.append(node.val)

        self.traversalHelper(node.left,array)

        self.traversalHelper(node.right,array)

        return array

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        values = []

        return self.traversalHelper(root,values)
       
```

```python

```

## Optimal Solutions

---

## Iterative Approach

To perform a binary tree preorder traversal iteratively, you can use a stack to keep track of nodes. In preorder traversal, you visit the node first, then traverse the left subtree, and finally traverse the right subtree. The iterative approach explicitly maintains a stack to mimic the recursion's call stack, allowing us to visit each node in the desired preorder sequence.

### Iterative Preorder Traversal Algorithm:

1. **Initialize** a stack and push the root node onto the stack.
2. **Loop** while the stack is not empty:
    - **Pop** the top node from the stack and process it (e.g., add its value to the result list).
    - **Push** the right child of the popped node onto the stack if it exists. (Right child is pushed first so that the left child is processed first, maintaining the preorder sequence of "node-left-right".)
    - **Push** the left child of the popped node onto the stack if it exists.

### Python Implementation:

```python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        stack = [root]  # Initialize the stack with the root node
        result = []  # This will store the values in preorder

        while stack:
            node = stack.pop()  # Pop the top node from the stack
            result.append(node.val)  # Process the node

            # Push right child first so that left child is processed first
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return result

```

### Explanation:

- The stack is used to keep track of nodes that are yet to be visited. Initially, it contains just the root node.
- In each iteration of the loop, the top node from the stack is popped and processed (its value is added to the `result` list).
- The right child (if any) of the popped node is pushed onto the stack followed by the left child. This order ensures that when nodes are popped from the stack for processing, the left child is processed before the right child, adhering to the preorder traversal order.
- The loop continues until the stack is empty, indicating that all nodes have been visited and processed.

### Complexity Analysis:

- **Time Complexity**: O(N), where N is the number of nodes in the binary tree. Each node is pushed and popped from the stack exactly once.
- **Space Complexity**: O(N) in the worst case (the tree is completely unbalanced, and the stack contains all nodes). For a balanced tree, the space complexity is O(log N) due to the height of the call stack.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)