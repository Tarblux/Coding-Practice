# Lowest Common Ancestor of BST

Problem: 235
Official Difficulty: medium
Feels Like : medium
My Understanding: Mostly Understand
Topic: Depth-First Search (DFS), binary search tree, binary tree, tree
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
Completed On : May 23, 2024
Last Review: May 23, 2024
Days Since Review: 3

## Problem

---

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**

![https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png](https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png)

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
```

**Example 3:**

```
Input: root = [2,1], p = 2, q = 1
Output: 2
```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 105]`.
- `109 <= Node.val <= 109`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the BST.

## My Solutions

---

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        p_path = []
        q_path = []

        cur_p = root
        cur_q = root

        while cur_p:

            p_path.append(cur_p)

            if p.val < cur_p.val:
                cur_p = cur_p.left
            elif p.val > cur_p.val:
                cur_p = cur_p.right
            else:
                break

        while cur_q:

            q_path.append(cur_q)

            if q.val < cur_q.val:
                cur_q = cur_q.left
            elif q.val > cur_q.val:
                cur_q = cur_q.right
            else:
                break

        lca = None

        for p_node , q_node in zip(p_path,q_path):

            if p_node == q_node:
                lca = p_node

        return lca
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def find_path(root, target):
            path = []
            node = root
            while node:
                path.append(node)
                if target.val < node.val:
                    node = node.left
                elif target.val > node.val:
                    node = node.right
                else:
                    break
            return path
        
        p_path = find_path(root, p)
        q_path = find_path(root, q)
        
        lca = None
        
        for p_node, q_node in zip(p_path, q_path):
            if p_node == q_node:
                lca = p_node
            else:
                break
        
        return lca
        
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        if p.val > q.val:
            p, q = q, p

        while True:
            while root.val > q.val:
                root = root.left

            while root.val < p.val:
                root = root.right

            if not root.left or root.left.val < q.val:
                break

        return root
```

## Optimal Solutions

---

### Problem Description

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. The LCA of two nodes `p` and `q` is defined as the lowest node that has both `p` and `q` as descendants (where we allow a node to be a descendant of itself).

### Example

```python
Input: root = [3,5,1,6,2,0,8,None,None,7,4], p = 5, q = 1
Output: 3

Input: root = [3,5,1,6,2,0,8,None,None,7,4], p = 5, q = 4
Output: 5
```

### Optimal Solution and Explanation

To solve this problem, we can use a recursive approach. The idea is to traverse the tree and return the node if it matches either `p` or `q`. If a node is found such that one of `p` or `q` is in its left subtree and the other is in its right subtree, then that node is the LCA.

### Recursive Solution

Here’s the Python code for the recursive solution:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def lowestCommonAncestor(root, p, q):
    if not root or root == p or root == q:
        return root

    left = lowestCommonAncestor(root.left, p, q)
    right = lowestCommonAncestor(root.right, p, q)

    if left and right:
        return root

    return left if left else right

# Example usage
# Construct the tree: root = [3,5,1,6,2,0,8,None,None,7,4]
root = TreeNode(3)
root.left = TreeNode(5)
root.right = TreeNode(1)
root.left.left = TreeNode(6)
root.left.right = TreeNode(2)
root.right.left = TreeNode(0)
root.right.right = TreeNode(8)
root.left.right.left = TreeNode(7)
root.left.right.right = TreeNode(4)

p = root.left  # Node with value 5
q = root.right  # Node with value 1

print(lowestCommonAncestor(root, p, q).val)  # Output: 3

p = root.left  # Node with value 5
q = root.left.right.right  # Node with value 4

print(lowestCommonAncestor(root, p, q).val)  # Output: 5
```

### Explanation

1. **Base Case**: If the current node is `None`, `p`, or `q`, return the current node.
2. **Recursive Case**:
    - Recursively call the function on the left subtree.
    - Recursively call the function on the right subtree.
    - If both left and right calls return non-`None` values, it means `p` and `q` are found in different subtrees, and the current node is their LCA.
    - If only one of the calls returns a non-`None` value, return that value as it indicates both `p` and `q` are in the same subtree.

### Explain Like I'm Five (ELI5)

Imagine you're playing hide and seek with your friends in a big house. You need to find the common room where two of your friends are hiding. You start searching from the main entrance:

1. **Check each room**: If you find one of your friends in the current room, remember this room.
2. **Search left and right**: Check the rooms to the left and right.
3. **Common room**: If you find one friend on the left and one on the right, the current room is the common room where you can meet both of them.
4. **Same direction**: If both friends are in the same direction (both left or both right), keep following that direction.

By using this method, you can efficiently find the common room where both of your friends are hiding.

## Notes

---

 

## Related Videos

---

[https://youtu.be/gs2LMfuOR9k](https://youtu.be/gs2LMfuOR9k)