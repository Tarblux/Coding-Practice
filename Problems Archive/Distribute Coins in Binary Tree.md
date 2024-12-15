Problem: 979
Official Difficulty: medium
Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
Completed On : 2024-12-10
Feels Like : medium
Topic: tree, Depth-First Search (DFS), binary tree
My Understanding: Needs Review
Last Review: 2024-12-10
Days Since Review: 5
Name: Distribute Coins in Binary Tree

# Distribute Coins in Binary Tree
### Problem
___
You are given the `root` of a binary tree with `n` nodes where each `node` in the tree has `node.val` coins. There are `n` coins in total throughout the whole tree.
In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.
Return *the ****minimum**** number of moves required to make every node have ****exactly**** one coin*.
**Example 1:**
![tree1.png](https://assets.leetcode.com/uploads/2019/01/18/tree1.png)
```plain text
Input: root = [3,0,0]
Output: 2
Explanation:From the root of the tree, we move one coin to its left child, and one coin to its right child.

```
**Example 2:**
![tree2.png](https://assets.leetcode.com/uploads/2019/01/18/tree2.png)
```plain text
Input: root = [0,3,0]
Output: 3
Explanation:From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.

```
**Constraints:**
- The number of nodes in the tree is `n`.
- `1 <= n <= 100`
- `0 <= Node.val <= n`
- The sum of all `Node.val` is `n`.
### My Solutions
___
```python

```

Time Complexity :
```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def distributeCoins(self, root: TreeNode) -> int:
        moves = [0] 
        
        def dfs(node, moves):
            if not node:
                return 0

            left_excess = dfs(node.left, moves)
            right_excess = dfs(node.right, moves)
            
            # Total excess at current node
            total_excess = node.val - 1 + left_excess + right_excess
            
            # Moves needed to balance this node's excess
            moves[0] += abs(left_excess) + abs(right_excess)
            
            return total_excess
        
        dfs(root, moves)
        return moves[0]





        
```

Time Complexity : 
### Optimal Solutions
___

### Notes
___
 
### Related Videos 
___
[]()