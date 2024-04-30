# Average of Levels in Binary Tree

Problem: 637
Official Difficulty: easy
Feels Like : easy
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), Math, binary tree
Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
Completed On : April 26, 2024
Last Review: April 26, 2024
Days Since Review: 4

## Problem

---

Given the rootof a binary tree, return*the average value of the nodes on each level in the form of an array*. Answers within 10 ^ 5 of the actual answer will be accepted.

**Example 1:**

![https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg](https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg](https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg)

```
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]

```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.
- `231 <= Node.val <= 231 - 1`

## My Solutions

---

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque , defaultdict

class Solution:
    
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:

        @staticmethod
        def average(list):
            return sum(list)/len(list)

        queue = deque([root])
        avgs = []

        while queue:

            cur_level = []

            for _ in range(len(queue)):

                cur_node = queue.popleft()
                cur_level.append(cur_node.val)

                if cur_node.right:
                    queue.append(cur_node.right)

                if cur_node.left:
                    queue.append(cur_node.left)

            avgs.append(average(cur_level))

        return avgs
```

```python

```

## Optimal Solutions

---

The "Average of Levels in Binary Tree" problem requires computing the average value of the nodes on each level of a binary tree. This is a common problem that tests your understanding of tree traversal techniques, especially breadth-first search (BFS), which is well-suited for level-wise traversal of a tree.

Here's a conceptual breakdown and step-by-step solution approach using Python:

### Problem Understanding:

You're given the root of a binary tree, and you need to calculate the average value of the nodes at each level. The result should be a list of averages corresponding to each level from top to bottom.

### Solution Approach:

1. **Breadth-First Search (BFS)**: This traversal technique uses a queue to explore nodes level by level. It’s particularly effective here because it naturally processes all nodes at the current level before moving on to the next.
2. **Queue for Node Processing**: Each entry in the queue contains a node and its associated level. By processing all nodes within the same level as a batch, you can easily calculate the average for that level.
3. **Calculate Averages**: For each level, compute the sum of node values and divide by the number of nodes to get the average.

### Python Code Implementation:

```python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from collections import deque
from typing import List

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []

        queue = deque([root])  # Initialize the queue with the root node
        averages = []  # This will store the average of each level

        while queue:
            level_length = len(queue)  # Number of nodes at the current level
            level_sum = 0  # Sum of values at the current level

            for _ in range(level_length):
                node = queue.popleft()  # Remove the node from the front of the queue
                level_sum += node.val  # Add the node's value to the level sum

                # Add child nodes to the queue for the next level
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            # Calculate the average for this level
            averages.append(level_sum / level_length)

        return averages

```

### Explanation:

- **TreeNode Class**: A simple binary tree node class that includes a value and pointers to the left and right children.
- **Queue**: A deque is used for the BFS. It holds all nodes at the current level and then replaces them with their children for the next level.
- **Level Processing**: For each level, calculate the total sum of the node values and then compute the average. This average is appended to the `averages` list.

### Time and Space Complexity:

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the binary tree. Each node is processed exactly once.
- **Space Complexity**: \(O(M)\), where \(M\) is the maximum number of nodes at any level in the binary tree. This occurs when the queue is at its largest, typically at the last level or a level close to the last.

This approach provides a clear and efficient solution to the problem, leveraging the BFS technique to ensure all nodes at each level are processed together, making it straightforward to calculate averages level by level.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)