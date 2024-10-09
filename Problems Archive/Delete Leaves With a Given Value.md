# Delete Leaves With a Given Value

Problem: 1325
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Depth-First Search (DFS), binary tree
Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/description/
Completed On : May 17, 2024
Last Review: May 17, 2024
Days Since Review: 2

## Problem

---

Given a binary tree `root` and an integer `target`, delete all the **leaf nodes** with value `target`.

Note that once you delete a leaf node with value `target`**,** if its parent node becomes a leaf node and has the value `target`, it should also be deleted (you need to continue doing that until you cannot).

**Example 1:**

![https://assets.leetcode.com/uploads/2020/01/09/sample_1_1684.png](https://assets.leetcode.com/uploads/2020/01/09/sample_1_1684.png)

```
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left).
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/01/09/sample_2_1684.png](https://assets.leetcode.com/uploads/2020/01/09/sample_2_1684.png)

```
Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
```

**Example 3:**

![https://assets.leetcode.com/uploads/2020/01/15/sample_3_1684.png](https://assets.leetcode.com/uploads/2020/01/15/sample_3_1684.png)

```
Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 3000]`.
- `1 <= Node.val, target <= 1000`

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

    def isLeaf(self, node):
        return not node.left and not node.right

    def dfsTraversal(self, node, target):
        if not node:
            return

        left_status = self.dfsTraversal(node.left, target)
        right_status = self.dfsTraversal(node.right, target)

        if left_status == "bad leaf":
            node.left = None
        if right_status == "bad leaf":
            node.right = None

        if self.isLeaf(node) and node.val == target:
            return "bad leaf"
        
        return

    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        if not root:
            return None

        if self.dfsTraversal(root, target) == "bad leaf":
            return None

        return root
```

```python

```

## Optimal Solutions

---

### Problem Description

Given a binary tree, you need to delete all the leaves that have a specific target value. Once you delete those leaves, new leaves may form. Continue deleting until no leaves with the target value are left.

### Example

```python
Input: root = [1, 2, 3, 2, None, 2, 4], target = 2
Output: [1, None, 3, None, 4]

Explanation:
         1                1
        / \\              / \\
       2   3    ->      N   3
      /   / \\              / \\
     2   2   4            N   4

```

### Optimal Solution and Explanation

To solve this problem, we can use a recursive approach to traverse the tree and delete the leaves with the given target value. The key is to check if a node is a leaf and if its value matches the target. If both conditions are true, we return `None` to delete the node. Otherwise, we continue the recursion for both the left and right children.

Here’s the Python code for this solution:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def removeLeafNodes(root, target):
    if not root:
        return None

    root.left = removeLeafNodes(root.left, target)
    root.right = removeLeafNodes(root.right, target)

    if not root.left and not root.right and root.val == target:
        return None

    return root

# Example usage
# Construct the tree: root = [1, 2, 3, 2, None, 2, 4]
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(2)
root.right.left = TreeNode(2)
root.right.right = TreeNode(4)

target = 2
new_root = removeLeafNodes(root, target)
# Function to print the tree in level-order
def printTree(root):
    if not root:
        return []
    result, queue = [], [root]
    while queue:
        level = []
        next_queue = []
        for node in queue:
            if node:
                level.append(node.val)
                next_queue.append(node.left)
                next_queue.append(node.right)
            else:
                level.append(None)
        if any(level):
            result.append(level)
        queue = next_queue
    return result

print(printTree(new_root))  # Output: [[1], [None, 3], [None, 4]]

```

### Explanation

1. **Base Case**: If the node is `None`, return `None`.
2. **Recursive Case**: Recursively call `removeLeafNodes` on the left and right children.
3. **Leaf Check**: After updating the left and right children, check if the current node is a leaf (both children are `None`) and if its value matches the target.
    - If both conditions are true, return `None` to delete the leaf.
    - Otherwise, return the current node.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=FqAoYAwbwV8](https://www.youtube.com/watch?v=FqAoYAwbwV8)