# N-ary Tree Postorder Traversal

Problem: 590
Official Difficulty: easy
Feels Like : easy breazy
My Understanding: Fully Understand
Topic: Depth-First Search (DFS), Stack, tree
Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
Completed On : August 26, 2024
Last Review: August 26, 2024
Days Since Review: 6

## Problem

---

Given the `root` of an n-ary tree, return *the postorder traversal of its nodes' values*.

Nary-Tree input serialization is represented in their level order 
traversal. Each group of children is separated by the null value (See 
examples)

**Example 1:**

![https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
```

**Example 2:**

![https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `0 <= Node.val <= 104`
- The height of the n-ary tree is less than or equal to `1000`.

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## My Solutions

---

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:

    def __init__(self):
        self.output = []

    def postorder(self, root: 'Node') -> List[int]:

        if not root:
            return

        for node in root.children:
            self.postorder(node)

        self.output.append(root.val)

        return self.output
```

```python

```

## Optimal Solutions

---

### Approach

To perform a postorder traversal on an N-ary tree, you can use either a recursive or an iterative approach.

1. **Recursive Approach**:
    - Traverse all the children of the current node recursively.
    - After all children are traversed, visit the current node.
2. **Iterative Approach**:
    - Use a stack to simulate the recursion.
    - Postorder can be thought of as a modified preorder traversal (where you visit the root node after its children). You can reverse the order of children in a stack-based preorder traversal to achieve this.

### Recursive Implementation

```python
from typing import List

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        def traverse(node):
            if not node:
                return []
            result = []
            for child in node.children:
                result.extend(traverse(child))
            result.append(node.val)
            return result

        return traverse(root)

# Example usage
# Tree structure:
#     1
#   / | \\
#  3  2  4
# / \\
#5   6
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
sol = Solution()
print(sol.postorder(root))  # Output: [5, 6, 3, 2, 4, 1]

```

### Iterative Implementation

```python
from typing import List

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return []

        stack, output = [root], []

        while stack:
            node = stack.pop()
            output.append(node.val)
            stack.extend(node.children)  # Add children to the stack

        return output[::-1]  # Reverse the result to get the correct order

# Example usage
# Tree structure:
#     1
#   / | \\
#  3  2  4
# / \\
#5   6
root = Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])
sol = Solution()
print(sol.postorder(root))  # Output: [5, 6, 3, 2, 4, 1]

```

### Explanation

1. **Recursive Approach**:
    - The `traverse` function is called recursively on each child of the node.
    - After visiting all the children, the value of the current node is appended to the result list.
2. **Iterative Approach**:
    - The stack is used to mimic the call stack of the recursive approach.
    - The nodes are processed in a modified preorder manner, and the result is reversed at the end to achieve the postorder traversal.

### Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the number of nodes in the tree. Each node is visited exactly once.
- **Space Complexity**: `O(n)` for both approaches. In the worst case, the space required is proportional to the number of nodes, either due to the recursion stack (in the recursive approach) or the explicit stack (in the iterative approach).

Both approaches effectively traverse the N-ary tree in postorder and are efficient in terms of both time and space complexity.

## Notes

---

 

## Related Videos

---

[https://youtu.be/GMUI91_pDmM](https://youtu.be/GMUI91_pDmM)