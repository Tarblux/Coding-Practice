# Linked List in Binary Tree

Problem: 1367
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand, Needs Review
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, linked list, tree
Link: https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=daily-question&envId=2024-09-07
Completed On : September 6, 2024
Last Review: September 6, 2024
Days Since Review: 2

## Problem

---

Given a binary tree `root` and a linked list with `head` as the first node.

Return True if all the elements in the linked list starting from the `head` correspond to some *downward path* connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/02/12/sample_1_1720.png](https://assets.leetcode.com/uploads/2020/02/12/sample_1_1720.png)

```
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/02/12/sample_2_1720.png](https://assets.leetcode.com/uploads/2020/02/12/sample_2_1720.png)

```
Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
```

**Example 3:**

```
Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list fromhead.

```

**Constraints:**

- The number of nodes in the tree will be in the range `[1, 2500]`.
- The number of nodes in the list will be in the range `[1, 100]`.
- `1 <= Node.val <= 100` for each node in the linked list and binary tree.

## My Solutions

---

Time Limit Exceeded

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def __init__(self):
        self.found = False

    def dfs(self,node,head):

        if not head:
            self.found = True
            return

        if not node or self.found:
            return

        if node.val == head.val:
            self.dfs(node.left,head.next)
            self.dfs(node.right,head.next)

        if not self.found:
            self.dfs(node.left,head)
            self.dfs(node.right,head)

    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:

        self.dfs(root,head)

        return self.found

        
        
```

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def __init__(self):
        self.visited = set() 

    def dfs(self, node, head):

        if not head:
            return True
        if not node:
            return False

        if (node, head) in self.visited:
            return False

        self.visited.add((node, head))

        if node.val == head.val:
            if self.dfs(node.left, head.next) or self.dfs(node.right, head.next):
                return True

        return False

    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        if not root:
            return False

        # Check if the list starts from the current root, or from any node in the left or right subtrees
        if self.dfs(root, head):
            return True
            
        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://youtu.be/OaA9MgG00AE](https://youtu.be/OaA9MgG00AE)