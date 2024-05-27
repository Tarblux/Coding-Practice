# Count Good Nodes in Binary Tree

Problem: 1448
Official Difficulty: medium
Feels Like : medium
My Understanding: Needs Review
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
Completed On : May 22, 2024
Last Review: May 22, 2024
Days Since Review: 4

## Problem

---

Given a binary tree `root`, a node *X* in the tree is named **good** if in the path from root to *X* there are no nodes with a value *greater than* X.

Return the number of **good** nodes in the binary tree.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png](https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png)

```
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue aregood.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/04/02/test_sample_2.png](https://assets.leetcode.com/uploads/2020/04/02/test_sample_2.png)

```
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

**Example 3:**

```
Input: root = [1]
Output: 1
Explanation: Root is considered asgood.
```

**Constraints:**

- The number of nodes in the binary tree is in the range `[1, 10^5]`.
- Each node's value is between `[-10^4, 10^4]`.

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
    def goodNodes(self, root: TreeNode) -> int:

        def dfs(node,path,goodnodes):

            if not node:
                return 

            good = True
            for i in range(len(path)):
                if path[i] > node.val:
                    good = False
                    break
                
            if good:
                goodnodes.append(node.val)

            path.append(node.val)

            dfs(node.left,path,goodnodes)
            dfs(node.right,path,goodnodes)

            path.pop()

        path = []
        goodnodes = []

        dfs(root,path,goodnodes)

        return len(goodnodes)

        
```

```python

```

## Optimal Solutions

---

### Problem Description

Given a binary tree root, a node X in the tree is named good if in the path from root to X, there are no nodes with a value greater than X. Return the number of good nodes in the binary tree.

### Example

```python
Input: root = [3, 1, 4, 3, None, 1, 5]
Output: 4

Explanation:
Nodes in the path [3], [3, 1], [3, 4], and [3, 4, 5] are good.
```

### Optimal Solution and Explanation

To solve this problem, we can use a depth-first search (DFS) approach. We keep track of the maximum value encountered on the path from the root to the current node. A node is considered good if its value is greater than or equal to this maximum value.

### Recursive Solution

Here's the Python code for the recursive solution:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def goodNodes(root):
    def dfs(node, max_val):
        if not node:
            return 0
        # A node is good if its value is greater than or equal to the max value seen so far
        good = 1 if node.val >= max_val else 0
        # Update the max value for the path to the current node
        max_val = max(max_val, node.val)
        # Continue DFS traversal
        good += dfs(node.left, max_val)
        good += dfs(node.right, max_val)
        return good

    return dfs(root, root.val)

# Example usage
# Construct the tree: root = [3, 1, 4, 3, None, 1, 5]
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.left = TreeNode(3)
root.right.left = TreeNode(1)
root.right.right = TreeNode(5)

print(goodNodes(root))  # Output: 4
```

### Explanation

1. **Initialize**: Start with the root node and set its value as the initial maximum value.
2. **DFS Traversal**:
    - For each node, check if its value is greater than or equal to the maximum value seen so far on the path.
    - If it is, count it as a good node.
    - Update the maximum value for the current path.
    - Recursively count the good nodes in the left and right subtrees.
3. **Return the total count of good nodes**.

### Explain Like I'm Five (ELI5)

Imagine you are walking through a mountain range, starting from the base. You keep track of the highest peak you've seen so far:

1. **Good peaks**: Every time you reach a new peak, you check if it’s taller than all the peaks you've seen before.
2. **Count good peaks**: If it is, you count it as a good peak because it stands out from all the previous ones.
3. **Continue climbing**: As you keep climbing, you always compare each new peak with the highest one you've seen so far.

By doing this, you can count all the peaks that are "good" because they are taller than all the peaks before them on your path.

## Notes

---

 

## Related Videos

---

[https://youtu.be/7cp5imvDzl4](https://youtu.be/7cp5imvDzl4)