# Step-By-Step Directions From a Binary Tree Node to Another

Problem: 2096
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: Depth-First Search (DFS), binary tree, string, tree
Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
Completed On : August 9, 2024
Last Review: August 9, 2024
Days Since Review: 0

## Problem

---

You are given the `root` of a **binary tree** with `n` nodes. Each node is uniquely assigned a value from `1` to `n`. You are also given an integer `startValue` representing the value of the start node `s`, and a different integer `destValue` representing the value of the destination node `t`.

Find the **shortest path** starting from node `s` and ending at node `t`. Generate step-by-step directions of such path as a string consisting of only the **uppercase** letters `'L'`, `'R'`, and `'U'`. Each letter indicates a specific direction:

- `'L'` means to go from a node to its **left child** node.
- `'R'` means to go from a node to its **right child** node.
- `'U'` means to go from a node to its **parent** node.

Return *the step-by-step directions of the **shortest path** from node* `s` *to node* `t`.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/11/15/eg1.png](https://assets.leetcode.com/uploads/2021/11/15/eg1.png)

```
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/11/15/eg2.png](https://assets.leetcode.com/uploads/2021/11/15/eg2.png)

```
Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
```

**Constraints:**

- The number of nodes in the tree is `n`.
- `2 <= n <= 105`
- `1 <= Node.val <= n`
- All the values in the tree are **unique**.
- `1 <= startValue, destValue <= n`
- `startValue != destValue`

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
    def dfs(self, node, path, target):
        if not node:
            return ''

        if node.val == target:
            return path 

        path.append('L')
        left = self.dfs(node.left, path, target)
        if left:
            return left

        path.pop()
        path.append('R')
        right = self.dfs(node.right, path, target)
        if right:
            return right

        path.pop()
        return ''

    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        s_path = self.dfs(root, [], startValue)
        d_path = self.dfs(root, [], destValue)

        divergence_index = 0
        for a, b in zip(s_path, d_path):
            if a != b:
                break
            divergence_index += 1

        up_moves = 'U' * (len(s_path) - divergence_index)

        down_moves = ''.join(d_path[divergence_index:])

        return up_moves + down_moves

```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def findPath(self,node,path,target):

        if not node:
            return False

        if node.val == target:
            return path

        path.append('L')
        left = self.findPath(node.left,path,target)
        if left:
            return left
        path.pop()

        path.append('R')
        right = self.findPath(node.right,path,target)
        if right:
            return right
        path.pop()

        return False
        
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:

        output = ''

        s_path = self.findPath(root,[],startValue)
        t_path = self.findPath(root,[],destValue)

        divergence_index = 0 # basically just LCA position

        for a , b in zip(s_path,t_path):

            if a != b:
                break

            divergence_index += 1

        for i in range(divergence_index,len(s_path)):
            output += 'U'

        return output + ''.join(t_path[divergence_index:])

```

## Optimal Solutions

---

### Problem Description

You are given the root of a binary tree with `n` nodes. Each node is uniquely labeled from `1` to `n`. You are also given two integers, `startValue` and `destValue`, representing the starting and destination nodes.

Your task is to return the step-by-step directions from the node with value `startValue` to the node with value `destValue`. The directions are represented by the characters `'L'` (left), `'R'` (right), and `'U'` (up).

### Example

```python
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"

Explanation:
- The path from node 3 to the root is "U".
- The path from node 6 to the root is "UR".
- Combining these gives "U" to go up to the root from node 3, and "URL" to go down to node 6.

```

### Solution Approach

To solve this problem, follow these steps:

1. **Find the Lowest Common Ancestor (LCA)**:
    - The lowest common ancestor of two nodes is the deepest node that is an ancestor of both nodes. It can be found using a recursive approach.
2. **Find Paths**:
    - Find the path from the LCA to the `startValue` node and the path from the LCA to the `destValue` node. These paths will help us determine how many 'U' moves are needed and how to reach the destination node.
3. **Combine Paths**:
    - The steps from `startValue` to `destValue` will consist of:
        - Moving up from `startValue` to the LCA (each move is represented by 'U').
        - Moving down from the LCA to `destValue` by following the path from the LCA to `destValue`.

### Python Code

Here’s the Python code to implement the solution:

```python
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findLCA(self, root: TreeNode, p: int, q: int) -> TreeNode:
        if not root or root.val == p or root.val == q:
            return root
        left = self.findLCA(root.left, p, q)
        right = self.findLCA(root.right, p, q)
        if left and right:
            return root
        return left if left else right

    def findPath(self, root: TreeNode, target: int, path: list) -> bool:
        if not root:
            return False
        if root.val == target:
            return True
        path.append('L')
        if self.findPath(root.left, target, path):
            return True
        path.pop()

        path.append('R')
        if self.findPath(root.right, target, path):
            return True
        path.pop()

        return False

    def getDirections(self, root: TreeNode, startValue: int, destValue: int) -> str:
        # Find the Lowest Common Ancestor (LCA)
        lca = self.findLCA(root, startValue, destValue)

        # Find the path from LCA to startValue and destValue
        startPath = []
        destPath = []
        self.findPath(lca, startValue, startPath)
        self.findPath(lca, destValue, destPath)

        # The path from startValue to destValue is the path from startValue to LCA
        # (which is all 'U') followed by the path from LCA to destValue.
        return 'U' * len(startPath) + ''.join(destPath)

# Example usage
root = TreeNode(5)
root.left = TreeNode(1)
root.right = TreeNode(2)
root.left.left = TreeNode(3)
root.right.left = TreeNode(6)
root.right.right = TreeNode(4)

sol = Solution()
print(sol.getDirections(root, 3, 6))  # Output: "UURL"

```

### Explanation

1. **Finding the LCA**:
    - The `findLCA` function is used to find the lowest common ancestor of `startValue` and `destValue`. The LCA is the deepest node that is an ancestor of both nodes.
2. **Finding Paths**:
    - The `findPath` function is used to determine the path from the LCA to a given target node (`startValue` or `destValue`). The path is stored as a list of directions ('L' for left and 'R' for right).
3. **Combining the Paths**:
    - To get from `startValue` to `destValue`, you first move up to the LCA (using 'U' for each step in `startPath`), then follow the path from the LCA to `destValue` using the steps stored in `destPath`.

### Time Complexity Analysis

- **Time Complexity**: `O(n)`
    - The LCA finding and path-finding operations both traverse the tree, so the total time complexity is proportional to the number of nodes in the tree.
- **Space Complexity**: `O(h)`
    - The space complexity is dominated by the recursion stack, which can go up to the height of the tree (`h`), and the paths which also can be of length `h`.

This approach efficiently finds the path between two nodes in a binary tree using a combination of the LCA and path-tracking techniques.

## Notes

---

 very similar to common LCA tree question

## Related Videos

---

[https://www.youtube.com/watch?v=JegJNGcwtFg](https://www.youtube.com/watch?v=JegJNGcwtFg)