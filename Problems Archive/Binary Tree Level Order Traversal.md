# Binary Tree Level Order Traversal

Problem: 102
Official Difficulty: medium
Feels Like : medium
Topic: Breadth-First Search(BFS), tree
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
Completed On : January 17, 2024
My Understanding: Mostly Understand
Last Review: January 17, 2024
Days Since Review: 24

## Problem

---

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `1000 <= Node.val <= 1000`

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
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        dict = {}
        
        if not root : 
            
            return []
       
        def travis(node,level,dict) : 
            
            if not node : 
                
                return
            
            if level not in dict : 
                
                dict[level] = []
                
            dict[level].append(node.val)
            
            travis(node.left,level + 1 , dict)
        
            travis(node.right,level + 1 , dict)
        
            return dict
        
        output_dict = travis(root,0,dict)
        
        output = []
        
        for level in output_dict : 
            
            output.append(output_dict[level])
            
        return output
```

```python

```

## Optimal Solutions

---

### Problem Statement

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

### Solution Approach: Using Queue

The most efficient way to perform level order traversal is by using a queue (FIFO data structure). You start by enqueuing the root and then process nodes level by level, enqueuing their child nodes as you go.

### Python Implementation

Assuming you have a TreeNode class defined as follows:

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

```

Here's an implementation using a queue:

```python
from collections import deque

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        result = []
        queue = deque([root])

        while queue:
            level_size = len(queue)
            level = []

            for _ in range(level_size):
                node = queue.popleft()
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(level)

        return result

```

### Explanation

- Initialize a queue and add the root to it.
- While the queue is not empty, process each level of the tree:
    - Determine the number of nodes at the current level (`level_size`).
    - For each node at this level, remove it from the queue, add its value to the current level's list, and add its children to the queue.
- After processing all nodes at the current level, add the level's list to the result.
- Continue until the queue is empty, indicating that all levels have been processed.

### Complexity Analysis

- **Time Complexity**: O(n), where n is the number of nodes in the tree. Each node is visited exactly once.
- **Space Complexity**: O(n), for the queue. In the worst-case scenario (a complete binary tree), the queue can contain all nodes of the last level, which is roughly n/2 nodes.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=6ZnyEApgFYg&pp=ygUhQmluYXJ5IFRyZWUgTGV2ZWwgT3JkZXIgVHJhdmVyc2Fs](https://www.youtube.com/watch?v=6ZnyEApgFYg&pp=ygUhQmluYXJ5IFRyZWUgTGV2ZWwgT3JkZXIgVHJhdmVyc2Fs)