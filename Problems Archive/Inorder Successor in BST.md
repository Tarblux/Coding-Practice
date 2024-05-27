# Inorder Successor in BST

Problem: 285
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Depth-First Search (DFS), binary search, binary tree
Link: https://leetcode.com/problems/inorder-successor-in-bst/description/
Completed On : May 22, 2024
Last Review: May 22, 2024
Days Since Review: 4

## Problem

---

Given the `root` of a binary search tree and a node `p` in it, return *the in-order successor of that node in the BST*. If the given node has no in-order successor in the tree, return `null`.

The successor of a node `p` is the node with the smallest key greater than `p.val`.

**Example 1:**

```
Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.

```

**Example 2:**

```
Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer isnull.

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `105 <= Node.val <= 105`
- All Nodes will have unique values.

## My Solutions

---

To simplify the code while keeping the approach, we can eliminate the need for the `nodes` list and streamline the logic. The key idea is to keep track of the previous node during the inorder traversal and check if the previous node is `p`. If it is, the current node is the inorder successor.

Here’s a more streamlined version of your code:

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def __init__(self):
        self.prev = None
        self.successor = None

    def dfsTraversal(self, node: Optional[TreeNode], p: TreeNode) -> None:
        if not node:
            return

        # Traverse the left subtree
        self.dfsTraversal(node.left, p)

        # Process the current node
        if self.prev == p:
            self.successor = node
            return

        self.prev = node

        # Traverse the right subtree
        self.dfsTraversal(node.right, p)

    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        self.prev = None
        self.successor = None
        self.dfsTraversal(root, p)
        return self.successor

```

**Simplifications and improvements:**

1. **Removed the `nodes` list**: By using a `self.prev` attribute, we can directly keep track of the previously visited node during the traversal.
2. **Inlined logic**: Instead of checking and returning within the traversal, we simply set `self.successor` when the successor is found, allowing the traversal to complete.
3. **Initialization**: Initialized `self.prev` and `self.successor` in the `inorderSuccessor` method to reset state for each call.

This version maintains your approach but simplifies the logic, making the code cleaner and easier to follow.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def dfsTraversal(self,node:Optional[TreeNode],nodes:List[int],p:TreeNode) -> Optional[TreeNode]:

        if not node:
            return

        left = self.dfsTraversal(node.left,nodes,p)

        if left:
            return left

        if nodes and nodes[-1]== p.val:
            return node

        nodes.append(node.val)

        return self.dfsTraversal(node.right,nodes,p)

    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:

        nodes = []
        
        successor = self.dfsTraversal(root,nodes,p)

        return successor
```

## Optimal Solutions

---

### Problem Description

Given a binary search tree (BST) and a node in it, find the in-order successor of that node in the BST. The in-order successor of a node is the node with the smallest key greater than the key of the given node.

### Example

```python
Input: root = [2, 1, 3], p = 1
Output: 2

Input: root = [5, 3, 6, 2, 4, None, None, 1], p = 6
Output: None

```

### Optimal Solution and Explanation

To find the in-order successor of a given node `p` in a BST, we need to consider two scenarios:

1. **If `p` has a right child**: The successor is the leftmost node in the right subtree.
2. **If `p` does not have a right child**: The successor is one of the ancestors. We need to traverse from the root and keep track of the potential successor.

### Recursive Solution

Here’s the Python code for the recursive solution:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorderSuccessor(root, p):
    successor = None

    while root:
        if p.val < root.val:
            successor = root
            root = root.left
        else:
            root = root.right

    return successor

# Example usage
# Construct the tree: root = [5, 3, 6, 2, 4, None, None, 1]
root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(6)
root.left.left = TreeNode(2)
root.left.right = TreeNode(4)
root.left.left.left = TreeNode(1)

p = root.left.right  # Node with value 4

print(inorderSuccessor(root, p).val if inorderSuccessor(root, p) else None)  # Output: 5

```

### Explanation

1. **Initialization**: Set `successor` to `None`.
2. **Traverse the BST**:
    - If the value of `p` is less than the current node's value, update `successor` to the current node and move to the left child.
    - Otherwise, move to the right child.
3. **Return**: After the traversal, `successor` will be the in-order successor of `p`.

### Explain Like I'm Five (ELI5)

Imagine you have a row of lockers, each labeled with a number. You want to find the next locker with a higher number after a given locker.

1. **If the locker has a key (right child)**: The next higher numbered locker is the smallest locker in the row of lockers starting from the key (right child).
2. **If the locker doesn't have a key**: You look at the lockers you passed before and find the smallest numbered locker that is still bigger than your current locker.

By following this process, you can efficiently find the next locker with a higher number.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)