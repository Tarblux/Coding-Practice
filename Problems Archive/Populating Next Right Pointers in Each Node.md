# Populating Next Right Pointers in Each Node

Problem: 116
Official Difficulty: medium
Feels Like : medium
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, linked list, tree
Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
Completed On : January 18, 2024
My Understanding: Fully Understand
Last Review: January 18, 2024
Days Since Review: 23

## Problem

---

You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

**Example 1:**

![https://assets.leetcode.com/uploads/2019/02/14/116_sample.png](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)

```
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation:Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

**Example 2:**

```
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 212 - 1]`.
- `1000 <= Node.val <= 1000`

**Follow-up:**

- You may only use constant extra space.
- The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

## My Solutions

---

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        
        dict = {}
        
        def linkski (node,level): 
            
            if not node : 
                
                return 
            
            if level not in dict : 
                
                dict[level] = []
            
            linkski(node.left,level + 1)
            
            dict[level].append(node)
            
            linkski(node.right,level + 1)
            
        linkski(root,0)
        
        for lvl in dict : 
            
            nodes = dict[lvl]
            
            for i in range (0,len(nodes)-1): 
                
                nodes[i].next = nodes[i+1]
                
        return root
```

```python

```

## Optimal Solutions

---

The problem "Populating Next Right Pointers in Each Node" is a classic tree manipulation problem where you are given a perfect binary tree (i.e., all leaves are at the same level, and every parent has two children) and asked to populate each `next` pointer to point to its next right node. If there is no next right node, the `next` pointer should be set to `NULL`. Initially, all `next` pointers are set to `NULL`.

### Solution Approach

Since the given tree is a perfect binary tree, we can utilize its properties to solve the problem efficiently without additional space (i.e., without using a queue or dictionary).

1. **Iterate Level by Level**: Start from the root and set the `next` pointers for each level. Once `next` pointers are set for a level, they can be used to traverse that level and set `next` pointers for the next level.
2. **Link Children of Each Node**: For each node, link its left child's `next` to its right child. If the node's `next` is not null, link the node's right child's `next` to the node's `next`'s left child.
3. **Move to the Next Level**: After setting `next` pointers for one level, move to the next level by going to the leftmost child of the current level.

### Python Implementation

Here's how you can implement this solution:

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None

        leftmost = root

        while leftmost.left:
            head = leftmost
            while head:
                # Link the children of the head node
                head.left.next = head.right
                if head.next:
                    head.right.next = head.next.left

                # Move to the next node in the current level
                head = head.next

            # Move to the next level
            leftmost = leftmost.left

        return root
```

### Explanation

- Start with the `leftmost` node of each level (initially the root).
- For each level, iterate through all nodes using the `head` pointer.
- Connect the `left` child's `next` to the `right` child for each `head`.
- If `head.next` is not null, connect the `right` child's `next` to `head.next.left`.
- After setting `next` pointers for one level, move `leftmost` to the next level by setting it to `leftmost.left`.

### Complexity Analysis

- **Time Complexity**: O(n), where `n` is the number of nodes in the tree. Each node is visited once.
- **Space Complexity**: O(1). The solution only uses constant extra space, making it more efficient than solutions that require additional data structures.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=U4hFQCa1Cq0&pp=ygUrUG9wdWxhdGluZyBOZXh0IFJpZ2h0IFBvaW50ZXJzIGluIEVhY2ggTm9kZQ%3D%3D](https://www.youtube.com/watch?v=U4hFQCa1Cq0&pp=ygUrUG9wdWxhdGluZyBOZXh0IFJpZ2h0IFBvaW50ZXJzIGluIEVhY2ggTm9kZQ%3D%3D)