# Path Sum

Problem: 112
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree
Link: https://leetcode.com/problems/path-sum/description/
Completed On : May 7, 2024
Last Review: May 7, 2024
Days Since Review: 5

## Problem

---

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

A **leaf** is a node with no children.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

**Example 3:**

```
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `1000 <= Node.val <= 1000`
- `1000 <= targetSum <= 1000`

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
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:

        def leaf(node):
            return node and node.left == None and node.right == None

        if not root:
            return False

        stack = [[root,0]]

        while stack:

            
            cur_node , cur_sum = stack.pop()

            if leaf(cur_node):
                cur_sum += cur_node.val
                if cur_sum == targetSum:
                    return True

            if cur_node.right:
                stack.append([cur_node.right,cur_sum + cur_node.val])

            if cur_node.left:
                stack.append([cur_node.left,cur_sum + cur_node.val])

        return False  
```

```python

```

## Optimal Solutions

---

The "Path Sum" problem is a classic tree traversal problem that asks whether there is a root-to-leaf path in a binary tree such that adding up all the values along the path equals a given number. This is typically solved using either depth-first search (DFS) or breadth-first search (BFS) to traverse the tree and keep track of the sums.

### Problem Statement:

Given the root of a binary tree and an integer `targetSum`, return `true` if the tree has a root-to-leaf path such that adding up all the values along the path equals `targetSum`.

### Approach:

### Depth-First Search (DFS):

- Use a recursive strategy to explore each path from the root to the leaves.
- At each node, subtract the node's value from `targetSum`.
- If you reach a leaf node (a node with no children), check if the remaining `targetSum` equals the node's value.

### Code Example (Recursive DFS):

```python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False

        # Check if we're at a leaf node
        if not root.left and not root.right:
            return root.val == targetSum

        # Recursively check the left and right subtree
        return self.hasPathSum(root.left, targetSum - root.val) or \\
               self.hasPathSum(root.right, targetSum - root.val)

```

### Iterative DFS:

- Use a stack to simulate the recursion.
- Push tuples onto the stack containing a node and the remaining `targetSum` after subtracting the current node's value.
- Process each node by updating the remaining `targetSum` and checking if you reach a leaf node with a `targetSum` equal to the node's value.

### Code Example (Iterative DFS):

```python
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if not root:
            return False

        stack = [(root, targetSum - root.val)]
        while stack:
            node, curr_sum = stack.pop()

            # Check if the current node is a leaf and its value matches remaining sum
            if not node.left and not node.right and curr_sum == 0:
                return True

            # Process children
            if node.right:
                stack.append((node.right, curr_sum - node.right.val))
            if node.left:
                stack.append((node.left, curr_sum - node.left.val))

        return False

```

### Complexity Analysis:

- **Time Complexity**: \(O(n)\), where \(n\) is the number of nodes in the tree. Each node is visited once.
- **Space Complexity**: \(O(h)\) for recursive DFS, where \(h\) is the maximum height of the tree, which correlates to the call stack size. For iterative DFS, the space complexity also depends on the tree's height due to the stack used but typically also \(O(h)\).

These methods provide comprehensive solutions to the Path Sum problem, ensuring all scenarios, including edge cases with empty trees or single-node trees, are correctly handled.

## Notes

---

 

## Related Videos

---

[https://youtu.be/LSKQyOz_P8I](https://youtu.be/LSKQyOz_P8I)