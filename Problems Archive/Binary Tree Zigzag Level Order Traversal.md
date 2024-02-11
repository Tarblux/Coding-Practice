# Binary Tree Zigzag Level Order Traversal

Problem: 103
Official Difficulty: medium
Feels Like : medium
Topic: Breadth-First Search(BFS), tree
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
Completed On : January 16, 2024
My Understanding: Needs Review
Last Review: January 16, 2024
Days Since Review: 25

## Problem

---

Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
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
- `100 <= Node.val <= 100`

## My Solutions

---

Not Really Mine , GPT help kraff it

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        def ziggy(node, level, level_dict):
            
            if not node:
                
                return

            if level not in level_dict:
                
                level_dict[level] = []
                
            level_dict[level].append(node.val)

            ziggy(node.left, level + 1, level_dict)
            
            ziggy(node.right, level + 1, level_dict)

        level_dict = {}
        
        ziggy(root, 0, level_dict)

        result = []
        
        for level in level_dict:
            
            if level % 2 == 0:
                
                result.append(level_dict[level])
                
            else:
                
                result.append(level_dict[level][::-1])

        return result
```

Zwea (Iterative)

```python
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
            
        result = []
        level = 1
        fringe = [(root, level)] # to keep track of unvisited nodes
        
        while fringe:
            parent, level = fringe.pop()
            
						# if current level has not been added to the result,
						# create a new empty array 
            if len(result) < level:
                result.append([])
            
						# if node at even levels, add values in reverse order
            if level % 2 == 0:
                result[level-1].append(parent.val)
            else:
                result[level-1].insert(0, parent.val)
               
            if parent.left:
                fringe.append((parent.left, level+1))
            
            if parent.right:
                fringe.append((parent.right, level+1))
                
        return result
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=igbboQbiwqw](https://www.youtube.com/watch?v=igbboQbiwqw)