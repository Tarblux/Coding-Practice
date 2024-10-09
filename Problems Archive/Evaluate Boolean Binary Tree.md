# Evaluate Boolean Binary Tree

Problem: 2331
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: binary tree
Link: https://leetcode.com/problems/evaluate-boolean-binary-tree/
Completed On : May 16, 2024
Last Review: May 16, 2024
Days Since Review: 3

## Problem

---

You are given the `root` of a **full binary tree** with the following properties:

- **Leaf nodes** have either the value `0` or `1`, where `0` represents `False` and `1` represents `True`.
- **Non-leaf nodes** have either the value `2` or `3`, where `2` represents the boolean `OR` and `3` represents the boolean `AND`.

The **evaluation** of a node is as follows:

- If the node is a leaf node, the evaluation is the **value** of the node, i.e. `True` or `False`.
- Otherwise, **evaluate** the node's two children and **apply** the boolean operation of its value with the children's evaluations.

Return *the boolean result of **evaluating** the* `root` *node.*

A **full binary tree** is a binary tree where each node has either `0` or `2` children.

A **leaf node** is a node that has zero children.

**Example 1:**

![https://assets.leetcode.com/uploads/2022/05/16/example1drawio1.png](https://assets.leetcode.com/uploads/2022/05/16/example1drawio1.png)

```
Input: root = [2,1,3,null,null,0,1]
Output: true
Explanation: The above diagram illustrates the evaluation process.
The AND node evaluates to False AND True = False.
The OR node evaluates to True OR False = True.
The root node evaluates to True, so we return true.
```

**Example 2:**

```
Input: root = [0]
Output: false
Explanation: The root node is a leaf node and it evaluates to false, so we return false.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `0 <= Node.val <= 3`
- Every node has either `0` or `2` children.
- Leaf nodes have a value of `0` or `1`.
- Non-leaf nodes have a value of `2` or `3`.

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
    def dfstraversal(self,node):

        if not node:
            return

        
        cur_val = node.val

        if not node.left:
            return cur_val

        left = self.dfstraversal(node.left)
        right = self.dfstraversal(node.right)

        return left or right if cur_val == 2 else left and right

        

    def evaluateTree(self, root: Optional[TreeNode]) -> bool:

        return self.dfstraversal(root)
        
```

```python

```

## Optimal Solutions

---

### Problem Description

You are given the root of a binary tree where each node has one of two possible values: `0` representing `False` and `1` representing `True`. Each node also has either two or zero children. If a node has two children, it represents a logical operator (AND `&` or OR `|`). You need to evaluate the Boolean value of the tree.

### Example

```python
Input: root = [2, 1, 3, None, None, 0, 1]
Output: True

```

Here, `2` represents OR (`|`), and `3` represents AND (`&`).

### Optimal Solution and Explanation

The optimal solution is to use a recursive function to evaluate the tree. Each node will perform its logical operation on the results of its children if it has any. If it is a leaf node, it simply returns its value.

Here's the Python code for this solution:

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def evaluateTree(root):
    if root.val in [0, 1]:  # Leaf node
        return bool(root.val)

    left_val = evaluateTree(root.left)
    right_val = evaluateTree(root.right)

    if root.val == 2:  # OR operation
        return left_val or right_val
    elif root.val == 3:  # AND operation
        return left_val and right_val

# Example usage
# Construct the tree: root = [2, 1, 3, None, None, 0, 1]
root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)
root.right.left = TreeNode(0)
root.right.right = TreeNode(1)

print(evaluateTree(root))  # Output: True

```

### Explanation

1. **Base Case**: If the node is a leaf node (value 0 or 1), return its Boolean value (`False` or `True`).
2. **Recursive Case**: If the node represents an operation:
    - Recursively evaluate the left child.
    - Recursively evaluate the right child.
    - Perform the operation (`OR` if value is 2, `AND` if value is 3) on the results from the left and right children.

### Explain Like I'm Five (ELI5)

Imagine you have a tree where each leaf (end) has either a light that is on (True) or off (False). Each branch in the tree can either say "at least one of my children must be on for me to be on" (OR) or "both of my children must be on for me to be on" (AND). You start at the top and follow the rules all the way down to the leaves to see if the light at the top is on or off.

1. **Leaves**: If you reach a light (0 or 1), it’s either on or off.
2. **Branches**: If you reach a branch:
    - If it says "at least one of my children must be on" (OR), check if either child’s light is on.
    - If it says "both of my children must be on" (AND), check if both children’s lights are on.
3. **Evaluate**: Follow this process until you reach the top light and see if it’s on or off.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=9a_cP54jn8Q&pp=ygUUZXZhbHVhdGUgYmluYXJ5IHRyZWU%3D](https://www.youtube.com/watch?v=9a_cP54jn8Q&pp=ygUUZXZhbHVhdGUgYmluYXJ5IHRyZWU%3D)