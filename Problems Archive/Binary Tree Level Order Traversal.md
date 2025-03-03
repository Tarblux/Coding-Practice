# Binary Tree Level Order Traversal II

Problem: 107
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: Breadth-First Search(BFS), binary tree, tree
Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
Completed On : November 8, 2024
Last Review: November 8, 2024
Days Since Review: 114
Neetcode: No

## Problem

---

Given the `root` of a binary tree, return *the bottom-up level order traversal of its nodes' values*. (i.e., from left to right, level by level from leaf to root).

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `1000 <= Node.val <= 1000`

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
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:

        if not root:
            return []

        queue = deque([root])
        order = []

        while queue:

            cur_level = []

            for node in range(len(queue)):

                cur_node = queue.popleft()

                if cur_node.left:
                    queue.append(cur_node.left)

                if cur_node.right:
                    queue.append(cur_node.right)

                cur_level.append(cur_node.val)
            
            order.append(cur_level)

        return order[::-1]

        
```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 107: Binary Tree Level Order Traversal II**, the most efficient algorithms involve traversing the binary tree while collecting nodes level by level and then reversing the order of levels to get the bottom-up traversal. Below are the optimal methods along with their time and space complexities.

---

### **1. Breadth-First Search (BFS) with Level Tracking**

**Algorithm Steps:**

1. **Initialize a Queue:**
    - Use a queue to perform level-order traversal (BFS).
    - Start by adding the root node to the queue.
2. **Traverse the Tree Level by Level:**
    - While the queue is not empty:
        - Determine the number of nodes at the current level (`level_size`).
        - Initialize an empty list `level_nodes` to store nodes at the current level.
        - For each node in the current level:
            - Dequeue a node from the queue.
            - Add its value to `level_nodes`.
            - Enqueue its left and right children if they exist.
        - **Append** `level_nodes` to the result list.
3. **Reverse the Result List:**
    - After traversing all levels, reverse the result list to get the bottom-up level order.

**Code Example:**

```python
from collections import deque

def levelOrderBottom(root):
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        level_size = len(queue)
        level_nodes = []

        for _ in range(level_size):
            node = queue.popleft()
            level_nodes.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level_nodes)

    # Reverse the result to get bottom-up order
    return result[::-1]

```

**Time Complexity:** O(N)

- **Explanation:**
    - Each node is visited exactly once during the traversal.
    - Reversing the list takes O(N) time.
    - Overall time complexity is linear with respect to the number of nodes.

**Space Complexity:** O(N)

- **Explanation:**
    - The queue can hold up to N nodes in the worst case (e.g., a complete binary tree).
    - The result list stores all node values.

---

### **2. Depth-First Search (DFS) with Depth Tracking**

**Algorithm Steps:**

1. **Initialize Result List:**
    - Use a list `result` to store nodes at each level.
2. **Define Recursive DFS Function:**
    - The function `dfs(node, depth)` performs a preorder traversal while tracking the depth.
3. **Recursive Traversal:**
    - If the current node is `None`, return.
    - **If** `depth` equals the length of `result`:
        - **Insert** a new list at the beginning of `result` to represent a new level.
    - **Append** the node's value to the list at index `(depth + 1)`:
        - This ensures that the bottom level is at index 0.
    - Recursively call `dfs` on the left and right children, incrementing `depth` by 1.

**Code Example:**

```python
def levelOrderBottom(root):
    result = []

    def dfs(node, depth):
        if not node:
            return
        if depth == len(result):
            # Insert at the beginning to build from bottom up
            result.insert(0, [])
        # Add the node's value to the corresponding level
        result[-(depth + 1)].append(node.val)
        dfs(node.left, depth + 1)
        dfs(node.right, depth + 1)

    dfs(root, 0)
    return result

```

**Time Complexity:** O(N)

- **Explanation:**
    - Each node is visited exactly once during the traversal.

**Space Complexity:** O(N)

- **Explanation:**
    - The recursion stack can go up to the height of the tree (O(N) in the worst case).
    - The result list stores all node values.

---

### **3. BFS without Reversing the Result**

**Algorithm Steps:**

1. **Initialize a Queue and a Deque:**
    - Use a queue for BFS traversal.
    - Use a deque (double-ended queue) `result` to append levels to the left.
2. **Traverse the Tree Level by Level:**
    - Similar to the BFS approach, but instead of appending `level_nodes` to the end of the result list, append it to the left of the deque.

**Code Example:**

```python
from collections import deque

def levelOrderBottom(root):
    if not root:
        return []

    result = deque()
    queue = deque([root])

    while queue:
        level_size = len(queue)
        level_nodes = []
        for _ in range(level_size):
            node = queue.popleft()
            level_nodes.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        # Append to the left to avoid reversing at the end
        result.appendleft(level_nodes)

    return list(result)

```

**Time Complexity:** O(N)

- **Explanation:**
    - Similar to the BFS approach, but avoids the reversing step.

**Space Complexity:** O(N)

- **Explanation:**
    - Uses a deque for the result, but overall space usage remains O(N).

---

### **Comparison and Recommendation**

- **BFS Approach:**
    - **Pros:**
        - Simple to implement.
        - Efficient for level order traversal.
    - **Cons:**
        - Requires reversing the result at the end (unless using a deque).
- **DFS Approach:**
    - **Pros:**
        - No need to reverse the result.
        - May be more intuitive for some recursive solutions.
    - **Cons:**
        - Requires careful index management.

**Recommendation:**

- The **BFS approach** is generally preferred for level order traversal problems due to its simplicity and direct mapping to levels.
- Using a **deque** to append levels to the left (Method 3) can optimize the BFS approach by avoiding the need to reverse the result list.

---

### **Summary**

- **Time Complexity for All Methods:** O(N)
- **Space Complexity for All Methods:** O(N)

All methods efficiently traverse the binary tree and collect the nodes in bottom-up level order. The choice between BFS and DFS depends on personal preference and specific use cases. BFS is typically more straightforward for level-based traversals.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)