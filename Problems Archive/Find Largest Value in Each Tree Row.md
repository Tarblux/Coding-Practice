<<<<<<< Updated upstream
Problem: 515
Official Difficulty: medium
Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25
Completed On : 2024-12-24
Feels Like : easy
Topic: tree, Depth-First Search (DFS), Breadth-First Search(BFS), binary tree
My Understanding: Fully Understand
Last Review: 2024-12-24
Days Since Review: 5
Name: Find Largest Value in Each Tree Row

# Find Largest Value in Each Tree Row
### Problem
___
Given the `root` of a binary tree, return *an array of the largest value in each row* of the tree **(0-indexed)**.
**Example 1:**
![largest_e1.jpg](https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg)
```plain text
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
```
**Example 2:**
```plain text
Input: root = [1,2,3]
Output: [1,3]
```
**Constraints:**
- The number of nodes in the tree will be in the range `[0, 104]`.
- `231 <= Node.val <= 231 - 1`
### My Solutions
___
=======
# Find Largest Value in Each Tree Row

Problem: 515
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), Depth-First Search (DFS), binary tree, tree
Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25
Completed On : December 24, 2024
Last Review: December 24, 2024
Days Since Review: 68
Neetcode: No

## Problem

---

Given the `root` of a binary tree, return *an array of the largest value in each row* of the tree **(0-indexed)**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg)

```
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
```

**Example 2:**

```
Input: root = [1,2,3]
Output: [1,3]
```

**Constraints:**

- The number of nodes in the tree will be in the range `[0, 104]`.
- `231 <= Node.val <= 231 - 1`

## My Solutions

---

>>>>>>> Stashed changes
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        
        if not root:
            return []

        largest = float('-inf')
        queue = deque([root])
        output = []

        while queue:

            for i in range(len(queue)):

                cur = queue.popleft()

                if cur.left:
                    queue.append(cur.left)

                if cur.right:
                    queue.append(cur.right)

                largest = max(cur.val,largest)

            output.append(largest)
            largest = float('-inf')

        return output
```

<<<<<<< Updated upstream
Time Complexity :
=======
>>>>>>> Stashed changes
```python

```

<<<<<<< Updated upstream
Time Complexity : 
### Optimal Solutions
___
Here’s how to solve **LeetCode 515: Find Largest Value in Each Tree Row** using a **Breadth-First Search (BFS)** or **Depth-First Search (DFS)** approach:
___
#### **Approach 1: BFS (Level Order Traversal)**
#### Steps:
1. Perform a level-order traversal of the tree using a queue.
2. For each level, keep track of the largest value encountered.
3. Add the largest value of each level to the result list.
___
#### Code Implementation (BFS)
=======
## Optimal Solutions

---

Here’s how to solve **LeetCode 515: Find Largest Value in Each Tree Row** using a **Breadth-First Search (BFS)** or **Depth-First Search (DFS)** approach:

---

### **Approach 1: BFS (Level Order Traversal)**

### Steps:

1. Perform a level-order traversal of the tree using a queue.
2. For each level, keep track of the largest value encountered.
3. Add the largest value of each level to the result list.

---

### Code Implementation (BFS)

>>>>>>> Stashed changes
```python
from collections import deque

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        result = []
        queue = deque([root])

        while queue:
            level_max = float('-inf')
            for _ in range(len(queue)):
                node = queue.popleft()
                level_max = max(level_max, node.val)

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result.append(level_max)

        return result

```
<<<<<<< Updated upstream
___
#### **Approach 2: DFS**
#### Steps:
4. Traverse the tree recursively, keeping track of the current depth.
5. Use a list `result` where the index represents the depth.
6. At each depth, update the largest value seen so far.
___
#### Code Implementation (DFS)
=======

---

### **Approach 2: DFS**

### Steps:

1. Traverse the tree recursively, keeping track of the current depth.
2. Use a list `result` where the index represents the depth.
3. At each depth, update the largest value seen so far.

---

### Code Implementation (DFS)

>>>>>>> Stashed changes
```python
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(node, depth):
            if not node:
                return

            # If this depth hasn't been recorded, initialize it
            if depth == len(result):
                result.append(node.val)
            else:
                # Update the max value at this depth
                result[depth] = max(result[depth], node.val)

            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)

        result = []
        dfs(root, 0)
        return result

```
<<<<<<< Updated upstream
___
#### **Example**
**Input:**
```plain text
=======

---

### **Example**

**Input:**

```
>>>>>>> Stashed changes
      1
     / \
    3   2
   / \   \
  5   3   9

```
<<<<<<< Updated upstream
**Execution (BFS):**
7. Level 0: [1] → max = 1
8. Level 1: [3, 2] → max = 3
9. Level 2: [5, 3, 9] → max = 9
**Output:** `[1, 3, 9]`
___
#### **Complexity Analysis**
- **Time Complexity:** O(n)
	- Every node is visited once.
- **Space Complexity:** O(n)
	- BFS: The queue can hold up to the maximum number of nodes at any level.
	- DFS: The recursion stack can go as deep as the height of the tree.
Both BFS and DFS are efficient for this problem, and the choice depends on personal preference or familiarity.
### Notes
___
 
### Related Videos 
___
[]()
=======

**Execution (BFS):**

1. Level 0: [1] → max = 1
2. Level 1: [3, 2] → max = 3
3. Level 2: [5, 3, 9] → max = 9

**Output:** `[1, 3, 9]`

---

### **Complexity Analysis**

- **Time Complexity:** O(n)
    - Every node is visited once.
- **Space Complexity:** O(n)
    - BFS: The queue can hold up to the maximum number of nodes at any level.
    - DFS: The recursion stack can go as deep as the height of the tree.

Both BFS and DFS are efficient for this problem, and the choice depends on personal preference or familiarity.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)
>>>>>>> Stashed changes
