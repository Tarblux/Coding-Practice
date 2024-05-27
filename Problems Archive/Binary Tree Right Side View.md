# Binary Tree Right Side View

Problem: 199
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/binary-tree-right-side-view/description/
Completed On : May 20, 2024
Last Review: May 20, 2024
Days Since Review: 6

## Problem

---

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/02/14/tree.jpg](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

```

**Example 2:**

```
Input: root = [1,null,3]
Output: [1,3]

```

**Example 3:**

```
Input: root = []
Output: []

```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `100 <= Node.val <= 100`

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
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        if not root :
            return []

        queue = deque([(root,0)])
        level_dict = defaultdict(list)

        while queue:

            node , lvl = queue.popleft()
            level_dict[lvl].append(node.val)

            if node.left:
                queue.append((node.left, lvl + 1))

            if node.right:
                queue.append((node.right, lvl + 1))
                
        r_view = [level[-1] for level in level_dict.values()]
        
        return r_view
```

Sanayka

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        #level:(y_value, node_value)
        memo = dict()

        def dfs(node, level, fromLeft, prev_y):
            if not node:
                return

            y = 2 ** (100 - level)
            if fromLeft: y *= -1
            y += prev_y
            
            if level in memo:
                old_y_value = memo[level][0]
                if y > old_y_value:
                    memo[level] = (y, node.val)
            else:
                memo[level] = (y, node.val)
            
            dfs(node.left, level + 1, True, y)
            dfs(node.right, level + 1, False, y)

        dfs(root, 0, False, 0)

        result = []
        for key in memo:
            result.append(memo[key][1])
                
        return result
```

## Optimal Solutions

---

### Problem Description

Given the root of a binary tree, imagine you are standing on the right side of it. Return the values of the nodes you can see ordered from top to bottom.

### Example

```python
Input: root = [1, 2, 3, None, 5, None, 4]
Output: [1, 3, 4]

Explanation:
     1            <--- 1 is visible from the right side
   /   \\
  2     3         <--- 3 is visible from the right side
   \\     \\
    5     4       <--- 4 is visible from the right side

```

### Optimal Solution and Explanation

To solve this problem, we can use a breadth-first search (BFS) approach. The idea is to traverse the tree level by level, from right to left. For each level, we add the first node encountered to the result since it is the rightmost node for that level.

### Iterative Solution

Here's the Python code for the iterative solution using BFS:

```python
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def rightSideView(root):
    if not root:
        return []

    queue = deque([root])
    right_side = []

    while queue:
        level_length = len(queue)
        for i in range(level_length):
            node = queue.popleft()
            # If it's the rightmost element at this level
            if i == 0:
                right_side.append(node.val)
            # Add right child first, then left child
            if node.right:
                queue.append(node.right)
            if node.left:
                queue.append(node.left)

    return right_side

# Example usage
# Construct the tree: root = [1, 2, 3, None, 5, None, 4]
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.right = TreeNode(5)
root.right.right = TreeNode(4)

print(rightSideView(root))  # Output: [1, 3, 4]

```

### Explanation

1. **Initialize**: Use a queue to facilitate level-order traversal.
2. **Traverse the tree**:
    - For each level, record the first node (rightmost node due to right-to-left traversal).
    - Add the right child first, followed by the left child to the queue.
3. **Record rightmost nodes**: Append the first node of each level to the result list.

### Explain Like I'm Five (ELI5)

Imagine you're walking along the side of a row of tall buildings (the tree) and you want to list the names of the buildings you can see:

1. **Look from the side**: Walk along the side of the row.
2. **List the visible buildings**: At each step, note the tallest building you see in front of you.
3. **Keep going**: Move forward and do the same for the next set of buildings.

By doing this, you get a list of buildings that are visible from the side. In our tree, this is like noting the rightmost node at each level.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)