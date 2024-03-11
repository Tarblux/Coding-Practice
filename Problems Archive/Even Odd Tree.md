# Even Odd Tree

Problem: 1609
Official Difficulty: medium
Feels Like : easy
My Understanding: Fully Understand
Topic: tree
Link: https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29
Completed On : March 6, 2024
Last Review: February 28, 2024
Days Since Review: 11

## Problem

---

A binary tree is named **Even-Odd** if it meets the following conditions:

- The root of the binary tree is at level index `0`, its children are at level index `1`, their children are at level index `2`, etc.
- For every **even-indexed** level, all nodes at the level have **odd** integer values in **strictly increasing** order (from left to right).
- For every **odd-indexed** level, all nodes at the level have **even** integer values in **strictly decreasing** order (from left to right).

Given the `root` of a binary tree, *return* `true` *if the binary tree is **Even-Odd**, otherwise return* `false`*.*

**Example 1:**

![https://assets.leetcode.com/uploads/2020/09/15/sample_1_1966.png](https://assets.leetcode.com/uploads/2020/09/15/sample_1_1966.png)

```
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/09/15/sample_2_1966.png](https://assets.leetcode.com/uploads/2020/09/15/sample_2_1966.png)

```
Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
Level 0: [5]
Level 1: [4,2]
Level 2: [3,3,7]
Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.
```

**Example 3:**

![https://assets.leetcode.com/uploads/2020/09/22/sample_1_333_1966.png](https://assets.leetcode.com/uploads/2020/09/22/sample_1_333_1966.png)

```
Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values in the level 1 should be even integers.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 105]`.
- `1 <= Node.val <= 106`

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

    def traversalBfs(self,node,dictionary,level):

        if not node: 
            
            return

        if level not in dictionary:

            dictionary[level] = []  

        dictionary[level].append(node.val) 

        self.traversalBfs(node.left,dictionary,level+1)
        self.traversalBfs(node.right,dictionary,level+1)

        return dictionary

    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        
        node_dict = {}
        tree_dict = self.traversalBfs(root,node_dict,0)

        for index , node_list in enumerate(tree_dict.values()): 

            if index % 2 == 0: 
                
                for i in range(1,len(node_list)):

                    if node_list[i] <= node_list[i-1]: 

                        return False 
                
                for i in range(len(node_list)):
                    
                    if node_list[i] % 2 == 0: 

                        return False 

            else:

                for i in range(1,len(node_list)):

                    if node_list[i] >= node_list[i-1]: 

                        return False 

                for i in range(len(node_list)):
                    
                    if node_list[i] % 2 != 0: 

                        return False 

        return True
```

```python

```

## Optimal Solutions

---

The "Even Odd Tree" problem is a binary tree problem where you're asked to check if a binary tree is an "even-odd tree". A binary tree is considered an even-odd tree if it meets the following conditions:

1. **Level 0 is all odd integers**, **Level 1 is all even integers**, and this pattern alternates for all levels.
2. At each level, integers increase from left to right.
3. For even-numbered levels (like 0, 2, 4, ...), each node's value is odd and strictly increasing from left to right.
4. For odd-numbered levels (like 1, 3, 5, ...), each node's value is even and strictly increasing from left to right.

### Approach

To solve this problem, you can perform a level-order traversal of the tree using a queue. While traversing each level, check the values of the nodes to ensure they adhere to the rules outlined above.

### Python Implementation

```python
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        if not root:
            return True

        queue = deque([root])
        level = 0

        while queue:
            level_size = len(queue)
            prev_value = float('-inf') if level % 2 == 0 else float('inf')

            for _ in range(level_size):
                node = queue.popleft()

                # Check if the value violates the even-odd rules
                if (level % 2 == 0 and (node.val % 2 == 0 or node.val <= prev_value)) or \\
                   (level % 2 == 1 and (node.val % 2 == 1 or node.val >= prev_value)):
                    return False

                prev_value = node.val

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            level += 1

        return True
```

### Explanation

- **Queue for Level-order Traversal**: A deque is used to store nodes of each level for traversal. This allows easy addition and removal of nodes while maintaining order.
- **Level Tracking**: A variable `level` keeps track of the current level in the tree. This helps to alternate between even and odd rules.
- **Previous Value Comparison**: The `prev_value` variable is used to compare the current node's value with the previous node's value in the same level. Its initial value is set based on the level's parity (odd or even).
- **Rule Checking**: For each node, the code checks if its value violates the even-odd tree rules based on the current level. If any rule is violated, the function immediately returns `False`.
- **Node Children Processing**: If the current node has children, they are added to the queue for processing in the next level.
- **Result**: If the traversal completes without finding any violations, the tree satisfies the even-odd tree conditions, and `True` is returned.

### Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the tree. Each node is visited exactly once during the level-order traversal.
- **Space Complexity**: \(O(N)\) in the worst case for the queue, where \(N\) is the number of nodes in the tree. This worst-case space complexity occurs when the tree is extremely unbalanced, and almost all nodes are on one level.

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)