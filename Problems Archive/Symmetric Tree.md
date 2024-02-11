# Symmetric Tree

Problem: 101
Official Difficulty: easy
Feels Like : medium
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), tree
Link: https://leetcode.com/problems/symmetric-tree/description/
Completed On : January 17, 2024
My Understanding: Mostly Understand
Last Review: January 17, 2024
Days Since Review: 24

## Problem

---

Given the `root` of a binary tree, *check whether it is a mirror of itself* (i.e., symmetric around its center).

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)

```
Input: root = [1,2,2,3,4,4,3]
Output: true
```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)

```
Input: root = [1,2,2,null,3,null,3]
Output: false
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `100 <= Node.val <= 100`

**Follow up:**

Could you solve it both recursively and iteratively?

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
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        
        a = [1,2,3]
        
        
        def travis(node,level,dict) : 
            
            if level not in dict : 
                
                dict[level] = []
            
            if not node : 
                
                dict[level].append('null')
                
                return
  
            dict[level].append(node.val)
                
            travis(node.left , level + 1 , dict)  
                
            travis(node.right , level + 1 , dict)
            
            return dict
        
        dict = {}
        
        dict2 = travis(root,0,dict)
        
        
        for lvl in dict2 : 
            
            if lvl != 0 :

                mid = len(dict[lvl]) // 2

                length = len(dict[lvl])

                if dict[lvl][0:mid] != dict[lvl][mid:length][::-1] :

                    return False
            
        return True
```

```python

```

## Optimal Solutions

---

The "Symmetric Tree" problem is a common binary tree problem where you need to determine if a binary tree is a mirror of itself (i.e., symmetric around its center). This can be approached both iteratively and recursively.

### Problem Statement

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

### Recursive Solution

A tree is symmetric if the left subtree is a mirror reflection of the right subtree. Therefore, the problem can be reduced to whether two trees are mirror images of each other. Two trees are a mirror reflection of each other if:

1. Their two roots have the same value.
2. The right subtree of each tree is a mirror reflection of the left subtree of the other tree.

### Python Implementation

```python
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def isMirror(t1, t2):
            if not t1 and not t2:
                return True
            if not t1 or not t2:
                return False
            return (t1.val == t2.val) and isMirror(t1.right, t2.left) and isMirror(t1.left, t2.right)

        return isMirror(root, root)
```

### Iterative Solution

The iterative solution uses a queue. Each two consecutive nodes in the queue should be equal, and their subtrees a mirror of each other. Initially, the queue contains the root and the root. Then, at each step, two nodes are extracted and their values compared. Then, their left and right children are inserted in the queue in opposite order.

### Python Implementation

```python
from collections import deque

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        queue = deque([root, root])

        while queue:
            t1 = queue.popleft()
            t2 = queue.popleft()

            if not t1 and not t2:
                continue
            if not t1 or not t2:
                return False
            if t1.val != t2.val:
                return False

            queue.append(t1.left)
            queue.append(t2.right)
            queue.append(t1.right)
            queue.append(t2.left)

        return True
```

### Complexity Analysis for Both Approaches

- **Time Complexity**: O(n), where n is the number of nodes in the tree. Each node is visited/traversed once.
- **Space Complexity**:
    - Recursive: O(h), where h is the height of the tree. The recursion stack can go up to h levels deep.
    - Iterative: O(n), for the queue. In the worst case, the queue can contain all nodes at a level of the binary tree (up to n/2).

Both approaches are effective for determining if a binary tree is symmetric. The choice between recursive and iterative methods depends on personal preference and specific constraints like tree height or memory limitations.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=Mao9uzxwvmc&pp=ygUXc3ltbWV0cmljIHRyZWUgbGVldGNvZGU%3D](https://www.youtube.com/watch?v=Mao9uzxwvmc&pp=ygUXc3ltbWV0cmljIHRyZWUgbGVldGNvZGU%3D)