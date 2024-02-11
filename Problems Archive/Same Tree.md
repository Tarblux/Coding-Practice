# Same Tree

Problem: 100
Official Difficulty: easy
Feels Like : easy
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/same-tree/description/?source=submission-noac
Completed On : February 10, 2024
My Understanding: Mostly Understand
Last Review: February 10, 2024
Days Since Review: 0

## Problem

---

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)

```
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)

```
Input: p = [1,2], q = [1,null,2]
Output: false
```

**Example 3:**

![https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)

```
Input: p = [1,2,1], q = [1,1,2]
Output: false
```

**Constraints:**

- The number of nodes in both trees is in the range `[0, 100]`.
- `104 <= Node.val <= 104`

## My Solutions

---

This was my first solution but it doesn’t work for a slightly nuanced reason ,explained at the end

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:

        array = []

        array_2 = []

        def inOrderTraversal (array,node):

            if not node : 

                return 

            inOrderTraversal(array,node.left)

            array.append(node.val)

            inOrderTraversal(array,node.right)

            return array

        return inOrderTraversal(array,p) == inOrderTraversal(array_2,q)
```

Correct Implementation

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:

        array_p = []

        array_q = []

        def inOrderTraversal (array,node):

            if not node : 

                array.append(None)

                return 

            array.append(node.val)

            inOrderTraversal(array,node.left)

            inOrderTraversal(array,node.right)

            return array

        return inOrderTraversal(array_p,p) == inOrderTraversal(array_q,q)
```

The key difference between the two code snippets you provided lies in the traversal order used to visit the nodes of the trees. The first code snippet uses a pre-order traversal, while the second one uses an in-order traversal. Let's break down why the pre-order traversal method works for comparing tree structure and values, and why the in-order traversal might not always work.

### Pre-order Traversal (Works)

In the first snippet, the traversal is done in a pre-order manner: it visits the node first, then recursively visits the left subtree, and finally, the right subtree. This approach captures the structure of the tree in the sequence in which nodes are visited because it starts with the root and follows each branch before moving to the next one. By including `None` for missing nodes, it ensures that even trees with different structures result in different arrays. Therefore, comparing the arrays generated from a pre-order traversal (with `None` placeholders for missing nodes) is a reliable way to determine if two trees are structurally identical and contain the same values in the same positions.

### In-order Traversal (Might Not Work for Structure)

In the second snippet, the traversal is done in an in-order manner: it first recursively visits the left subtree, then visits the node, and finally, the right subtree. While this approach correctly captures the ascending order of values for binary search trees, it may not reliably capture the structure of the tree because it focuses on the order of values rather than the tree's branching structure. Two different trees can produce the same in-order traversal sequence if they contain the same values, even if their structures are different. This is especially true if the trees have different shapes but the same set of values arranged to yield the same in-order sequence.

For example, consider these two trees:

```
    1            1
   /              \
  2                2
```

Both will have the same in-order traversal `[2, 1]`, but they are clearly not the same tree. However, their pre-order traversals would be `[1, 2]` and `[1, None, 2]`, differentiating them effectively.

### Conclusion

The reason the first method works for comparing if two binary trees are the same (in both structure and value) is that pre-order traversal captures both the structure and the values of the tree in the way it sequences the node visits and includes `None` for missing branches. In contrast, in-order traversal may only reliably compare the values in some cases and can fail to distinguish trees with different structures but similar values arranged in a way that results in the same in-order sequence.

## Optimal Solutions

---

### Problem Statement

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

### Solution Approach

A straightforward approach to solving this problem is to use recursion. You need to compare the value of the current node of both trees and then recursively check the left and right subtrees.

### Python Implementation

Here is how you could implement the solution:

```python
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        # If both nodes are None, the trees are identical at this branch
        if not p and not q:
            return True
        # If one node is None and the other isn't, trees aren't identical
        if not p or not q:
            return False
        # If the values of the current nodes are different, trees aren't identical
        if p.val != q.val:
            return False
        # Recursively check the left and right subtrees
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

```

### Explanation

- **Base Cases**:
    - If both nodes `p` and `q` are `None`, it means that we've reached the leaf nodes of both trees in this path, and so far, they are identical. Therefore, return `True`.
    - If one of the nodes is `None` and the other is not, it means the trees differ structurally in this path. Therefore, return `False`.
- **Value Comparison**: If the values of `p` and `q` differ, the trees are not identical. Return `False`.
- **Recursive Calls**: The function calls itself twice: once for the left child nodes of `p` and `q`, and once for the right child nodes. This checks the entire structure and values of the trees.
- The trees are considered identical if all the checks pass, meaning both the structure and node values are the same.

### Complexity Analysis

- **Time Complexity**: O(N), where N is the number of nodes in the tree. In the worst case, you have to visit all nodes to confirm they are identical.
- **Space Complexity**: O(log(N)) in the best case of completely balanced trees and O(N) in the worst case of completely unbalanced trees, to keep a recursion stack.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=vRbbcKXCxOw](https://www.youtube.com/watch?v=vRbbcKXCxOw)