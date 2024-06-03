# Construct Binary Tree from In order and Preorder Traversal

Problem: 105
Official Difficulty: medium
Feels Like : Brain Damage
My Understanding: Needs Review
Topic: Divide and Conquer, array, binary tree, hash table, tree
Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
Completed On : May 27, 2024
Last Review: May 27, 2024
Days Since Review: 7

## Problem

---

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the in order traversal of the same tree, construct and return *the binary tree*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/19/tree.jpg](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

```

**Example 2:**

```
Input: preorder = [-1], inorder = [-1]
Output: [-1]

```

**Constraints:**

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `3000 <= preorder[i], inorder[i] <= 3000`
- `preorder` and `inorder` consist of **unique** values.
- Each value of `inorder` also appears in `preorder`.
- `preorder` is **guaranteed** to be the preorder traversal of the tree.
- `inorder` is **guaranteed** to be the inorder traversal of the tree.

## My Solutions

---

Straight from neetcode , Just one of them where you have to just memorize it I think

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

        if not preorder or not inorder:
            return None

        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])

        root.left = self.buildTree(preorder[1:mid+1],inorder[:mid])
        root.right = self.buildTree(preorder[mid+1:],inorder[mid+1:])

        return root
```

```python

```

## Optimal Solutions

---

### Problem Description

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.

### Example

```python
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Explanation:
The binary tree is as follows:
    3
   / \\
  9  20
    /  \\
   15   7

```

### Optimal Solution and Explanation

To construct the binary tree from the given preorder and inorder traversal arrays, we can use a recursive approach. The preorder traversal gives us the root of the tree, and the inorder traversal helps us determine the left and right subtrees.

### Steps:

1. **Identify the root**: The first element in the preorder array is the root of the tree.
2. **Find the root in the inorder array**: This helps us divide the inorder array into left and right subtrees.
3. **Recursive Construction**:
    - Recursively build the left subtree using the elements before the root in the inorder array.
    - Recursively build the right subtree using the elements after the root in the inorder array.

### Python Code

Here’s the Python code to achieve this:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(preorder, inorder):
    if not preorder or not inorder:
        return None

    # The first element in preorder is the root
    root_val = preorder[0]
    root = TreeNode(root_val)

    # Find the index of the root in inorder
    mid = inorder.index(root_val)

    # Recursively build the left and right subtrees
    root.left = buildTree(preorder[1:mid+1], inorder[:mid])
    root.right = buildTree(preorder[mid+1:], inorder[mid+1:])

    return root

# Example usage
preorder = [3, 9, 20, 15, 7]
inorder = [9, 3, 15, 20, 7]

def printTree(root):
    """Helper function to print the tree level-order"""
    if not root:
        return []
    result, queue = [], [root]
    while queue:
        current_level_values = []
        next_queue = []
        for node in queue:
            if node:
                current_level_values.append(node.val)
                next_queue.append(node.left)
                next_queue.append(node.right)
            else:
                current_level_values.append(None)
        if any(current_level_values):
            result.append(current_level_values)
        queue = next_queue
    return result

root = buildTree(preorder, inorder)
print(printTree(root))  # Output: [[3], [9, 20], [None, None, 15, 7]]

```

### Explanation

1. **Base Case**: If the `preorder` or `inorder` array is empty, return `None`.
2. **Identify the Root**: The first element of the `preorder` array is the root node (`root_val`).
3. **Find the Root in Inorder Array**: Find the index of `root_val` in the `inorder` array (`mid`). This splits the `inorder` array into the left subtree (`inorder[:mid]`) and the right subtree (`inorder[mid+1:]`).
4. **Recursive Construction**:
    - The left subtree's `preorder` array is `preorder[1:mid+1]` and its `inorder` array is `inorder[:mid]`.
    - The right subtree's `preorder` array is `preorder[mid+1:]` and its `inorder` array is `inorder[mid+1:]`.
5. **Construct the Tree**: Create the `root` node and recursively construct its left and right children.

### Explain Like I'm Five (ELI5)

Imagine you have a set of building instructions (preorder) and a layout plan (inorder) to build a toy castle.

1. **Identify the Main Part**: The first instruction tells you which part to build first (the root).
2. **Find the Main Part in the Layout**: Look for this main part in your layout plan. This helps you split the plan into two sections: the left section (left subtree) and the right section (right subtree).
3. **Build Step-by-Step**:
    - Follow the next set of instructions to build the left side using the left section of the layout.
    - Then, follow the instructions to build the right side using the right section of the layout.

By doing this recursively, you can build the entire toy castle step by step, following the instructions and the layout plan!

## Notes

---

 

## Related Videos

---

[https://youtu.be/ihj4IQGZ2zc](https://youtu.be/ihj4IQGZ2zc)